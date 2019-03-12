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
	//m_slider.setTextBoxStyle (Slider::TextBoxBelow, true, 100, 20);
	//m_slider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
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
	auto labelsHeight = height / squeezeFactor;

	m_slider.setTextBoxStyle(Slider::TextBoxBelow, true, width, labelsHeight);

	m_nameLabel.setBounds  (r.removeFromTop (labelsHeight));
	m_slider.setBounds (r);
}