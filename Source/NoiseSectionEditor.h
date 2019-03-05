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
	NoiseSectionLookAndFeel lookAndFeel;

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
	LtdRotarySlider filterCutoffSlider{ juce::String("Freq"), &lookAndFeel };
	LtdRotarySlider filterResonanceSlider{ juce::String("Reso"), &lookAndFeel };
	LtdRotarySlider attackSlider{ juce::String("Att"), &lookAndFeel };
	LtdRotarySlider decaySlider{ juce::String("Dec"), &lookAndFeel };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
