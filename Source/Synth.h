/*
  ==============================================================================

    Synth.h
    Created: 9 Nov 2018 4:39:13pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthVoice.h"

class Synth : public Synthesiser
{
public:
	void prepare(const juce::dsp::ProcessSpec& spec) noexcept
	{
		setCurrentPlaybackSampleRate (spec.sampleRate);

		for (auto* v : voices)
			dynamic_cast<SynthVoice*> (v)->prepare (spec);

		//fxChain.prepare(spec);
	}
private:
	// ...
};