/*
  ==============================================================================

    SynthVoice.h
    Created: 28 Oct 2018 5:13:04pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "Oscillator.h"
#include "Envelope.h"
#include "WhiteNoiseGenerator.h"
#include "Distortion.h"

class SynthVoice : public SynthesiserVoice
{
public:
	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		// init buffers
		oscSectionBlock    = juce::dsp::AudioBlock<float> (oscSectionHeapBlock, spec.numChannels, spec.maximumBlockSize);
		noiseSectionBlock  = juce::dsp::AudioBlock<float> (noiseSectionHeapBlock, spec.numChannels, spec.maximumBlockSize);
		masterSectionBlock = juce::dsp::AudioBlock<float> (masterSectionHeapBlock, spec.numChannels, spec.maximumBlockSize);

		// Setup amp envelope smoothing
		auto modSampleRate   = (spec.sampleRate / m_modulationUpdateRate);
		auto modSamplePeriod = 1 / modSampleRate;
		oscSectionProcessorChain.get<oscSectionOscIndex>().setRampDuration (static_cast<float>(modSamplePeriod));

		// prepare processing chains
		oscSectionProcessorChain.prepare (spec);
		noiseSectionProcessorChain.prepare (spec);
		masterSectionProcessorChain.prepare (spec);

		//init envelopes
		m_oscAmpEnv.setSampleRate (spec.sampleRate / m_modulationUpdateRate);
		m_noiseAmpEnv.setSampleRate (spec.sampleRate / m_modulationUpdateRate);
		m_oscPitchEnv.setSampleRate (spec.sampleRate / m_modulationUpdateRate);
		
		// init LFO
		pitchLfo.initialise([](float x) { return std::sin(x); }, 128);
		pitchLfo.prepare({ spec.sampleRate / m_modulationUpdateRate, spec.maximumBlockSize, spec.numChannels });
	}

	//==============================================================================
	void setParamPointers ( float* oscAttack 
		                  , float* oscDecay 
		                  , float* oscFreq 
		                  , float* oscSelection 
		                  , float* oscPitchEnvAmount 
		                  , float* oscPitchEnvRate 
		                  , float* oscPitchLfoAmount 
		                  , float* oscPitchLfoRate
		                  , float* noiseFilterType 
		                  , float* noiseFilterCutoff 
		                  , float* noiseFilterRes 
		                  , float* noiseAttack 
		                  , float* noiseDecay
		                  , float* masterMix 
		                  , float* masterEqFreq 
		                  , float* masterEqGain 
		                  , float* masterDistortionAmount 
		                  , float* masterLevel 
		                  , float* masterPan ) 
	{
		envAttack            = oscAttack;
		envDecay             = oscDecay;
		currentNoteFrequency = oscFreq;
		oscWaveform          = oscSelection;
		pitchEnvAmount       = oscPitchEnvAmount;
		pitchEnvRate         = oscPitchEnvRate;
		pitchLfoAmount       = oscPitchLfoAmount;
		pitchLfoRate         = oscPitchLfoRate;
		filterType           = noiseFilterType;
		filterCutoff         = noiseFilterCutoff;
		filterRes            = noiseFilterRes;
		noiseEnvAttack       = noiseAttack;
		noiseEnvDecay        = noiseDecay;
		mix                  = masterMix;
		eqFreq               = masterEqFreq;
		eqGain               = masterEqGain;
		distortionAmount     = masterDistortionAmount;
	    level                = masterLevel;
	    pan                  = masterPan;
	}
	
	//==============================================================================
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*> (sound) != nullptr;
	}

	void startNote(int /*midiNoteNumber*/, 
		           float velocity, 
		           SynthesiserSound* /*sound*/,
		           int /*currentPitchWheelPosition*/) override
	{
		setPerNoteParams();
		
		m_oscAmpEnv.noteOn();
		m_noiseAmpEnv.noteOn();
		m_oscPitchEnv.noteOn();

		m_currentNoteVelocity = velocity;
	}
	
	void stopNote(float /*velocity*/, bool allowTailOf) override
	{
		if (allowTailOf) {} // Nothing to do - one-shot drum envelope here
		else             clearCurrentNote();
	}

	void pitchWheelMoved (int /*newPitchWheelValue*/) override
	{
	}

	void controllerMoved (int /*controllerNumber*/, int /*newControllerValue*/) override
	{
	}

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
	{
		auto oscSectionOutput    = oscSectionBlock.getSubBlock (0, (size_t)numSamples);
		auto noiseSectionOutput  = noiseSectionBlock.getSubBlock (0, (size_t)numSamples);
		auto masterSectionOutput = masterSectionBlock.getSubBlock (0, (size_t)numSamples);
		
		oscSectionOutput.clear();
		noiseSectionOutput.clear();
		masterSectionOutput.clear();

		for (size_t pos = 0; pos < numSamples;)
		{
			// If both osc and noise envelopes completed their cycle, clear the note
			if (isVoiceActive() && !m_oscAmpEnv.isActive() && !m_noiseAmpEnv.isActive())
			{
				clearCurrentNote();
				break;
			}

			auto max = jmin (static_cast<size_t> (numSamples - pos), m_modulationUpdateCounter);

			auto oscBlock    = oscSectionOutput.getSubBlock (pos, max);
			auto noiseBlock  = noiseSectionOutput.getSubBlock (pos, max);
			auto masterBlock = masterSectionOutput.getSubBlock (pos, max);

			juce::dsp::ProcessContextReplacing<float> oscSectionContext (oscBlock);
			juce::dsp::ProcessContextReplacing<float> noiseSectionContext (noiseBlock);
			juce::dsp::ProcessContextReplacing<float> masterSectionContext (masterBlock);
			
			pos += max;
			m_modulationUpdateCounter -= max;
		
			if (m_modulationUpdateCounter == 0)
			{
				setControlRateParams();
				m_modulationUpdateCounter = m_modulationUpdateRate;
			}
			
			// process osc section
			oscSectionProcessorChain.process (oscSectionContext);
			// process noise section
			noiseSectionProcessorChain.process (noiseSectionContext);
			// master = osc + noise
			masterBlock.add (oscBlock).add (noiseBlock);
			// process master section
			masterSectionProcessorChain.process (masterSectionContext);
		}

		// All processing done!
		juce::dsp::AudioBlock<float> (outputBuffer)
			.getSubBlock ((size_t)startSample, (size_t)numSamples)
			.add (masterSectionBlock);
	}

	//==============================================================================
	void killNote()
	{
		m_oscAmpEnv.noteOff();
		m_noiseAmpEnv.noteOff();
		m_oscPitchEnv.noteOff();
	}

