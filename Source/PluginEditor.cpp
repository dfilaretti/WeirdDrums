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
	  bottomSectionGui (p, "Version 0.1.1"),
	  titleSectionGui  ("WeirdDrums", "www.danielefilaretti.com"),
	  oscSectionGui    (p, 4, 2, "Oscillator", Colours::black),
	  noiseSectionGui  (p, 4, 1, "Noise",      Colours::black),
	  masterSectionGui (p, 4, 1, "Master",     Colours::black)
{
	setLookAndFeel (&lookAndFeel);
	lookAndFeel.setTheme1();

	addAndMakeVisible (titleSectionGui);
	addAndMakeVisible (oscSectionGui);
	addAndMakeVisible (masterSectionGui);
	addAndMakeVisible (noiseSectionGui);
	addAndMakeVisible (bottomSectionGui); 

	setSize (kWidth, kHeight);
}

LittleTeknoDrummerAudioProcessorEditor::~LittleTeknoDrummerAudioProcessorEditor() 
{ 
	setLookAndFeel (nullptr); 
}

//==============================================================================
void LittleTeknoDrummerAudioProcessorEditor::paint (Graphics& g)
{
	Colour backgroundColour;
	if (auto lf = dynamic_cast<LittleTeknoDrummerLookAndFeel*> (&getLookAndFeel()))
		backgroundColour = lf->colour4;

	g.fillAll (backgroundColour);
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