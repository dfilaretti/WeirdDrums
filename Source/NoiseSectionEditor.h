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
	LtdRotarySlider filterTypeSlider{ juce::String("FLT TYPE") };
	LtdRotarySlider filterCutoffSlider{ juce::String("FREQ")  };
	LtdRotarySlider filterResonanceSlider{ juce::String("RESO") };
	LtdRotarySlider attackSlider{ juce::String("ATT") };
	LtdRotarySlider decaySlider{ juce::String("DEC") };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
