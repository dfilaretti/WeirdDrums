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
#include "Globals.h"

//==============================================================================
/*
*/
class OscillatorSectionEditor    : public Component
{
public:
    OscillatorSectionEditor(PatSynthAudioProcessor&);
    ~OscillatorSectionEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	//const int kMargin                = 5;
							         
	const int kTitleHeight           = 25;
	const int kWaveformHeight        = 100;
	const int kAmpWidth              = 100;
	const int kModWidth              = 150;

	//const int kSliderWidth         = 25;
	//const int kSliderHeight        = 175;

	//==============================================================================
	const string kMenuItemSineText   = "Sine";
	const string kMenuItemSawText    = "Saw";
	const string kMenuItemSquareText = "Square";

	const int kMenuItemSineId        = 1;
	const int kMenuItemSawId         = 2;
	const int kMenuItemSquareId      = 3;

	//==============================================================================
	juce::Rectangle <int>
		area,
		titleArea,
		controlsArea,
		waveformArea,
		ampArea,
		modArea;

	//==============================================================================
	ComboBox 
		oscComboBox;

	Slider
		frequencySlider,
		attackSlider,
		decaySlider,
		pitchEnvAmountSlider,
		pitchEnvRateSlider,
		pitchLfoAmountSlider,
		pitchLfoRateSlider;

	//==============================================================================
	ScopedPointer<ComboBoxAttachment> 
		oscComboBoxAttachment;

	ScopedPointer<SliderAttachment>
		attackSliderAttachment,
		decaySliderAttachment,
		frequencySliderAttachment,
		pitchEnvAmountAttachment,
		pitchEnvRateSliderAttachment,
		pitchLfoAmountAttachment,
		pitchLfoRateSliderAttachment;

	//==============================================================================
	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
