/*
  ==============================================================================

    LabelledSlider.cpp
    Created: 5 Mar 2019 8:38:02am
    Author:  dfila

  ==============================================================================
*/

#include "LabelledSlider.h"

LabelledSlider::LabelledSlider (juce::String label)
{
	// Set up name label
	m_nameLabel.setFont(Font(15.0f, Font::bold));
	m_nameLabel.setText (label, dontSendNotification);
	m_nameLabel.setJustificationType (Justification::centred);
	addAndMakeVisible (m_nameLabel);
};

LabelledSlider::~LabelledSlider()
{
	// TODO (probably nothing)
}

Slider* LabelledSlider::getSlider()
{
	return &m_slider;
}