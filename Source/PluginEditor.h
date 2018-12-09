/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "OscillatorSectionEditor.h"
#include "NoiseSectionEditor.h"
#include "MasterSectionEditor.h"

//==============================================================================

class PatSynthAudioProcessorEditor  : 
	public AudioProcessorEditor
{
public:
    PatSynthAudioProcessorEditor (PatSynthAudioProcessor&);
    ~PatSynthAudioProcessorEditor();

	//==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	MidiKeyboardState keyboardState;
	MidiKeyboardComponent keyboardComponent;

	//==============================================================================
	const int kWidth         = 750;
	const int kHeight        = 275;
	const int kSectionWidth  = 250;
	const int kSectionHeight = kHeight;

    PatSynthAudioProcessor& processor;

	OscillatorSectionEditor oscGui;
	MasterSectionEditor envGui;
	NoiseSectionEditor filterGui;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatSynthAudioProcessorEditor)
};
