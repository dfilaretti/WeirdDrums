/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "TitleSectionEditor.h"
#include "BottomSectionEditor.h"
#include "Grid2d.h"

//==============================================================================

class WdAudioProcessorEditor  : public AudioProcessorEditor
{
public:
	//==============================================================================
    WdAudioProcessorEditor (WdAudioProcessor&);
    ~WdAudioProcessorEditor();

	//==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	//==============================================================================
	WdLookAndFeel lookAndFeel;
private:
	//==============================================================================
	BottomSectionEditor bottomSectionGui;
	TitleSectionEditor titleSectionGui;

	//==============================================================================
	Grid2d oscSectionGui;
	Grid2d masterSectionGui;
	Grid2d noiseSectionGui;

	//==============================================================================
	const int kWidth         = 500;
	const int kHeight        = 600;
	const int kTitleHeight   = 40;

	//==============================================================================
    WdAudioProcessor& processor;
	
	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WdAudioProcessorEditor)
};