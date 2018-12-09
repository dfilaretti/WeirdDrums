/*
  ==============================================================================

    MySound.h
    Created: 8 Dec 2018 9:48:21am
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class MySound : public SynthesiserSound
{
public:
	bool appliesToNote(int /*midiNoteNumber*/)
	{
		return true;
	}

	bool appliesToChannel(int /*midiChannel*/)
	{
		return true;
	}
};