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
	//==============================================================================
	const String kMenuItemLowPassText  = "LP";
	const String kMenuItemHighPassText = "HP";
	const String kMenuItemBandPassText = "BP";

	//==============================================================================
	const int kMenuItemLowPassId   = 1;
	const int kMenuItemHighPassId  = 2;
	const int kMenuItemSBandPassId = 3;

	//==============================================================================
	ComboBox filterTypeComboBox;

	//==============================================================================
	LtdRotarySlider filterCutoffSlider{ juce::String("Freq")  };
	LtdRotarySlider filterResonanceSlider{ juce::String("Reso") };
	LtdRotarySlider attackSlider{ juce::String("Att") };
	LtdRotarySlider decaySlider{ juce::String("Dec") };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
