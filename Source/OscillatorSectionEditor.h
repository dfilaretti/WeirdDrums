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
#include "Grid2d.h"
#include "LabelledRotarySlider.h"

//==============================================================================
/*
*/
class OscillatorSectionEditor    : public Grid2d
{
public:
	//==============================================================================
    OscillatorSectionEditor(WdAudioProcessor&, 
		                    int, 
		                    int, 
		                    std::string, 
		                    Colour);
    ~OscillatorSectionEditor();

private:
	//==============================================================================
	LabelledRotarySlider m_oscSlider{ juce::String("Waveform") };
	LabelledRotarySlider m_freqSlider{ juce::String("Freq") };
	LabelledRotarySlider m_attackSlider{ juce::String("Attack") };
	LabelledRotarySlider m_decaySlider{ juce::String("Decay") };
	LabelledRotarySlider m_pitchEnvAmountSlider  { juce::String("Env Amt") };
	LabelledRotarySlider m_pitchEnvRateSlider{ juce::String("Env Rate") };
	LabelledRotarySlider m_pitchLfoAmountSlider{ juce::String("LFO Amt") };
	LabelledRotarySlider m_pitchLfoRateSlider { juce::String("LFO Rate") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
