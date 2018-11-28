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
#include "AdsrEnvelope.h"

class SynthVoice : public SynthesiserVoice
{
public:
	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		// init buffers
		oscSectionBlock    = juce::dsp::AudioBlock<float>(oscSectionHeapBlock,    spec.numChannels, spec.maximumBlockSize);
		noiseSectionBlock  = juce::dsp::AudioBlock<float>(noiseSectionHeapBlock,  spec.numChannels, spec.maximumBlockSize);
		masterSectionBlock = juce::dsp::AudioBlock<float>(masterSectionHeapBlock, spec.numChannels, spec.maximumBlockSize);
		
		// prepare processing chains
		oscSectionProcessorChain.prepare(spec);
		noiseSectionProcessorChain.prepare(spec);
		masterSectionProcessorChain.prepare(spec);

		//// TODO: remove
		//noiseSectionProcessorChain.get<0>().setFrequency(110, true);
		//noiseSectionProcessorChain.get<0>().setLevel(0.2);

		// init modulation
		pitchLfo.initialise([](float x) { return std::sin(x); }, 128);
		auto pitchLfoFactor = 0.01; // TODO: remove eventually!!!
		pitchLfo.prepare({ spec.sampleRate * pitchLfoFactor, spec.maximumBlockSize, spec.numChannels });
	}

	//==============================================================================
	void getEnvelopeParams (float* attack, float* decay)
	{
		envAttack  = *attack;
		envDecay   = *decay;
	}

	void getNoiseEnvelopeParams (float* attack, float* decay)
	{
		noiseEnvAttack = *attack;
		noiseEnvDecay = *decay;
	}

	

	void getOscParams (float* selection)
	{
		oscWaveform = *selection;
	}

	void getFilterParams (float* type, float* cutoff, float* res)
	{
		filterType   = *type;
		filterCutoff = *cutoff;
		filterRes    = *res;
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
	
	//==============================================================================
	void setOscAmpEnv() 
	{
		oscSectionProcessorChain.get<envelopeIndex>().setAttack(envAttack);
		oscSectionProcessorChain.get<envelopeIndex>().setDecay(envDecay);

		// Although we are using a full ADSR envelope, we use it as an AD  (Attack/Decay) , 
		// therefore we set Sustain and Release to 0. 
		// TODO: actually make a ADEnvelope class. 
		oscSectionProcessorChain.get<envelopeIndex>().setSustain(0.0f);
		oscSectionProcessorChain.get<envelopeIndex>().setRelease(0.0f);
	}

	void setOscWaveform()
	{
		switch (oscWaveform)
		{
		case 0:
			oscSectionProcessorChain.get<osc1Index>().setWaveform(Oscillator::sine);
			break;
		case 1:
			oscSectionProcessorChain.get<osc1Index>().setWaveform (Oscillator::saw);
			break;
		case 2:
			oscSectionProcessorChain.get<osc1Index>().setWaveform(Oscillator::square);
			break;
		}
	}

	void setOscFreq(float freq, float vel)
	{
		oscSectionProcessorChain.get<osc1Index>().setFrequency(freq, true);
		oscSectionProcessorChain.get<osc1Index>().setLevel(vel);
	}

	void setOscFilter()
	{
		auto sr = getSampleRate();
		auto& stateVariableFilter = oscSectionProcessorChain.get<filterIndex>();

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

		pitchEnv.setDecay(pitchEnvDecay);
		pitchEnv.setAttack(0.0f);
		pitchEnv.setSustain(0.0f);
		pitchEnv.setRelease(0.0f);
	}

	void setOscPitchLfo()
	{
		pitchLfo.setFrequency(pitchLfoRate, true);
	}

	//==============================================================================
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
		int currentPitchWheelPosition) override
	{
		pitchEnv.trigger = 1;
		oscSectionProcessorChain.get<envelopeIndex>().setTrigger (1);
		
		oscLevel = velocity;
		currentNoteFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	void stopNote(float velocity, bool allowTailOff) override
	{
		pitchEnv.trigger = 0;
		oscSectionProcessorChain.get<envelopeIndex>().setTrigger (0);

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
		// NOTE: how often should we calculate modulations? Now this is done once per block. 
		//       Before this commit, it was done more often. What's best? Should probably test 
		//       in a DAW and observe performance, sound quality etc. Sticking to this now, as it's simpler. 

		// OSC section 
		// =============================
		// =============================
		// =============================

		// set things up
		auto oscSectionOutput = oscSectionBlock.getSubBlock(0, (size_t)numSamples);
		oscSectionOutput.clear();
		juce::dsp::ProcessContextReplacing<float> oscSectionContext (oscSectionOutput);
		// set processors with params
		setOscWaveform();
		setOscAmpEnv();
		setOscPitchEnv();
		setOscPitchLfo();
		// calculate osc frequency (w/ modulation)
		oscFrequency = currentNoteFrequency;
		applyPitchLfo();
		applyPitchEnv();
		oscFrequency = jlimit<float>(0.0f, 20000.0, oscFrequency);
		// set osc freqency
		setOscFreq(oscFrequency, oscLevel);
		// process this block! 
		oscSectionProcessorChain.process (oscSectionContext);
		
		// NOISE section 
		// =============================
		// =============================
		// =============================
		
		// set things up
		auto noiseSectionOutput = noiseSectionBlock.getSubBlock(0, (size_t)numSamples);
		noiseSectionOutput.clear();
		juce::dsp::ProcessContextReplacing<float> noiseSectionContext(noiseSectionOutput);

		setOscFilter();
		// set env
		// set stuff
		noiseSectionProcessorChain.process(noiseSectionContext);

		// MASTER section 
		// =============================
		// =============================
		// =============================

		// set things up
		auto masterSectionOutput = masterSectionBlock.getSubBlock(0, (size_t)numSamples);
		masterSectionOutput.clear();
		juce::dsp::ProcessContextReplacing<float> masterSectionContext(masterSectionOutput);

		// sum OSC and NOISE sections
		masterSectionOutput
			.add(oscSectionBlock)
			.add(noiseSectionBlock);

		// TODO: global level, EQ, distortion etc. 
		masterSectionProcessorChain.process (masterSectionContext);

		// write down output
		//juce::dsp::AudioBlock<float>(outputBuffer)
		//	.getSubBlock((size_t)startSample, (size_t)numSamples)
		//	.add(oscSectionBlock)
		//	.add(noiseSectionBlock);
		juce::dsp::AudioBlock<float>(outputBuffer)
			.getSubBlock((size_t)startSample, (size_t)numSamples)
			.add(masterSectionBlock);
	}

private:
	//==============================================================================
	typedef Oscillator<float> Oscillator;
	
	typedef AdsrEnvelope<float> Envelope;
	
	typedef 
		dsp::ProcessorDuplicator<dsp::StateVariableFilter::Filter<float>, 
		                         dsp::StateVariableFilter::Parameters<float>> Filter;

	enum
	{
		osc1Index,
		filterIndex,
		envelopeIndex
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
	juce::dsp::ProcessorChain<Oscillator, Filter, Envelope> oscSectionProcessorChain;
	juce::dsp::ProcessorChain<Oscillator> noiseSectionProcessorChain; // TODO
	juce::dsp::ProcessorChain<Filter> masterSectionProcessorChain; // TODO

	//==============================================================================
	maxiEnv pitchEnv;
	juce::dsp::Oscillator<float> pitchLfo;
	
	//==============================================================================
	float noiseEnvAttack, noiseEnvDecay;
	
	double oscLevel, oscFrequency, currentNoteFrequency;
	int oscWaveform;
	
	int filterType;
	float filterCutoff, filterRes;

	float pitchEnvAmount, pitchEnvRate;
	float pitchLfoAmount, pitchLfoRate;

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
		auto pitchEnvDepth = pitchEnvAmount;

		float pitchEnvOut = pitchEnv.adsr(1.0f, pitchEnv.trigger);	
		oscFrequency = oscFrequency + (pitchEnvOut * pitchEnvDepth);
	}
};