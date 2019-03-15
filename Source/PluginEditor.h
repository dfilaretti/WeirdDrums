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
	//==============================================================================
    LittleTeknoDrummerAudioProcessorEditor (LittleTeknoDrummerAudioProcessor&);
    ~LittleTeknoDrummerAudioProcessorEditor();

	//==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	//==============================================================================
	LittleTeknoDrummerLookAndFeel lookAndFeel;
private:
	//==============================================================================
	// TODO: factorize Oscillator/Noise/Master/SectionEditor into a single class
	OscillatorSectionEditor oscSectionGui;
	MasterSectionEditor masterSectionGui;
	NoiseSectionEditor noiseSectionGui;

	//==============================================================================
	TextButton resetButton;
	TextButton randomButton; 
	Label versionLabel;

	//==============================================================================
	void initResetButton();
	void initRandomButton();

	//==============================================================================
	const float kWidth         = 500;
	const float kHeight        = 600;
	const int   kTitleHeight   = 40;

	//==============================================================================
    LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
	Random randomNumberGenerator;
	
	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LittleTeknoDrummerAudioProcessorEditor)
};