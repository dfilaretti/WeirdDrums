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
		tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
		processorChain.prepare(spec);

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
		processorChain.get<envelopeIndex>().setAttack(envAttack);
		processorChain.get<envelopeIndex>().setDecay(envDecay);

		// Although we are using a full ADSR envelope, we use it as an AD  (Attack/Decay) , 
		// therefore we set Sustain and Release to 0. 
		// TODO: actually make a ADEnvelope class. 
		processorChain.get<envelopeIndex>().setSustain(0.0f);
		processorChain.get<envelopeIndex>().setRelease(0.0f);
	}

	void setOscWaveform()
	{
		switch (oscWaveform)
		{
		case 0:
			processorChain.get<osc1Index>().setWaveform(Oscillator::sine);
			break;
		case 1:
			processorChain.get<osc1Index>().setWaveform (Oscillator::saw);
			break;
		case 2:
			processorChain.get<osc1Index>().setWaveform(Oscillator::square);
			break;
		}
	}

	void setOscFreq(float freq, float vel)
	{
		processorChain.get<osc1Index>().setFrequency(freq, true);
		processorChain.get<osc1Index>().setLevel(vel);
	}

	void setOscFilter()
	{
		auto sr = getSampleRate();
		auto& stateVariableFilter = processorChain.get<filterIndex>();

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
		processorChain.get<envelopeIndex>().setTrigger (1);
		
		oscLevel = velocity;
		currentNoteFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	void stopNote(float velocity, bool allowTailOff) override
	{
		pitchEnv.trigger = 0;
		processorChain.get<envelopeIndex>().setTrigger (0);

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

		// set things up
		auto output = tempBlock.getSubBlock(0, (size_t)numSamples);
		output.clear();
		juce::dsp::ProcessContextReplacing<float> context(output);
		// set processors with params
		setOscWaveform();
		setOscFilter();
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
		processorChain.process(context);
		// write down output
		juce::dsp::AudioBlock<float>(outputBuffer)
			.getSubBlock((size_t)startSample, (size_t)numSamples)
			.add(tempBlock);
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
	juce::HeapBlock<char> heapBlock;
	juce::dsp::AudioBlock<float> tempBlock;
	
	//==============================================================================
	// TODO: are we sure the amp envelope should be here?
	//       shouldn't it be a control rate envelope?
	juce::dsp::ProcessorChain<Oscillator, Filter, Envelope> processorChain;

	maxiEnv pitchEnv;
	juce::dsp::Oscillator<float> pitchLfo;

	//==============================================================================
	float envAttack, envDecay;
	
	double oscLevel, oscFrequency, currentNoteFrequency;
	int oscWaveform;
	
	int filterType;
	float filterCutoff, filterRes;

	float pitchEnvAmount, pitchEnvRate;
	float pitchLfoAmount, pitchLfoRate;

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