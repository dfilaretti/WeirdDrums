/*
  ==============================================================================

    BottomSectionEditor.cpp
    Created: 16 Mar 2019 10:44:28am
    Author:  dfila

  ==============================================================================
*/

#include "BottomSectionEditor.h"

//==============================================================================
BottomSectionEditor::BottomSectionEditor(WdAudioProcessor& processor,
	                                     std::string versionInfo)
	: m_processor {processor}, m_versionInfo {versionInfo}
{
	// init buttons functionality
	initResetButton();
	initRandomButton();

	// setup version slider
	m_versionLabel.setFont(Font(16.0f, Font::bold));
	m_versionLabel.setText(m_versionInfo, dontSendNotification);
	m_versionLabel.setJustificationType(Justification::right);
	addAndMakeVisible(m_versionLabel);
}

BottomSectionEditor::~BottomSectionEditor()
{
	// Nothing to do, for now...
}

//==============================================================================

void BottomSectionEditor::paint(Graphics& /*g*/) 
{
}

void BottomSectionEditor::resized()
{
	auto area            = getLocalBounds();
	auto width           = area.getWidth();
	auto button1Area     = area.removeFromLeft(width / 4);
	auto button2Area     = area.removeFromLeft(width / 4);
	auto versionInfoArea = area;

	Colour textColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		textColour = lf->colour1;

	m_versionLabel.setColour(Label::textColourId, textColour);

	m_resetButton.setBounds  (button1Area);
	m_randomButton.setBounds (button2Area);
	m_versionLabel.setBounds (versionInfoArea);
}

//==============================================================================
void BottomSectionEditor::initResetButton()
{
	m_resetButton.onClick = [&]()
	{
		auto paramsToReset =
		{
			"FREQ",
			"ATTACK",
			"DECAY",
			"WAVE-TYPE",
			"PITCH-ENV-AMOUNT",
			"PITCH-ENV-RATE",
			"PITCH-LFO-AMOUNT",
			"PITCH-LFO-RATE",
			"FILTER-TYPE",
			"FILTER-CUTOFF",
			"FILTER-RESONANCE",
			"NOISE-ATTACK",
			"NOISE-DECAY",
			"MASTER-MIX",
			"MASTER-DISTORT",
			"MASTER-LEVEL"
		};

		for (auto paramtoReset : paramsToReset)
		{
			auto param = dynamic_cast<juce::AudioProcessorParameterWithID*>(m_processor.parameters.getParameter(paramtoReset));
			auto defaultValueNormalised = param->getDefaultValue();
			param->setValueNotifyingHost(defaultValueNormalised);
		}
	};

	addAndMakeVisible(m_resetButton);
	m_resetButton.setButtonText("Init");
}

void BottomSectionEditor::initRandomButton()
{
	m_randomButton.onClick = [&]()
	{
		auto paramsToReset =
		{
			"FREQ",
			"ATTACK",
			"DECAY",
			"WAVE-TYPE",
			"PITCH-ENV-AMOUNT",
			"PITCH-ENV-RATE",
			"PITCH-LFO-AMOUNT",
			"PITCH-LFO-RATE",
			"FILTER-TYPE",
			"FILTER-CUTOFF",
			"FILTER-RESONANCE",
			"NOISE-ATTACK",
			"NOISE-DECAY",
			"MASTER-MIX",
			"MASTER-DISTORT"
			//"MASTER-LEVEL" // don't randomize this!
		};

		for (auto paramtoReset : paramsToReset)
		{
			auto param = dynamic_cast<juce::AudioProcessorParameterWithID*>(m_processor.parameters.getParameter(paramtoReset));
			auto randomValueNormalised = m_randomNumberGenerator.nextFloat();
			param->setValueNotifyingHost(randomValueNormalised);
		}
	};

	addAndMakeVisible(m_randomButton);
	m_randomButton.setButtonText("Rand");
}