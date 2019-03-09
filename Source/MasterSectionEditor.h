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
	LtdRotarySlider mixSlider{ juce::String("Mix") };
	LtdRotarySlider eqFreqSlider{ juce::String("EQ Freq") };
	LtdRotarySlider distortSlider{ juce::String("Dist") };
	LtdRotarySlider eqGainSlider{ juce::String("EqGain") };
	LtdRotarySlider levelSlider{ juce::String("Level") };
	LtdRotarySlider panSlider{ juce::String("Pan") };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
