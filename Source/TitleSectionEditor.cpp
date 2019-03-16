/*
  ==============================================================================

    TitleSectionEditor.cpp
    Created: 16 Mar 2019 10:44:16am
    Author:  dfila

  ==============================================================================
*/

#include "TitleSectionEditor.h"

//==============================================================================
TitleSectionEditor::TitleSectionEditor() {}
TitleSectionEditor::~TitleSectionEditor() {}

//==============================================================================
void TitleSectionEditor::paint (Graphics& g)
{
	// draw title area
	auto area   = getLocalBounds();
	auto width  = area.getWidth();
	auto height = area.getHeight();

	auto titleArea   = area.removeFromLeft (width / 2);
	auto creditsArea = area;

	// draw title
	g.setColour(Colours::black);
	g.setFont(Font(40.0f, Font::bold));
	g.drawText("WeirdDrums", titleArea, Justification::left, true);

	// draw credits
	g.setColour(Colours::black);
	g.setFont(Font(16.0f, Font::bold));

	g.drawText("www.danielefilaretti.com", creditsArea, Justification::right, true);
}

void TitleSectionEditor::resized()
{
	// TODO
}

//==============================================================================