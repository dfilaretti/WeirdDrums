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
#include "LtdRotarySlider.h"
#include "LtdComplexComponent.h"
#include <variant>

//==============================================================================

class NoiseSectionEditor	: public LtdComplexComponent
{
public:
	NoiseSectionLookAndFeel lookAndFeel;

    NoiseSectionEditor(LittleTeknoDrummerAudioProcessor&, int, int, std::string);
    ~NoiseSectionEditor();

private:
	//LtdRotarySlider filterTypeSlider{ juce::String("FLT TYPE") };
	LtdRotarySlider filterCutoffSlider{ juce::String("Cutoff")  };
	LtdRotarySlider filterResonanceSlider{ juce::String("Res") };
	LtdRotarySlider attackSlider{ juce::String("Attack") };
	LtdRotarySlider decaySlider{ juce::String("Decay") };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
