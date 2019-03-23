/*
  ==============================================================================

    Distortion.h
    Created: 9 Jan 2019 8:31:22pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template <typename Type>
class Distortion
{
public:
	//==============================================================================
	Distortion()
	{
		auto& waveshaper = processorChain.template get<waveshaperIndex>();

		waveshaper.functionToUse = [](Type x)
		{
			return std::tanh(x);
		};

		// POST gain is no-op
		auto& postGain = processorChain.template get<postGainIndex>();
		postGain.setGainDecibels(0.0f);
	}

	//==============================================================================
	void setPreGain(float newPreGain)
	{
		auto& preGain = processorChain.template get<preGainIndex>();
		preGain.setGainDecibels (newPreGain);
	}

	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		processorChain.prepare(spec);
	}

	//==============================================================================
	template <typename ProcessContext>
	void process(const ProcessContext& context) noexcept
	{
		processorChain.process(context);
	}

	//==============================================================================
	void reset() noexcept
	{
		processorChain.reset();
	}

private:
	//==============================================================================
	enum
	{
		preGainIndex,
		waveshaperIndex,
		postGainIndex
	};

	juce::dsp::ProcessorChain<juce::dsp::Gain<Type>, 
		                      juce::dsp::WaveShaper<Type>, 
		                      juce::dsp::Gain<Type>> processorChain;
};