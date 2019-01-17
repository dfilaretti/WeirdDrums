/*
  ==============================================================================

    WhiteNoiseGenerator.h
    Created: 12 Jan 2019 10:16:00am
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

//template <typename Type>
class WhiteNoiseGenerator
{
public:
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
	}

	void reset() noexcept
	{
	}

	// Use an actusal gain processor instead
	void setLevel(float newLevel)
	{
		level = newLevel;
	}

	template <typename ProcessContext>
	void process(const ProcessContext& context) noexcept
	{
		// initial setup (see juce_Gain.h)
		auto&& inBlock  = context.getInputBlock();
		auto&& outBlock = context.getOutputBlock();

		// in and out blocks must have same "shape"
		jassert(inBlock.getNumChannels() == outBlock.getNumChannels());
		jassert(inBlock.getNumSamples()  == outBlock.getNumSamples());

		auto len         = inBlock.getNumSamples();
		auto numChannels = inBlock.getNumChannels();

		if (context.isBypassed)
		{
			// TODO
		}

		for (int channel = 0; channel < numChannels; channel++)
		{
			auto* src = inBlock.getChannelPointer(channel);
			auto* dst = outBlock.getChannelPointer(channel);

			for (int i = 0; i < len; i++)
			{
				dst[i] = (randomNumberGenerator.nextFloat() - 0.5f) * level;
			}
		}
	}

private:
	Random randomNumberGenerator;
	float level; // [0,1]
};