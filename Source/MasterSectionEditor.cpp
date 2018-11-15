/*
  ==============================================================================

    MasterSectionEditor.cpp
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MasterSectionEditor.h"

//==============================================================================
MasterSectionEditor::MasterSectionEditor(PatSynthAudioProcessor& p) : 
	processor (p)
{
}

MasterSectionEditor::~MasterSectionEditor()
{
}

void MasterSectionEditor::paint (Graphics& g)
{
	juce::Rectangle <int> area      = getLocalBounds().reduced(kMargin);
	juce::Rectangle <int> titleArea = area.removeFromTop(kTitleHeight);
	
	g.fillAll(Colours::black);
	
	g.setColour(Colours::white);
	g.drawText("Master", titleArea, Justification::centredTop);
}

void MasterSectionEditor::resized()
{
	auto area      = getLocalBounds().reduced(kMargin);
	auto titleArea = area.removeFromTop(kTitleHeight);
}
