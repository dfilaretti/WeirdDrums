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
	LtdRotarySlider m_oscSlider{ juce::String("WAVEFORM") };
	LtdRotarySlider m_freqSlider{ juce::String("FREQ") };
	LtdRotarySlider m_attackSlider{ juce::String("ATTACK") };
	LtdRotarySlider m_decaySlider{ juce::String("DECAY") };
	LtdRotarySlider m_pitchEnvAmountSlider  { juce::String("ENV AMT") };
	LtdRotarySlider m_pitchEnvRateSlider{ juce::String("ENV RATE") };
	LtdRotarySlider m_pitchLfoAmountSlider{ juce::String("LFO AMT") };
	LtdRotarySlider m_pitchLfoRateSlider { juce::String("LFO RATE") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
