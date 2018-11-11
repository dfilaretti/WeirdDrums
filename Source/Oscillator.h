/*
  ==============================================================================

    Osc.h
    Created: 9 Nov 2018 5:31:56pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template <typename Type>
class Oscillator
{
public:
	//==============================================================================
	Oscillator()
	{
		auto& osc = processorChain.template get<oscIndex>();
		osc.initialise([](Type x) { return std::sin(x); }, 128);
	}

	//==============================================================================
	void setFrequency(Type newValue, bool force = false)
	{
		auto& osc = processorChain.template get<oscIndex>();
		osc.setFrequency(newValue, force);
	}

	//==============================================================================
	void setLevel(Type newValue)
	{
		auto& gain = processorChain.template get<gainIndex>();
		gain.setGainLinear(newValue);
	}

	//==============================================================================
	void reset() noexcept
	{
		processorChain.reset();
	}

	//==============================================================================
	template <typename ProcessContext>
	void process(const ProcessContext& context) noexcept
	{
		processorChain.process(context);
	}

	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		processorChain.prepare(spec);
	}

private:
	//==============================================================================
	enum
	{
		oscIndex,
		gainIndex
	};

	juce::dsp::ProcessorChain<juce::dsp::Oscillator<Type>, juce::dsp::Gain<Type>> processorChain;
};