/*
  ==============================================================================

    TitleSectionEditor.cpp
    Created: 16 Mar 2019 10:44:16am
    Author:  dfila

  ==============================================================================
*/

#include "TitleSectionEditor.h"

//==============================================================================
TitleSectionEditor::TitleSectionEditor(std::string title, std::string company) 
{
	// Setup title
	m_pluginTitleLabel.setColour(Label::textColourId, Colours::black);
	m_pluginTitleLabel.setFont(Font(40.0f, Font::bold));
	m_pluginTitleLabel.setText(title, dontSendNotification);
	m_pluginTitleLabel.setJustificationType(Justification::left);
	addAndMakeVisible(m_pluginTitleLabel);

	// Setup credits
	m_pluginCompanyLabel.setColour(Label::textColourId, Colours::black);
	m_pluginCompanyLabel.setFont(Font(16.0f, Font::bold));
	m_pluginCompanyLabel.setText(company, dontSendNotification);
	m_pluginCompanyLabel.setJustificationType(Justification::right);
	addAndMakeVisible(m_pluginCompanyLabel);
}

TitleSectionEditor::~TitleSectionEditor() {}

//==============================================================================
void TitleSectionEditor::paint (Graphics& g) {}

void TitleSectionEditor::resized()
{
	auto area        = getLocalBounds();
	auto width       = area.getWidth();
	auto height      = area.getHeight();
	auto titleArea   = area.removeFromLeft(width / 2);
	auto creditsArea = area;

	m_pluginTitleLabel.setBounds(titleArea);
	m_pluginCompanyLabel.setBounds(creditsArea);
}

//==============================================================================