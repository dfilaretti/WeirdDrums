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
    : AudioProcessorEditor (&p), 
	  processor (p), 
	  oscSectionGui    (p, 4, 2, "Oscillator", Colours::black), 
	  noiseSectionGui  (p, 4, 1, "Noise",      Colours::black),
	  masterSectionGui (p, 4, 1, "Master",     Colours::black)
{
	setSize (kWidth, kHeight);
	addAndMakeVisible (oscSectionGui);
	addAndMakeVisible (masterSectionGui);
	addAndMakeVisible (noiseSectionGui);
}

LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor() {}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll (Colours::lightgrey);

	// draw title area
	auto area = getLocalBounds();
	auto headerArea = area.removeFromTop(kTitleHeight).reduced(8);
	auto titleArea = headerArea.removeFromLeft (area.getWidth() / 2);
	auto creditsArea = headerArea;

	// draw title
	g.setColour(Colours::black);
	g.setFont(Font(40.0f, Font::bold));
	g.drawText("TeknoDrums", titleArea, Justification::left, true);

	// draw credits
	g.setColour(Colours::black);
	g.setFont(Font(15.0f, Font::bold));
	
	g.drawText("Version 0.1.1", 
		       creditsArea.removeFromTop (creditsArea.getHeight() / 2), 
		       Justification::centredRight, true);

	g.drawText("www.danielefilaretti.com", 
		       creditsArea,
		       Justification::centredRight, true);
}

void LittleTeknoDrummerAudioProcessorEditor::resized()
{
	auto area = getLocalBounds();
	auto titleArea = area.removeFromTop(kTitleHeight);

	auto mainArea = area.reduced(4);
	oscSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 2));
	noiseSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	masterSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
}
