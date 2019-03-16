/*
  ==============================================================================

    TitleSectionEditor.cpp
    Created: 16 Mar 2019 10:44:16am
    Author:  dfila

  ==============================================================================
*/

#include "TitleSectionEditor.h"

//==============================================================================
TitleSectionEditor::TitleSectionEditor(std::string m_title, std::string m_company) 
	: pluginTitle {m_title}, pluginCompany {m_company}
{
	// Nothing to be done here, for now.
}

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
	g.setFont(Font(40.0f, Font::bold)); // TODO: move to centralised place
	g.drawText(pluginTitle, titleArea, Justification::left, true);

	// draw credits
	g.setColour(Colours::black);
	g.setFont(Font(16.0f, Font::bold));

	g.drawText(pluginCompany, creditsArea, Justification::right, true);
}

void TitleSectionEditor::resized()
{
	// TODO
}

//==============================================================================