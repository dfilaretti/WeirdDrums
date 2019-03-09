/*
  ==============================================================================

    LtdRotarySlider.cpp
    Created: 5 Mar 2019 8:38:14am
    Author:  dfila

  ==============================================================================
*/

#include "LtdRotarySlider.h"

LtdRotarySlider::LtdRotarySlider (juce::String label)
	: LtdSlider (label) // call base ctor
{
	m_slider.setSliderStyle  (Slider::RotaryHorizontalVerticalDrag);
	m_slider.setTextBoxStyle (Slider::NoTextBox, true, 0, 0);
	addAndMakeVisible (&m_slider);
}

LtdRotarySlider::~LtdRotarySlider()
{
	// TODO (probably nothing)
}

void LtdRotarySlider::paint(Graphics& g)
{
	//g.fillAll (Colours::darkgrey);
}

void LtdRotarySlider::resized()
{
	auto r      = getLocalBounds();
	auto width  = r.getWidth();
	auto height = r.getHeight();

	m_nameLabel.setBounds  (r.removeFromTop (height / squeezeFactor));
	m_valueLabel.setBounds(r.removeFromBottom(height / squeezeFactor));
	m_slider.setBounds (r);

	//m_slider.setTextBoxStyle(Slider::TextBoxBelow, true, width, height / squeezeFactor);
}