/*
  ==============================================================================

    NoiseSectionEditor.h
    Created: 6 Nov 2018 4:44:43pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"
#include "LabelledRotarySlider.h"
#include "Grid2d.h"
#include <variant>

//==============================================================================

class NoiseSectionEditor	: public Grid2d
{
public:
	//==============================================================================
    NoiseSectionEditor(WdAudioProcessor&, 
		               int,  
		               int, 
		               std::string);

    ~NoiseSectionEditor();

private:
	//==============================================================================
	LabelledRotarySlider filterCutoffSlider{ juce::String("Cutoff")  };
	LabelledRotarySlider filterResonanceSlider{ juce::String("Res") };
	LabelledRotarySlider attackSlider{ juce::String("Attack") };
	LabelledRotarySlider decaySlider{ juce::String("Decay") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
