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
	MasterSectionLookAndFeel lookAndFeel;
	
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

	std::unique_ptr<SliderAttachment> mixSliderAttachment;
	std::unique_ptr<SliderAttachment> eqFreqSliderAttachment;
	std::unique_ptr<SliderAttachment> distortSliderAttachment;
	std::unique_ptr<SliderAttachment> eqGainSliderAttachment;
	std::unique_ptr<SliderAttachment> levelSliderAttachment;
	std::unique_ptr<SliderAttachment> panSliderAttachment;

	Label m_mixLabel;
	Label m_eqFreqLabel;
	Label m_distortLabel;
	Label m_eqGainLabel;
	Label m_levelLabel;
	Label m_panLabel;

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
