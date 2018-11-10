/*
  ==============================================================================

    EnvelopeEditor.h
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Globals.h"

//==============================================================================

class EnvelopeEditor    : public Component
{
public:
    EnvelopeEditor(PatSynthAudioProcessor&);
    ~EnvelopeEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

	const int kWidth        = 200;
	const int kHeight       = 200;
	const int kSliderWidth  = 25;
	const int kSliderHeight = 175;

	Slider 
		attackSlider, 
		decaySlider, 
		sustainSlider, 
		releaseSlider;
	
	ScopedPointer<SliderAttachment>
		attackSliderAttachment, 
		decaySliderAttachment, 
		sustainSliderAttachment, 
		releaseSliderAttachment;

	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeEditor)
};
