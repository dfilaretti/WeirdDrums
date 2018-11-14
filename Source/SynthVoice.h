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

class SynthVoice : public SynthesiserVoice
{
public:

	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
		processorChain.prepare(spec);
	}

	//==============================================================================

	void getEnvelopeParams(float* attack, float* decay)
	{
		envAttack  = *attack;
		envDecay   = *decay;
	}

	void getOscParams(float* selection)
	{
		oscWaveform = *selection;
	}

	void getFilterParams(float* type, float* cutoff, float* res)
	{
		filterType   = *type;
		filterCutoff = *cutoff;
		filterRes    = *res;
	}
	
	//==============================================================================

	void updateEnvelopeParams() 
	{
		processorChain.get<envelopeIndex>().setAttack(envAttack);
		processorChain.get<envelopeIndex>().setDecay(envDecay);
		processorChain.get<envelopeIndex>().setSustain(0.0f);
		processorChain.get<envelopeIndex>().setRelease(0.0f);
	}

	void updateOscillatorParams()
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

		processorChain.get<osc1Index>().setFrequency(oscFrequency, true);
		processorChain.get<osc1Index>().setLevel(oscLevel);
	}

	void updateFilterParams()
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

	//==============================================================================
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
		int currentPitchWheelPosition) override
	{
		processorChain.get<envelopeIndex>().setTrigger (1);
		oscLevel = velocity;
		oscFrequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	void stopNote(float velocity, bool allowTailOff) override
	{
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
		updateOscillatorParams();
		updateFilterParams();
		updateEnvelopeParams();
		
		auto block = tempBlock.getSubBlock(0, (size_t)numSamples);
		block.clear();
		juce::dsp::ProcessContextReplacing<float> context(block);
		processorChain.process(context);

		juce::dsp::AudioBlock<float>(outputBuffer)
			.getSubBlock((size_t)startSample, (size_t)numSamples)
			.add(tempBlock);
	}

private:
	//==============================================================================
	typedef Oscillator<float> Oscillator;
	
	typedef Envelope<float> Envelope;
	
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
	juce::dsp::ProcessorChain<Oscillator, Filter, Envelope> processorChain;

	//==============================================================================
	float envAttack, envDecay;
	
	double oscLevel, oscFrequency;
	int oscWaveform;
	
	int filterType;
	float filterCutoff, filterRes;
};