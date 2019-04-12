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
    //==============================================================================
	/** Initialises the synth */
	void prepare (const juce::dsp::ProcessSpec& spec) noexcept
	{
		setCurrentPlaybackSampleRate (spec.sampleRate);

		for (auto* v : voices)
			dynamic_cast<SynthVoice*> (v)->prepare (spec);
	}

	/** Soft-kills all currently playing voices.

        This is done by calling SynthVoice::killNote()
    */
	void softKillActiveVoices (const int midiChannel)
	{
		for (auto* voice : voices)
			if (midiChannel <= 0 || voice->isPlayingChannel (midiChannel))
				dynamic_cast<SynthVoice*> (voice)->killNote();	
	}

    //==============================================================================
	/** Soft-kills all voices, then starts a new one.

		This achieves monophony, without nasty clicks when stealing voices.
    */
	void noteOn(const int midiChannel,
		        const int midiNoteNumber,
		        const float velocity) override
	{
		const ScopedLock sl (lock);

		softKillActiveVoices (midiChannel);

		Synthesiser::noteOn (midiChannel, midiNoteNumber, velocity);
	}
	
private:
};