private:
	//==============================================================================
	void setControlRateParams()
	{
		// OSC section 
		// =============================

		// amp envelope
		auto currentAmpEnv = m_oscAmpEnv.getNextSample();
		auto oscLevel = currentAmpEnv * m_currentNoteVelocity;
		oscSectionProcessorChain.get<oscSectionOscIndex>().setLevel (oscLevel);

		// pitch LFO
		// https://dsp.stackexchange.com/questions/2349/help-with-algorithm-for-modulating-oscillator-pitch-using-lfo
		auto pitchLfoOut = pitchLfo.processSample (0.0f);
		oscFrequency = *currentNoteFrequency * pow (2.f, (1.f / 1200.0f + pitchLfoOut * *pitchLfoAmount));

		// pitch env
		float fMin = oscFrequency;
		float fMax = jlimit(0.0f, 20000.0f, fMin + (1000 * *pitchEnvAmount));
		float pitchEnvOut = m_oscPitchEnv.getNextSample();
		oscFrequency = jmap (pitchEnvOut, 0.0f, 1.0f, fMin, fMax); 

		// set pitch with combined frequency
		oscSectionProcessorChain.get<oscSectionOscIndex>().setFrequency (oscFrequency, true);

		// NOISE section 
		// =============================

		auto currentNoiseEnv = m_noiseAmpEnv.getNextSample();
		auto noiseLevel = currentNoiseEnv * m_currentNoteVelocity;
		noiseSectionProcessorChain.get<noiseSectionOscIndex>().setLevel(noiseLevel);
	}

	//==============================================================================
	void setPerNoteParams()
	{
		oscSectionProcessorChain.get<oscSectionOscIndex>().reset (); // reset phase to avoid clicks
		oscSectionProcessorChain.get<oscSectionOscIndex>().setWaveform (static_cast<int>(*oscWaveform));

		// Global FX chain
		masterSectionProcessorChain
			.get<masterSectionDistortionIndex>()
			.setPreGain(*distortionAmount);

		masterSectionProcessorChain
			.get<masterSectionGainIndex>()
			.setGainDecibels(*level);

		// envelopes
		m_oscAmpEnv.setParameters({ *envAttack, *envDecay });
		m_noiseAmpEnv.setParameters({ *noiseEnvAttack, *noiseEnvDecay });

		// modulation
		m_oscPitchEnv.setParameters({ 0.001f, *pitchEnvRate });
		pitchLfo.setFrequency(*pitchLfoRate, true);

		// set filter params
		{
			auto sr = getSampleRate();
			auto& filter = noiseSectionProcessorChain.get<noiseSectionFilterIndex>();

			switch (static_cast<int> (*filterType))
			{
			case 0:
				filter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
				break;
			case 1:
				filter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
				break;
			case 2:
				filter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
				break;
			default:
				filter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
			}

			filter.state->setCutOffFrequency(sr, *filterCutoff, *filterRes);
		}

		// mix
		oscSectionProcessorChain.get<oscSectionGainIndex>().setGainLinear (1 - *mix);
		noiseSectionProcessorChain.get<noiseSectionGainIndex>().setGainLinear (*mix);
	}

	//==============================================================================
	static constexpr size_t m_modulationUpdateRate = 10;
	size_t m_modulationUpdateCounter = m_modulationUpdateRate;

	//==============================================================================
	juce::dsp::Oscillator<float> pitchLfo;
	Envelope m_oscAmpEnv;
	Envelope m_oscPitchEnv;
	Envelope m_noiseAmpEnv;

	//==============================================================================
	typedef Oscillator<float> Oscillator;
	typedef Distortion<float> Distortion;
	typedef juce::dsp::Gain<float> Gain;
	typedef dsp::ProcessorDuplicator<dsp::StateVariableFilter::Filter<float>, 
		                             dsp::StateVariableFilter::Parameters<float>> Filter;

	//==============================================================================
	enum OscSection
	{
		oscSectionOscIndex,
		oscSectionGainIndex
	};

	enum NoiseSection
	{
		noiseSectionOscIndex,
		noiseSectionFilterIndex,
		noiseSectionGainIndex,
	};

	enum MasterSection
	{
		masterSectionDistortionIndex,
		masterSectionGainIndex
	};

	//==============================================================================
	juce::HeapBlock<char> oscSectionHeapBlock;
	juce::dsp::AudioBlock<float> oscSectionBlock;

	juce::HeapBlock<char> noiseSectionHeapBlock;
	juce::dsp::AudioBlock<float> noiseSectionBlock;

	juce::HeapBlock<char> masterSectionHeapBlock;
	juce::dsp::AudioBlock<float> masterSectionBlock;
	
	//==============================================================================
	juce::dsp::ProcessorChain<Oscillator, Gain> oscSectionProcessorChain;
	juce::dsp::ProcessorChain<WhiteNoiseGenerator, Filter, Gain> noiseSectionProcessorChain;
	juce::dsp::ProcessorChain<Distortion, Gain> masterSectionProcessorChain;

	//==============================================================================
	float m_currentNoteVelocity;
	float  oscFrequency; // actual frequency taking LFO and pitch env into account
 	
	//==============================================================================
	// OSC 
	float* oscWaveform;
	float* currentNoteFrequency;
	float* envAttack;
	float* envDecay;
	float* pitchEnvAmount;
	float* pitchEnvRate;
	float* pitchLfoAmount;
	float* pitchLfoRate;

	// NOISE 
	float* filterType;
	float* filterCutoff;
	float* filterRes;
	float* noiseEnvAttack; 
	float* noiseEnvDecay;

	// MASTER 
	float* mix; 
	float* eqFreq;            // todo
	float* eqGain;            // todo
	float* distortionAmount;
	float* level; 
	float* pan;               // todo
};