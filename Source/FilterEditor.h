/*
  ==============================================================================

    FilterEditor.h
    Created: 6 Nov 2018 4:44:43pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Globals.h"

//==============================================================================

class FilterEditor	: public Component
{
public:
    FilterEditor(PatSynthAudioProcessor&);
    ~FilterEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

	const int kWidth = 200;
	const int kHeight = 200;

	const string kMenuItemLowPassText  = "Low Pass";
	const string kMenuItemHighPassText = "High Pass";
	const string kMenuItemBandPassText = "Band Pass";

	const int kMenuItemLowPassId   = 1;
	const int kMenuItemHighPassId  = 2;
	const int kMenuItemSBandPassId = 3;

	ComboBox 
		filterTypeComboBox;
	
	ScopedPointer<ComboBoxAttachment> 
		filterTypeComboBoxAttachment;

	Slider 
		filterCutoffSlider, 
		filterResonanceSlider;

	ScopedPointer<SliderAttachment>
		filterCutoffSliderAttachment,
		filterResonanceSliderAttachment;

	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterEditor)
};
