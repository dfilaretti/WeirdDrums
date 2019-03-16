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
	  bottomSectionGui (p, "Version 999.2"),
	  titleSectionGui  ("LolDrumz", "www.danielefilaretti.com"),
	  oscSectionGui    (p, 4, 2, "Oscillator", Colours::black),
	  noiseSectionGui  (p, 4, 1, "Noise",      Colours::black),
	  masterSectionGui (p, 4, 1, "Master",     Colours::black)
{
	setSize (kWidth, kHeight);

	setLookAndFeel (&lookAndFeel);

	addAndMakeVisible(titleSectionGui);
	addAndMakeVisible (oscSectionGui);
	addAndMakeVisible (masterSectionGui);
	addAndMakeVisible (noiseSectionGui);
	addAndMakeVisible(bottomSectionGui); 
}

LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor() 
{ 
	setLookAndFeel (nullptr); 
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll (Colours::lightgrey); // TODO: move to centralised place
}

void LittleTeknoDrummerAudioProcessorEditor::resized()
{
	auto area  = getLocalBounds();
	auto width = area.getWidth();

	auto titleArea  = area.removeFromTop(kTitleHeight);
	auto bottomArea = area.removeFromBottom(kTitleHeight);
	auto mainArea = area/*.reduced(4)*/;

	titleSectionGui.setBounds (titleArea);
	oscSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 2));
	noiseSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	masterSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	bottomSectionGui.setBounds (bottomArea);
}