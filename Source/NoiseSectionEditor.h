/*
  ==============================================================================

    NoiseSectionEditor.h
    Created: 6 Nov 2018 4:44:43pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"

//==============================================================================

class NoiseSectionEditor	: public Component
{
public:
    NoiseSectionEditor(LittleTeknoDrummerAudioProcessor&);
    ~NoiseSectionEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	//==============================================================================
	NoiseSectionLookAndFeel lookAndFeel;

	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

	//==============================================================================
	const int kTitleHeight = 25;
	const int topAreaHeight = 100;
	const int bottomRightAreaWidth = 100;
	const int bottomLeftAreaWidth = 150;

	//==============================================================================
	const String kMenuItemLowPassText  = "LP";
	const String kMenuItemHighPassText = "HP";
	const String kMenuItemBandPassText = "BP";

	//==============================================================================
	const int kMenuItemLowPassId   = 1;
	const int kMenuItemHighPassId  = 2;
	const int kMenuItemSBandPassId = 3;

	//==============================================================================
	ComboBox filterTypeComboBox;
	std::unique_ptr<ComboBoxAttachment> filterTypeComboBoxAttachment;

	//==============================================================================
	Slider filterCutoffSlider, filterResonanceSlider;
	Slider attackSlider, decaySlider;

	std::unique_ptr<SliderAttachment> filterCutoffSliderAttachment, filterResonanceSliderAttachment;
	std::unique_ptr<SliderAttachment> attackSliderAttachment, decaySliderAttachment;

	//==============================================================================
	Label m_filterTypeLabel;
	Label m_cutoffLabel;
	Label m_filterQLabel;
	Label m_attackLabel;
	Label m_decayLabel;

	//==============================================================================
	juce::Rectangle <int>
		area,
		titleArea,
		controlsArea,
		topArea,
		bottomRightArea,
		bottomLeftArea;

	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
