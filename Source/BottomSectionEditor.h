/*
  ==============================================================================

    BottomSectionEditor.h
    Created: 16 Mar 2019 11:22:47am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"

class BottomSectionEditor : public Component
{
public:
	//==============================================================================
	BottomSectionEditor (WdAudioProcessor& /*processor*/,
		                 std::string /*versionInfo*/);
	
	~BottomSectionEditor();

	//==============================================================================
	void paint (Graphics& /*g*/) override;
	void resized() override;

private:
	//==============================================================================
	WdAudioProcessor& m_processor;
	std::string m_versionInfo;

	//==============================================================================
	TextButton m_resetButton;
	TextButton m_randomButton;
	Label m_versionLabel;

	//==============================================================================
	Random m_randomNumberGenerator;

	//==============================================================================
	void initResetButton();
	void initRandomButton();
};