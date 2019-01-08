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
		frequencySliderAttachment,
		attackSliderAttachment,
		decaySliderAttachment,
		pitchEnvAmountAttachment,
		pitchEnvRateSliderAttachment,
		pitchLfoAmountAttachment,
		pitchLfoRateSliderAttachment;

	Label m_freqLabel;
	Label m_attackLabel;
	Label m_decayLabel;
	Label m_pitchEnvAmountLabel;
	Label m_pitchEnvRateLabel;
	Label m_pitchLfoAmountLabel;
	Label m_pitchLfoRateLabel;

	//==============================================================================
	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
