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
    MasterSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~MasterSectionEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	MasterSectionLookAndFeel lookAndFeel;
	
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	//==============================================================================
	const int kTitleHeight = 25;
	const int kTopAreaHeight = 100;
	const int kBottomRightAreaWidth = 100;
	const int kBottomLeftAreaWidth = 150;

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
	juce::Rectangle<int> area;
	juce::Rectangle<int> titleArea;
	juce::Rectangle<int> controlsArea;
	juce::Rectangle<int> topArea;
	juce::Rectangle<int> bottomRightArea;
	juce::Rectangle<int> bottomLeftArea;

	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterSectionEditor)
};
