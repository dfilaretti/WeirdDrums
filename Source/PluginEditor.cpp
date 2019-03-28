/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WdAudioProcessorEditor::WdAudioProcessorEditor (WdAudioProcessor& p)
    : AudioProcessorEditor (&p), 
	  processor (p), 
	  bottomSectionGui (p, "Version 0.1.1"),
	  titleSectionGui  ("WeirdDrums", "www.danielefilaretti.com"),
	  oscSectionGui    (p, 4, 2, "Oscillator"),
	  noiseSectionGui  (p, 4, 1, "Noise"),
	  masterSectionGui (p, 4, 1, "Master")
{
	// Setting up LookAndFeel & theme
	setLookAndFeel (&lookAndFeel);
	lookAndFeel.setTheme3(); 

	// add OSC SECTION children
	oscSectionGui.addRotarySlider(juce::String("Waveform"),       "WAVE-TYPE");
	oscSectionGui.addRotarySlider(juce::String("Freq"),           "FREQ");
	oscSectionGui.addRotarySlider(juce::String("Attack"),         "ATTACK");
	oscSectionGui.addRotarySlider(juce::String("Decay"),          "DECAY");
	oscSectionGui.addRotarySlider(juce::String("Env Amt"),        "PITCH-ENV-AMOUNT");
	oscSectionGui.addRotarySlider(juce::String("Env Rate"),       "PITCH-ENV-RATE");
	oscSectionGui.addRotarySlider(juce::String("LFO Amt"),        "PITCH-LFO-AMOUNT");
	oscSectionGui.addRotarySlider(juce::String("LFO Rate"),       "PITCH-LFO-RATE");
	// NOISE ...
	noiseSectionGui.addRotarySlider(juce::String("Cutoff"),       "FILTER-CUTOFF");
	noiseSectionGui.addRotarySlider(juce::String("Res"),          "FILTER-RESONANCE");
	noiseSectionGui.addRotarySlider(juce::String("Attack"),       "NOISE-ATTACK");
	noiseSectionGui.addRotarySlider(juce::String("Decay"),        "NOISE-DECAY");
	// MASTER ...
	masterSectionGui.addRotarySlider(juce::String("Mix"),         "MASTER-MIX");
	masterSectionGui.addRotarySlider(juce::String("Distort"),     "MASTER-DISTORT");
	masterSectionGui.addRotarySlider(juce::String("Level"),       "MASTER-LEVEL");
	masterSectionGui.addRotarySlider(juce::String("Filter Type"), "FILTER-TYPE");
	
	addAndMakeVisible (titleSectionGui);
	addAndMakeVisible (oscSectionGui);
	addAndMakeVisible (masterSectionGui);
	addAndMakeVisible (noiseSectionGui);
	addAndMakeVisible (bottomSectionGui); 

	setSize (kWidth, kHeight);
}



WdAudioProcessorEditor::~WdAudioProcessorEditor() 
{ 
	setLookAndFeel (nullptr); 
}

//==============================================================================
void WdAudioProcessorEditor::paint (Graphics& g)
{
	Colour backgroundColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		backgroundColour = lf->colour4;

	g.fillAll (backgroundColour);
}

void WdAudioProcessorEditor::resized()
{
	auto area  = getLocalBounds();

	auto titleArea  = area.removeFromTop(kTitleHeight);
	auto bottomArea = area.removeFromBottom(kTitleHeight);
	auto mainArea = area/*.reduced(4)*/;

	titleSectionGui.setBounds (titleArea);
	oscSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 2));
	noiseSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	masterSectionGui.setBounds(mainArea.removeFromLeft(kWidth / 4));
	bottomSectionGui.setBounds (bottomArea);
}