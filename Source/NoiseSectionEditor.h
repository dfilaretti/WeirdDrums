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
#include "Globals.h"
#include "LookAndFeels.h"

//==============================================================================

class NoiseSectionEditor	: public Component
{
public:
    NoiseSectionEditor(PatSynthAudioProcessor&);
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
	//const int kMargin                = 5;

	const int kTitleHeight = 25;
	const int kWaveformHeight = 100;
	const int kAmpWidth = 100;
	const int kModWidth = 150;

	//const int kSliderWidth         = 25;
	//const int kSliderHeight        = 175;

	//==============================================================================
	const String kMenuItemLowPassText  = "Low Pass";
	const String kMenuItemHighPassText = "High Pass";
	const String kMenuItemBandPassText = "Band Pass";

	//==============================================================================
	const int kMenuItemLowPassId   = 1;
	const int kMenuItemHighPassId  = 2;
	const int kMenuItemSBandPassId = 3;

	//==============================================================================
	ComboBox 
		filterTypeComboBox;
	
	ScopedPointer<ComboBoxAttachment> 
		filterTypeComboBoxAttachment;

	Slider filterCutoffSlider, filterResonanceSlider;
	Slider attackSlider, decaySlider;

	ScopedPointer<SliderAttachment>
		filterCutoffSliderAttachment,
		filterResonanceSliderAttachment;

	ScopedPointer<SliderAttachment>
		attackSliderAttachment, decaySliderAttachment;

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
		waveformArea,
		ampArea,
		miscArea;


	//==============================================================================
	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseSectionEditor)
};
