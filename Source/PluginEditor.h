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

class LittleTeknoDrummerAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    LittleTeknoDrummerAudioProcessorEditor (LittleTeknoDrummerAudioProcessor&);
    ~LittleTeknoDrummerAudioProcessorEditor();

	//==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	LittleTeknoDrummerLookAndFeel lookAndFeel;

	//==============================================================================
	OscillatorSectionEditor oscGui;
	MasterSectionEditor envGui;
	NoiseSectionEditor filterGui;

	//==============================================================================
	const float kWidth         = 500;
	const float kHeight        = 500;

	const int   kTitleHeight   = 40;

	//==============================================================================
    LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LittleTeknoDrummerAudioProcessorEditor)
};