/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LittleDrumSynthAudioProcessorEditor::LittleDrumSynthAudioProcessorEditor (LittleDrumSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui (p), envGui (p), filterGui (p)
{
    setSize (kWidth, kHeight);

	//addAndMakeVisible(pluginUI);

	addAndMakeVisible(oscGui);
	addAndMakeVisible(envGui);
	addAndMakeVisible(filterGui);
}


LittleDrumSynthAudioProcessorEditor::~LittleDrumSynthAudioProcessorEditor()
{
}

//==============================================================================
void LittleDrumSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void LittleDrumSynthAudioProcessorEditor::resized()
{
	juce::Rectangle<int> area = getLocalBounds();

	oscGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));
	filterGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));
	envGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));

 	//pluginUI.setBounds(0,0,700, 500);
}