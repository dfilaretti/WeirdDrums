/*
  ==============================================================================

    MyVoice.h
    Created: 8 Dec 2018 9:48:04am
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "MySound.h"
#include "DspFaust.h"

class MyVoice : public SynthesiserVoice 
{
public:

	MyVoice()
	{
		dspFaust.start();
	}

	~MyVoice()
	{
		dspFaust.stop();
	}


	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<MySound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
	{
		dspFaust.setParamValue("/PatSynth/gate", 1);
	}

	void stopNote(float velocity, bool allowTailOff) override
	{
		dspFaust.setParamValue("/PatSynth/gate", 0);
	}

	void pitchWheelMoved(int newPitchWheelValue) override
	{
	}

	void controllerMoved(int controllerNumber, int newControllerValue) override
	{
	}

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
	{
	}

private:
	DspFaust dspFaust;
};