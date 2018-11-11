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
//#include "Maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
		processorChain.prepare(spec);
	}


	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*> (sound) != nullptr;
	}

	//==============================================================================

	void getParam(float* attack, float* decay, float* sustain, float* release)
	{
		processorChain.get<envelopeIndex>().setAttack(double(*attack));
		processorChain.get<envelopeIndex>().setDecay(double(*decay));
		processorChain.get<envelopeIndex>().setSustain(double(*sustain));
		processorChain.get<envelopeIndex>().setRelease(double(*release));
	}

	void getOscType(float* selection)
	{
		waveform = *selection;
	}

	void getFilterParams(float* type, float* cutoff, float* res)
	{
		filterType = *type;
		filterCutoff = *cutoff;
		filterRes = *res;
	}
	
	//==============================================================================

	void updateFilter()
	{
		auto sr = getSampleRate();
		auto& stateVariableFilter = processorChain.get<filterIndex>();

		if (filterType == 0)
		{
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
			stateVariableFilter.state->setCutOffFrequency(sr, filterCutoff, filterRes);
		}

		if (filterType == 1)
		{
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::highPass;
			stateVariableFilter.state->setCutOffFrequency(sr, filterCutoff, filterRes);
		}

		if (filterType == 3)
		{
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
			stateVariableFilter.state->setCutOffFrequency(sr, filterCutoff, filterRes);
		}
		else
		{
			stateVariableFilter.state->type =
				dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
			stateVariableFilter.state->setCutOffFrequency(sr, filterCutoff, filterRes);
		}
	}

	void updateOsc()
	{
		switch (waveform)
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

		processorChain.get<osc1Index>().setFrequency(frequency, true);
		processorChain.get<osc1Index>().setLevel(level);
	}

	//==============================================================================

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
		int currentPitchWheelPosition) override
	{
		processorChain.get<envelopeIndex>().setTrigger (1);
		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	//==============================================================================

	void stopNote(float velocity, bool allowTailOff) override
	{
		processorChain.get<envelopeIndex>().setTrigger (0);

		allowTailOff = true;

		if (velocity = 0)
			clearCurrentNote(); // clear voice so it can be used (e.g. press other key)
	}

	//==============================================================================

	void pitchWheelMoved (int newPitchWheelValue) override
	{

	}

	//==============================================================================

	void controllerMoved (int controllerNumber, int newControllerValue) override
	{

	}

	//==============================================================================

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
	{
		updateOsc();
		updateFilter();
		
		auto block = tempBlock.getSubBlock(0, (size_t)numSamples);
		block.clear();
		juce::dsp::ProcessContextReplacing<float> context(block);
		processorChain.process(context);

		juce::dsp::AudioBlock<float>(outputBuffer)
			.getSubBlock((size_t)startSample, (size_t)numSamples)
			.add(tempBlock);
	}

	//==============================================================================

private:

	//==============================================================================
	typedef Oscillator<float> Oscillator;

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
	juce::HeapBlock<char> heapBlock;        // ?
	juce::dsp::AudioBlock<float> tempBlock; // ?
	
	juce::dsp::ProcessorChain<Oscillator, Filter, Envelope<float>> processorChain;

	double level, frequency;
	int waveform;
	int filterType;
	float filterCutoff, filterRes;
};