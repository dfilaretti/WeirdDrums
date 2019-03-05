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
	MasterSectionLookAndFeel lookAndFeel;
	
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	LtdRotarySlider mixSlider{ juce::String("Mix"), &lookAndFeel };
	LtdRotarySlider eqFreqSlider{ juce::String("EQ Freq"), &lookAndFeel };
	LtdRotarySlider distortSlider{ juce::String("Dist"), &lookAndFeel };
	LtdRotarySlider eqGainSlider{ juce::String("EqGain"), &lookAndFeel };
	LtdRotarySlider levelSlider{ juce::String("Level"), &lookAndFeel };
	LtdRotarySlider panSlider{ juce::String("Pan"), &lookAndFeel };

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
