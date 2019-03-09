/*
  ==============================================================================

    MasterSectionEditor.h
    Created: 6 Nov 2018 3:44:06pm
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

class MasterSectionEditor    : public LtdComplexComponent
{
public:
    MasterSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~MasterSectionEditor();

private:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	LtdRotarySlider mixSlider{ juce::String("MIX") };
	LtdRotarySlider eqFreqSlider{ juce::String("EQ FREQ") };
	LtdRotarySlider distortSlider{ juce::String("DIST") };
	LtdRotarySlider eqGainSlider{ juce::String("EQGAIN") };
	LtdRotarySlider levelSlider{ juce::String("LEVEL") };
	LtdRotarySlider panSlider{ juce::String("PAN") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
