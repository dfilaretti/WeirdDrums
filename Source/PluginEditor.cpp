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
    : AudioProcessorEditor (&p), processor (p), oscGui (p, 4, 2), envGui (p, 4, 1), filterGui (p, 4, 1)
{
	// Set up lookandfeel
	//setLookAndFeel (&lookAndFeel);
	
	setSize (kWidth, kHeight);

	addAndMakeVisible (oscGui);
	addAndMakeVisible (envGui);
	addAndMakeVisible (filterGui);

	auto sectionBackgroundColour = Colours::black;

	oscGui.setBackgroundColour(sectionBackgroundColour);
	envGui.setBackgroundColour(sectionBackgroundColour);
	filterGui.setBackgroundColour (sectionBackgroundColour);
}

LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor()
{
	//setLookAndFeel (nullptr);
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll (Colours::white);

	// draw title area
	auto area = getLocalBounds();
	auto titleArea = area.removeFromTop(kTitleHeight);

	g.setColour(Colours::black);
	g.setFont(Font(38.0f, Font::bold));

	g.drawText("TeknoDrumz v.0.1", titleArea, Justification::centred, true);

}

void LittleTeknoDrummerAudioProcessorEditor::resized()
{
	auto area = getLocalBounds();
	auto titleArea = area.removeFromTop(kTitleHeight);

	auto mainArea = area.reduced(4);
	oscGui.setBounds(mainArea.removeFromLeft(kWidth / 2));
	filterGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	envGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
}
