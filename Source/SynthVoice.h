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

class SynthVoice : public SynthesiserVoice
{
public:
	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		
		m_oscAmpEnv.setSampleRate(spec.sampleRate / m_modulationUpdateRate); // TODO: change this value to something "real"!
		m_noiseAmpEnv.setSampleRate(spec.sampleRate / m_modulationUpdateRate); // TODO: change this value to something "real"!
		
		auto f = 1.0f;
		m_oscAmpEnv.setParameters({ 0.001f * f, 0.5f * f, 0.1f * f, 0.2f * f });
		m_noiseAmpEnv.setParameters({ 0.001f * f, 0.5f * f, 0.1f * f, 0.2f * f});


		// init buffers
		oscSectionBlock    = juce::dsp::AudioBlock<float>(oscSectionHeapBlock,    spec.numChannels, spec.maximumBlockSize);
		noiseSectionBlock  = juce::dsp::AudioBlock<float>(noiseSectionHeapBlock,  spec.numChannels, spec.maximumBlockSize);
		masterSectionBlock = juce::dsp::AudioBlock<float>(masterSectionHeapBlock, spec.numChannels, spec.maximumBlockSize);
		
		// prepare processing chains
		oscSectionProcessorChain.prepare(spec);
		noiseSectionProcessorChain.prepare(spec);
		masterSectionProcessorChain.prepare(spec);

