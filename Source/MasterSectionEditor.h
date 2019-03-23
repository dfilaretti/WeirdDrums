/*
  ==============================================================================

    MasterSectionEditor.h
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"
#include "Grid2d.h"
#include "LabelledRotarySlider.h"

//==============================================================================

class MasterSectionEditor    : public Grid2d
{
public:
	//==============================================================================
    MasterSectionEditor(WdAudioProcessor&, 
		                int, 
		                int, 
		                std::string, 
		                Colour);

    ~MasterSectionEditor();

private:
	//==============================================================================
	LabelledRotarySlider mixSlider{ juce::String("Mix") };
	LabelledRotarySlider eqFreqSlider{ juce::String("Eq Freq") };
	LabelledRotarySlider distortSlider{ juce::String("Distort") };
	LabelledRotarySlider eqGainSlider{ juce::String("Eq Gain") };
	LabelledRotarySlider levelSlider{ juce::String("Level") };
	LabelledRotarySlider panSlider{ juce::String("Pan") };
	LabelledRotarySlider filterTypeSlider{ juce::String("Filter Type") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
