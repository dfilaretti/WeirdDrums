/*
  ==============================================================================

    LtdSlider.cpp
    Created: 5 Mar 2019 8:38:02am
    Author:  dfila

  ==============================================================================
*/

#include "LtdSlider.h"

LtdSlider::LtdSlider (juce::String label)
{
	// Set up label
	m_label.setText (label, dontSendNotification);
	m_label.setJustificationType (Justification::centredTop);
	addAndMakeVisible (m_label);
}

LtdSlider::~LtdSlider()
{
	// TODO (probably nothing)
}

Slider* LtdSlider::getSlider()
{
	return &m_slider;
}