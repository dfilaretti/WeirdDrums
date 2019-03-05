/*
  ==============================================================================

    OscillatorSectionEditor.h
    Created: 6 Nov 2018 2:36:24pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"
#include "LtdComplexComponent.h"
#include "LtdRotarySlider.h"

//==============================================================================
/*
*/
class OscillatorSectionEditor    : public LtdComplexComponent
{
public:
    OscillatorSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~OscillatorSectionEditor();

private:
	//==============================================================================
	OscSectionLookAndFeel lookAndFeel;

	//==============================================================================
	const String kMenuItemSineText   = "Sine";
	const String kMenuItemSawText    = "Saw";
	const String kMenuItemSquareText = "Square";

	const int kMenuItemSineId        = 1;
	const int kMenuItemSawId         = 2;
	const int kMenuItemSquareId      = 3;

	//==============================================================================
	ComboBox oscComboBox;

	//==============================================================================
	LtdRotarySlider m_freqSlider{ juce::String("Freq"), &lookAndFeel };
	LtdRotarySlider m_attackSlider{ juce::String("Attack"), &lookAndFeel };
	LtdRotarySlider m_decaySlider{ juce::String("Decay"), &lookAndFeel };
	LtdRotarySlider m_pitchEnvAmountSlider  { juce::String("Env Amt"), &lookAndFeel };
	LtdRotarySlider m_pitchEnvRateSlider{ juce::String("Env Rate"), &lookAndFeel };
	LtdRotarySlider m_pitchLfoAmountSlider{ juce::String("LFO Amt"), &lookAndFeel };
	LtdRotarySlider m_pitchLfoRateSlider { juce::String("LFO Rate"), &lookAndFeel };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
