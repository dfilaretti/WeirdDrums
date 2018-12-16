/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PatSynthAudioProcessorEditor::PatSynthAudioProcessorEditor (PatSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui (p), envGui (p), filterGui (p), pluginUI (p)
{
    setSize (kWidth, kHeight);

	addAndMakeVisible(pluginUI);

	//addAndMakeVisible(oscGui);
	//addAndMakeVisible(envGui);
	//addAndMakeVisible(filterGui);
}


PatSynthAudioProcessorEditor::~PatSynthAudioProcessorEditor()
{
}

//==============================================================================
void PatSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void PatSynthAudioProcessorEditor::resized()
{
	//juce::Rectangle<int> area = getLocalBounds();

	//oscGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));
	//filterGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));
	//envGui.setBounds(area.removeFromLeft(kSectionWidth).removeFromTop(kSectionHeight));

 	pluginUI.setBounds(0,0,700, 500);
}