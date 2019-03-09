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
    NoiseSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~NoiseSectionEditor();

private:
	LtdRotarySlider filterTypeSlider{ juce::String("Flt Type") };
	LtdRotarySlider filterCutoffSlider{ juce::String("Freq")  };
	LtdRotarySlider filterResonanceSlider{ juce::String("Reso") };
	LtdRotarySlider attackSlider{ juce::String("Att") };
	LtdRotarySlider decaySlider{ juce::String("Dec") };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