		// init modulation
		pitchLfo.initialise([](float x) { return std::sin(x); }, 128);
		auto pitchLfoFactor = 0.01; // TODO: remove eventually!!!
		pitchLfo.prepare({ spec.sampleRate * pitchLfoFactor, spec.maximumBlockSize, spec.numChannels });



	}

	//==============================================================================
	
	// OSC SECTION
	void getEnvelopeParams (float* attack, float* decay)
	{
		envAttack  = *attack;
		envDecay   = *decay;
	}

	void getOscParams (float* selection)
	{
		oscWaveform = *selection;
	}

	void getPitchEnvParams (float* amount, float* rate)
	{
		pitchEnvAmount = *amount;
		pitchEnvRate   = *rate;
	}

	void getPitchLfoParams(float* amount, float* rate)
	{
		pitchLfoAmount = *amount;
		pitchLfoRate   = *rate;
	}

	// NOISE SECTION

	void getNoiseFilterParams (float* type, float* cutoff, float* res)
	{
		filterType   = *type;
		filterCutoff = *cutoff;
		filterRes    = *res;
	}

	void getNoiseEnvelopeParams (float* attack, float* decay)
	{
		noiseEnvAttack = *attack;
		noiseEnvDecay = *decay;
	}

	// MASTER SECTION

	void getMasterMixParams(float* mix)
	{
		this->mix = *mix;
	}

	void getMasterEqParams(float* freq, float* gain)
	{
		eqFreq = *freq;
		eqGain = *gain;
	}

	void getMasterDistortionParams(float* amount)
	{
		distortionAmount = *amount;
	}

	void getMasterLevelAndPanParams(float* level, float* pan)
	{
		this->level = *level;
		this->pan = *pan;
	}
	
	//==============================================================================
	void setOscAmpEnv() 
	{

		//oscSectionProcessorChain.get<oscSectionEnvelopeIndex>().setAttack(envAttack);
		//oscSectionProcessorChain.get<oscSectionEnvelopeIndex>().setDecay(envDecay);
		// Although we are using a full ADSR envelope, we use it as an AD  (Attack/Decay) , 
		// therefore we set Sustain and Release to 0. 
		// TODO: actually make a ADEnvelope class. 
		//oscSectionProcessorChain.get<oscSectionEnvelopeIndex>().setSustain(0.0f);
		//oscSectionProcessorChain.get<oscSectionEnvelopeIndex>().setRelease(0.0f);
	}

	void setNoiseOscWaveform()
	{
		// init noise oscillator
		noiseSectionProcessorChain.get<noiseSectionOscIndex>().setWaveform(Oscillator::noise);
		/*noiseSectionProcessorChain.get<noiseSectionOscIndex>().setLevel(1);*/
	}

	void setNoiseAmpEnv()
	{


		//noiseSectionProcessorChain.get<noiseSectionEnvelopeIndex>().setAttack(noiseEnvAttack);
		//noiseSectionProcessorChain.get<noiseSectionEnvelopeIndex>().setDecay(noiseEnvDecay);
		// Although we are using a full ADSR envelope, we use it as an AD  (Attack/Decay) , 
		// therefore we set Sustain and Release to 0. 
		// TODO: actually make a ADEnvelope class. 
		//noiseSectionProcessorChain.get<noiseSectionEnvelopeIndex>().setSustain(0.0f);
		//noiseSectionProcessorChain.get<noiseSectionEnvelopeIndex>().setRelease(0.0f);
	}

	void setOscWaveform()
	{
		// TODO: this should be white noise
		// TODO: move away from here
		//noiseSectionProcessorChain.get<noiseSectionOscIndex>().setWaveform(Oscillator::noise);
		//noiseSectionProcessorChain.get<noiseSectionOscIndex>().setLevel(1);
	
		switch (oscWaveform)
		{
		case 0:
			oscSectionProcessorChain.get<oscSectionOscIndex>().setWaveform(Oscillator::sine);
			break;
		case 1:
			oscSectionProcessorChain.get<oscSectionOscIndex>().setWaveform (Oscillator::saw);
			break;
		case 2:
			oscSectionProcessorChain.get<oscSectionOscIndex>().setWaveform(Oscillator::square);
			break;
		}
	}

	void setOscFreq(float freq, float vel)
	{
		oscSectionProcessorChain.get<oscSectionOscIndex>().setFrequency(freq, true);
		oscSectionProcessorChain.get<oscSectionOscIndex>().setLevel(vel);
	}

	void setNoiseFilter()
	{
		auto sr = getSampleRate();
		auto& stateVariableFilter = noiseSectionProcessorChain.get<noiseSectionFilterIndex>();

		switch (filterType)
		{
		case 0:
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
			break;
		case 1:
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::highPass;
			break;
		case 2:
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
			break;
		default:
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
		}

		stateVariableFilter.state->setCutOffFrequency(sr, filterCutoff, filterRes);
	}

	void setOscPitchEnv()
	{
		auto pitchEnvFactor = 0.01; // TODO: remove this one after sample rate fixed
		auto pitchEnvDecay = pitchEnvRate * pitchEnvFactor;

		//pitchEnv.setDecay(pitchEnvDecay);
		//pitchEnv.setAttack(0.0f);
		//pitchEnv.setSustain(0.0f);
		//pitchEnv.setRelease(0.0f);
	}

	void setOscPitchLfo()
	{
		//pitchLfo.setFrequency(pitchLfoRate, true);
	}

	//==============================================================================
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
		int currentPitchWheelPosition) override
	{
		m_oscAmpEnv.noteOn();
		m_noiseAmpEnv.noteOn();

		m_currentNoteVelocity = velocity;
		currentNoteFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	void stopNote(float velocity, bool allowTailOff) override
	{
		m_oscAmpEnv.noteOff();
		m_noiseAmpEnv.noteOff();

		allowTailOff = true; // ?

		if (velocity = 0)
			clearCurrentNote(); // so that voice can be reused
	}

	void pitchWheelMoved (int newPitchWheelValue) override
	{

	}

	void controllerMoved (int controllerNumber, int newControllerValue) override
	{

	}

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
	{

		auto oscSectionOutput    = oscSectionBlock.getSubBlock(0, (size_t)numSamples);
		auto noiseSectionOutput  = noiseSectionBlock.getSubBlock(0, (size_t)numSamples);
		auto masterSectionOutput = masterSectionBlock.getSubBlock(0, (size_t)numSamples);
		
		oscSectionOutput.clear();
		noiseSectionOutput.clear();
		masterSectionOutput.clear();

		// MASTER section 
		// =============================
		// =============================
		// =============================

		for (size_t pos = 0; pos < numSamples;)
		{
			auto max = jmin(static_cast<size_t> (numSamples - pos), m_modulationUpdateCounter);

			auto oscBlock    = oscSectionOutput.getSubBlock(pos, max);
			auto noiseBlock  = noiseSectionOutput.getSubBlock (pos, max);
			auto masterBlock = masterSectionOutput.getSubBlock(pos, max);

			juce::dsp::ProcessContextReplacing<float> oscSectionContext (oscBlock);
			juce::dsp::ProcessContextReplacing<float> noiseSectionContext (noiseBlock);
			juce::dsp::ProcessContextReplacing<float> masterSectionContext (masterBlock);
			
			pos += max;
			m_modulationUpdateCounter -= max;
		
			if (m_modulationUpdateCounter == 0)
			{
				// OSC section 
				// =============================

				setOscWaveform();
				auto currentAmpEnv = m_oscAmpEnv.getNextSample();
				auto oscLevel      = currentAmpEnv * m_currentNoteVelocity;
				oscFrequency       = currentNoteFrequency;
				setOscFreq (oscFrequency, oscLevel);

				// NOISE section 
				// =============================

				setNoiseOscWaveform();
				setNoiseFilter();
				auto currentNoiseEnv = m_noiseAmpEnv.getNextSample();
				auto noiseLevel = currentNoiseEnv * m_currentNoteVelocity;
				noiseSectionProcessorChain.get<noiseSectionOscIndex>().setLevel(noiseLevel);


				// ---
				m_modulationUpdateCounter = m_modulationUpdateRate;
			}
			
			oscSectionProcessorChain.process (oscSectionContext);
			noiseSectionProcessorChain.process (noiseSectionContext);
			masterSectionProcessorChain.process (masterSectionContext);

			// scale OSC and NOISE according to the MIX param
			
			oscBlock.multiply (1 - mix);
			noiseBlock.multiply (mix);

			// sum OSC and NOISE sections
			masterBlock
				.add(oscBlock)
				.add(noiseBlock);

			// apply MASTER level
			// TODO: make it in DB?
			masterBlock.multiply (level);
		
		}


		juce::dsp::AudioBlock<float> (outputBuffer)
			.getSubBlock ((size_t)startSample, (size_t)numSamples)
			.add (masterSectionBlock);
	}

private:
	//==============================================================================
	static constexpr size_t m_modulationUpdateRate = 10;
	size_t m_modulationUpdateCounter = m_modulationUpdateRate;

	//==============================================================================
	ADSR m_oscAmpEnv;
	ADSR m_oscPitchEnv;
	ADSR m_noiseAmpEnv;

	//==============================================================================
	typedef Oscillator<float> Oscillator;
	
	typedef 
		dsp::ProcessorDuplicator<dsp::StateVariableFilter::Filter<float>, 
		                         dsp::StateVariableFilter::Parameters<float>> Filter;

	enum OscSection
	{
		oscSectionOscIndex,
		//oscSectionEnvelopeIndex
	};

	enum NoiseSection
	{
		noiseSectionOscIndex,
		noiseSectionFilterIndex,
		//noiseSectionEnvelopeIndex
	};

	//==============================================================================
	juce::HeapBlock<char> oscSectionHeapBlock;
	juce::dsp::AudioBlock<float> oscSectionBlock;

	juce::HeapBlock<char> noiseSectionHeapBlock;
	juce::dsp::AudioBlock<float> noiseSectionBlock;

	juce::HeapBlock<char> masterSectionHeapBlock;
	juce::dsp::AudioBlock<float> masterSectionBlock;
	
	//==============================================================================
	// TODO: are we sure the amp envelope should be here?
	//       shouldn't it be a control rate envelope?
	juce::dsp::ProcessorChain<Oscillator> oscSectionProcessorChain;
	juce::dsp::ProcessorChain<Oscillator, Filter> noiseSectionProcessorChain; // TODO
	juce::dsp::ProcessorChain<Filter> masterSectionProcessorChain; // TODO

	//==============================================================================
	//maxiEnv pitchEnv;
	juce::dsp::Oscillator<float> pitchLfo;
	
	//==============================================================================
	
	double m_currentNoteVelocity;

	// OSC 

	double oscFrequency, currentNoteFrequency;
	int oscWaveform;
	float pitchEnvAmount, pitchEnvRate;
	float pitchLfoAmount, pitchLfoRate;

	// NOISE 
	
	int filterType;
	float filterCutoff, filterRes;
	float noiseEnvAttack, noiseEnvDecay;

	// MASTER 

	float mix, eqFreq, eqGain, distortionAmount, level, pan;

	//==============================================================================
	float envAttack, envDecay;

	//==============================================================================
	void applyPitchLfo()
	{
		auto pitchLfoOut = pitchLfo.processSample(0.0f);
		oscFrequency = oscFrequency + (pitchLfoOut * pitchLfoAmount);
	}

	void applyPitchEnv()
	{
		/*auto pitchEnvDepth = pitchEnvAmount;

		float pitchEnvOut = pitchEnv.adsr(1.0f, pitchEnv.trigger);	
		oscFrequency = oscFrequency + (pitchEnvOut * pitchEnvDepth);*/
	}
};