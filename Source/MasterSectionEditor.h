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
#include "Globals.h"

//==============================================================================

class MasterSectionEditor    : public Component
{
public:
    MasterSectionEditor(PatSynthAudioProcessor&);
    ~MasterSectionEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	//const int kMargin                = 5;

	const int kTitleHeight = 25;
	const int kWaveformHeight = 100;
	const int kAmpWidth = 100;
	const int kModWidth = 150;

	//const int kSliderWidth         = 25;
	//const int kSliderHeight        = 175;

	//==============================================================================

	Slider mixSlider;
	Slider eqFreqSlider;
	Slider distortSlider;
	Slider eqGainSlider;
	Slider levelSlider;
	Slider panSlider;

	ScopedPointer<SliderAttachment> mixSliderAttachment;
	ScopedPointer<SliderAttachment> eqFreqSliderAttachment;
	ScopedPointer<SliderAttachment> distortSliderAttachment;
	ScopedPointer<SliderAttachment> eqGainSliderAttachment;
	ScopedPointer<SliderAttachment> levelSliderAttachment;
	ScopedPointer<SliderAttachment> panSliderAttachment;

	//==============================================================================
	juce::Rectangle <int>
		area,
		titleArea,
		controlsArea,
		waveformArea,
		ampArea,
		miscArea;

	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
