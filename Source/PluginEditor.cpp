/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LittleTeknoDrummerAudioProcessorEditor::LittleTeknoDrummerAudioProcessorEditor (LittleTeknoDrummerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui (p), envGui (p), filterGui (p)
{
	setLookAndFeel (&lookAndFeel);

	setSize (kWidth, kHeight);

	addAndMakeVisible (oscGui);
	addAndMakeVisible (envGui);
	addAndMakeVisible (filterGui);
}


LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor()
{
	setLookAndFeel (nullptr);
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void LittleTeknoDrummerAudioProcessorEditor::resized()
{
	auto area = getLocalBounds();

	oscGui.setBounds (area.removeFromTop (kHeight/3));
	filterGui.setBounds (area.removeFromTop (kHeight/3));
	envGui.setBounds (area.removeFromTop (kHeight/3));
}