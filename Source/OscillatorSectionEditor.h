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
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

	//==============================================================================
	
	const int kWidth  = 200;
	const int kHeight = 200;

	const string kMenuItemSineText   = "Sine";
	const string kMenuItemSawText    = "Saw";
	const string kMenuItemSquareText = "Square";

	const int kMenuItemSineId   = 1;
	const int kMenuItemSawId    = 2;
	const int kMenuItemSquareId = 3;

	ComboBox oscComboBox;
	ScopedPointer<ComboBoxAttachment> oscComboBoxAttachment;

	PatSynthAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSectionEditor)
};
