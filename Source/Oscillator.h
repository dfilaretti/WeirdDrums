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

	/** Sets ramp duration in second */
	void setRampDuration(float durationSecs)
	{
		auto& gain = processorChain.template get<gainIndex>();
		gain.setRampDurationSeconds(durationSecs);
	}

	void setWaveform(int selection)
	{
		auto oscFunction = [selection, this] () -> std::function<float(float)>
		{
			switch (selection)
			{
				case sine:
					return [](Type x) { return std::sin(x); };
				case saw:
					return [](Type x) { return jmap(x, Type(-MathConstants<double>::pi), Type(MathConstants<double>::pi), Type(-1), Type(1)); };
				case square:
				default:
					return [](Type x) 
					{ 
						auto v = std::sin(x);
						return static_cast<float>((0 < v) - (v < 0));
					};

			}
		}();

		auto& osc = processorChain.template get<oscIndex>();
		osc.initialise (oscFunction, 512);
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

	enum Waveform
	{
		sine,
		saw,
		square,
	};
private:
	//==============================================================================
	enum
	{
		oscIndex,
		gainIndex
	};

	//==============================================================================
	juce::dsp::ProcessorChain<juce::dsp::Oscillator<Type>, juce::dsp::Gain<Type>> processorChain;
};