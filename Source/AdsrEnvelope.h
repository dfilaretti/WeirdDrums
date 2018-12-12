/*
  ==============================================================================

    Envelope.h
    Created: 11 Nov 2018 10:25:18am
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Maximilian.h"

template <typename Type>
class AdsrEnvelope
{
public:
	//==============================================================================

	void prepare(const juce::dsp::ProcessSpec& spec)
	{
	}

	void reset() noexcept
	{
	}

	template <typename ProcessContext>
	void process(const ProcessContext& context) noexcept
	{
		// initial setup (see juce_Gain.h)
		auto&& inBlock = context.getInputBlock();
		auto&& outBlock = context.getOutputBlock();

		jassert(inBlock.getNumChannels() == outBlock.getNumChannels());
		jassert(inBlock.getNumSamples() == outBlock.getNumSamples());

		auto len = inBlock.getNumSamples();
		auto numChannels = inBlock.getNumChannels();

		if (context.isBypassed)
		{
			// TODO
		}
		
		for (int channel = 0; channel < numChannels; channel++)
		{
			auto* src = inBlock.getChannelPointer (channel);
			auto* dst = outBlock.getChannelPointer (channel);
			
			for (int i = 0; i < len; i++)
			{
				dst[i] = env.adsr(src[i], env.trigger);
			}
		}
	}

	//==============================================================================
	
	void setAttack (float attack)
	{
		env.setAttack(attack);
	}

	void setDecay (float decay)
	{
		env.setDecay(decay);
	}

	void setSustain (float sustain)
	{
		env.setSustain(sustain);
	}

	void setRelease (float release)
	{
		env.setRelease(release);
	}

	void setTrigger (bool trigger)
	{
		env.trigger = trigger;
	}

private:
	maxiEnv env;
};