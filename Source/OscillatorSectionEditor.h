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

//==============================================================================
/*
*/
class OscillatorSectionEditor    : public Component
{
public:
    OscillatorSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~OscillatorSectionEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	OscSectionLookAndFeel lookAndFeel;

	//==============================================================================
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	const int kTitleHeight           = 25;
	const int kTopAreaHeight        = 100;
	const int bottomRightAreaWidth              = 100;
	const int bottomLeftAreaWidth              = 150;

	//==============================================================================
	const String kMenuItemSineText   = "Sine";
	const String kMenuItemSawText    = "Saw";
	const String kMenuItemSquareText = "Square";

	const int kMenuItemSineId        = 1;
	const int kMenuItemSawId         = 2;
	const int kMenuItemSquareId      = 3;

	//==============================================================================
	juce::Rectangle <int>
		area,
		titleArea,
		controlsArea,
		topArea,
		bottomRightArea,
		bottomLeftArea;

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
	std::unique_ptr<ComboBoxAttachment> 
		oscComboBoxAttachment;

	std::unique_ptr<SliderAttachment>
		frequencySliderAttachment,
		attackSliderAttachment,
		decaySliderAttachment,
		pitchEnvAmountAttachment,
		pitchEnvRateSliderAttachment,
		pitchLfoAmountAttachment,
		pitchLfoRateSliderAttachment;

	//==============================================================================
	Label m_freqLabel;
	Label m_attackLabel;
	Label m_decayLabel;
	Label m_pitchEnvAmountLabel;
	Label m_pitchEnvRateLabel;
	Label m_pitchLfoAmountLabel;
	Label m_pitchLfoRateLabel;

	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
