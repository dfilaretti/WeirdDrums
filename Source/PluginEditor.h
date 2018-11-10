/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "OscillatorEditor.h"
#include "EnvelopeEditor.h"
#include "FilterEditor.h"

//==============================================================================

class PatSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    PatSynthAudioProcessorEditor (PatSynthAudioProcessor&);
    ~PatSynthAudioProcessorEditor();

	//==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
	const int kWidth         = 600;
	const int kHeight        = 200;
	const int kSectionWidth  = 200;
	const int kSectionHeight = 200;

    PatSynthAudioProcessor& processor;

	OscillatorEditor oscGui;
	EnvelopeEditor envGui;
	FilterEditor filterGui;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatSynthAudioProcessorEditor)
};
