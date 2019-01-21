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

	//==============================================================================
	OscillatorSectionEditor oscGui;
	MasterSectionEditor envGui;
	NoiseSectionEditor filterGui;

private:
	//==============================================================================
	const int kWidth         = 750;
	const int kHeight        = 285;
	const int kSectionWidth  = 250; // each section's width is 1/3 of total
	const int kSectionHeight = kHeight;

	//==============================================================================
    LittleTeknoDrummerAudioProcessor& processor;


	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LittleTeknoDrummerAudioProcessorEditor)
};
