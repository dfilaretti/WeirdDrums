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
#include "Osc.h"
#include "Maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		// TODO
		//tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
		//processorChain.prepare(spec);
		
		stateVariableFilter.reset();
		stateVariableFilter.prepare (spec);
	}


	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	//==============================================================================

	void getParam(float* attack, float* decay, float* sustain, float* release)
	{
		env1.setAttack(double(*attack));
		env1.setDecay(double(*decay));
		env1.setSustain(double(*sustain));
		env1.setRelease(double(*release));
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

	double setOscType ()
	{
		// TODO: use switch
		if (waveform == 0)
		{
			return osc1.sinewave(frequency);
		}
		if (waveform == 1)
		{
			return osc1.saw(frequency);
		}
		if (waveform == 2)
		{
			return osc1.square(frequency);
		}
		else
		{
			return osc1.sinewave(frequency);
		}
	}

	double setEnvelope()
	{
		return env1.adsr(setOscType(), env1.trigger) * level;
	}

	//==============================================================================

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
		int currentPitchWheelPosition) override
	{
		env1.trigger = 1; // start env
		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	}
	
	//==============================================================================

	void stopNote(float velocity, bool allowTailOff)
	{
		env1.trigger = 0;   // release env
		allowTailOff = true;

		if (velocity = 0)
			clearCurrentNote(); // clear voice so it can be used (e.g. press other key)
	}

	//==============================================================================

	void pitchWheelMoved (int newPitchWheelValue)
	{

	}

	//==============================================================================

	void controllerMoved (int controllerNumber, int newControllerValue)
	{

	}

	//==============================================================================

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
	{
		for (int sample = 0; sample < numSamples; sample++)
		{
			for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
			{
				outputBuffer.addSample(channel, startSample, setEnvelope());
			}

			++startSample;
		}

		// do filter stuff
		updateFilter();
		dsp::AudioBlock<float> block (outputBuffer);
		stateVariableFilter.process(dsp::ProcessContextReplacing<float> (block));

		//dsp::AudioBlock<float> block (outputBuffer);
		//processorChain.process(dsp::ProcessContextReplacing<float> (block));
	}

	//==============================================================================

private:

	//enum
	//{
	//	osc1Index,
	//	//osc2Index,
	//	//filterIndex,
	//	//masterGainIndex
	//};

	double level;
	double frequency;
	int waveform;
	int filterType;
	float filterCutoff, filterRes;

	maxiOsc osc1;
	maxiEnv env1;
	
	//juce::dsp::ProcessorChain<Oscillator<float>> processorChain;

	dsp::ProcessorDuplicator<juce::dsp::StateVariableFilter::Filter<float>, dsp::StateVariableFilter::Parameters<float>>
		stateVariableFilter;
};