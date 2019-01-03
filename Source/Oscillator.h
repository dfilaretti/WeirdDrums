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
	void setFrequency (Type newValue, bool force = false)
	{
		auto& osc = processorChain.template get<oscIndex>();
		osc.setFrequency(newValue, force);
	}

	//==============================================================================
	void setLevel (Type newValue)
	{
		auto& gain = processorChain.template get<gainIndex>();
		gain.setGainLinear(newValue);
	}

	void setWaveform(int selection)
	{
		auto& osc = processorChain.template get<oscIndex>();
		
		Random random;

		switch (selection) 
		{
			case sine: 
				osc.initialise([](Type x) { return std::sin(x); }, 512);
				break;
			case saw: 
				osc.initialise([](Type x) {
					return jmap(x, Type(-MathConstants<double>::pi), Type(MathConstants<double>::pi), Type(-1), Type(1));
				}, 2);
				break;
			case square:
				osc.initialise([](Type x) { return ( sgn (std::sin (x))) ; }, 512);
				break;
			case noise:
				osc.initialise([&random](Type x) { return (random.nextFloat() * 0.25f - 0.125f);}, 128);
				break;
			default:
				osc.initialise([](Type x) { return std::sin(x); }, 128);
		}
	}

	//==============================================================================
	void reset() noexcept
	{
		processorChain.reset();
	}

	//==============================================================================
	template <typename ProcessContext>
	void process (const ProcessContext& context) noexcept
	{
		processorChain.process(context);
	}

	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		processorChain.prepare(spec);
	}

	enum Waveform
	{
		sine, 
		saw,
		square, // todo 
		noise
	};
private:
	//==============================================================================
	
	template <typename T> 
	static int sgn(T val)
	{
		return ( T(0) < val ) - ( val < T(0) );
	}

	enum
	{
		oscIndex,
		gainIndex
	};
	
	juce::dsp::ProcessorChain<juce::dsp::Oscillator<Type>, juce::dsp::Gain<Type>> processorChain;
};