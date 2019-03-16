/*
  ==============================================================================

    TitleSectionEditor.h
    Created: 16 Mar 2019 10:44:16am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class TitleSectionEditor : public Component
{
public:
	//==============================================================================
	TitleSectionEditor (std::string /*title*/, std::string /*company*/);
	~TitleSectionEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

private:
	//==============================================================================
	Label m_pluginTitleLabel;
	Label m_pluginCompanyLabel;
};