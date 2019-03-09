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
	const String kMenuItemSineText   = "Sine";
	const String kMenuItemSawText    = "Saw";
	const String kMenuItemSquareText = "Square";

	const int kMenuItemSineId        = 1;
	const int kMenuItemSawId         = 2;
	const int kMenuItemSquareId      = 3;

	//==============================================================================
	ComboBox oscComboBox;

	//==============================================================================
	LtdRotarySlider m_freqSlider{ juce::String("Freq") };
	LtdRotarySlider m_attackSlider{ juce::String("Attack") };
	LtdRotarySlider m_decaySlider{ juce::String("Decay") };
	LtdRotarySlider m_pitchEnvAmountSlider  { juce::String("Env Amt") };
	LtdRotarySlider m_pitchEnvRateSlider{ juce::String("Env Rate") };
	LtdRotarySlider m_pitchLfoAmountSlider{ juce::String("LFO Amt") };
	LtdRotarySlider m_pitchLfoRateSlider { juce::String("LFO Rate") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
