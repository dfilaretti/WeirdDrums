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
MasterSectionEditor::MasterSectionEditor(LittleTeknoDrummerAudioProcessor& p) : 
	processor (p)
{
	// Setup labels
	m_mixLabel.setText("mix", dontSendNotification);
	m_mixLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_mixLabel);

	m_eqFreqLabel.setText("eq freq", dontSendNotification);
	m_eqFreqLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_eqFreqLabel);
	
	m_distortLabel.setText("distort", dontSendNotification);
	m_distortLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_distortLabel);

	m_eqGainLabel.setText("eq gain", dontSendNotification);
	m_eqGainLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_eqGainLabel);

	m_levelLabel.setText("level", dontSendNotification);
	m_levelLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_levelLabel);
	
	m_panLabel.setText("pan", dontSendNotification);
	m_panLabel.setJustificationType(Justification::centredTop);
	addAndMakeVisible(m_panLabel);

	// mix slider
	mixSlider.setLookAndFeel (&lookAndFeel);
	mixSlider.setSliderStyle(Slider::LinearHorizontal);
	mixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&mixSlider);
	mixSliderAttachment = std::make_unique<SliderAttachment> (processor.parameters, "MASTER-MIX", mixSlider);

	// eq freq slider
	eqFreqSlider.setEnabled (false);
	eqFreqSlider.setLookAndFeel (&lookAndFeel);
	eqFreqSlider.setSliderStyle(Slider::LinearHorizontal);
	eqFreqSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&eqFreqSlider);
	eqFreqSliderAttachment = std::make_unique<SliderAttachment>(processor.parameters, "MASTER-EQ-FREQ", eqFreqSlider);
	
	// distort (rotary) slider
	distortSlider.setLookAndFeel (&lookAndFeel);
	distortSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	distortSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&distortSlider);
	distortSliderAttachment = std::make_unique<SliderAttachment>(processor.parameters, "MASTER-DISTORT", distortSlider);

	// eq gain (rotary) slider
	eqGainSlider.setEnabled (false);
	eqGainSlider.setLookAndFeel (&lookAndFeel);
	eqGainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	eqGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&eqGainSlider);
	eqGainSliderAttachment = std::make_unique<SliderAttachment>(processor.parameters, "MASTER-EQ-GAIN", eqGainSlider);

	// level (rotary) slider
	levelSlider.setLookAndFeel (&lookAndFeel);
	levelSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	levelSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&levelSlider);
	levelSliderAttachment = std::make_unique<SliderAttachment>(processor.parameters, "MASTER-LEVEL", levelSlider);

	// pan (rotary) slider
	panSlider.setEnabled (false);
	panSlider.setLookAndFeel (&lookAndFeel);
	panSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	panSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&panSlider);
	panSliderAttachment = std::make_unique<SliderAttachment>(processor.parameters, "MASTER-PAN", panSlider);
}

MasterSectionEditor::~MasterSectionEditor()
{
}

void MasterSectionEditor::paint (Graphics& g)
{
	g.setColour (Colour (0xFF171717));
	
	auto r = getLocalBounds();

	auto titleArea = r.removeFromTop (kTitleHeight);
	g.fillRect ( titleArea.reduced (3) );

	auto controlsArea = r.reduced (3);
	g.fillRect (controlsArea);

	g.setColour(Colours::white);
	g.drawText("M A S T E R", titleArea, Justification::centred);
}

void MasterSectionEditor::resized()
{
	// Update rectangles sizes
	area            = getLocalBounds();
	titleArea       = area.removeFromTop(kTitleHeight);
	topArea         = area.removeFromTop(kTopAreaHeight);
	bottomRightArea = area.removeFromRight(kBottomRightAreaWidth);
	bottomLeftArea  = area.removeFromRight(kBottomLeftAreaWidth);

	// TOP AREA

	// Mix
	{
		auto r = topArea.removeFromTop(50);
		mixSlider.setBounds(r.removeFromTop(25));
		m_mixLabel.setBounds(r);
	}

	// Eq Freq
	{
		auto r = topArea.removeFromTop(50);
		eqFreqSlider.setBounds(r.removeFromTop(25));
		m_eqFreqLabel.setBounds(r);
	}

	// BOTTOM-LEFT AREA

	auto eqGainAndPanlidersArea = bottomLeftArea.removeFromRight(75);

	// Eq Gain
	{
		auto r = eqGainAndPanlidersArea.removeFromTop(75);
		eqGainSlider.setBounds(r.removeFromTop(60));
		m_eqGainLabel.setBounds(r);
	}

	// Pan
	{
		auto r = eqGainAndPanlidersArea.removeFromTop(75);
		panSlider.setBounds(r.removeFromTop(60));
		m_panLabel.setBounds(r);
	}

	auto distortAndLevelSlidersArea = bottomLeftArea.removeFromRight(75);

	// Distort
	{
		auto r = distortAndLevelSlidersArea.removeFromTop(75);
		distortSlider.setBounds(r.removeFromTop(60));
		m_distortLabel.setBounds(r);
	}

	// Level
	{
		auto r = distortAndLevelSlidersArea.removeFromTop(75);
		levelSlider.setBounds(r.removeFromTop(60));
		m_levelLabel.setBounds(r);
	}
}
