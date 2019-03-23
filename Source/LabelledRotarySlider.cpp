/*
  ==============================================================================

    LabelledRotarySlider.cpp
    Created: 5 Mar 2019 8:38:14am
    Author:  dfila

  ==============================================================================
*/

#include "LabelledRotarySlider.h"

LabelledRotarySlider::LabelledRotarySlider (juce::String label)
	: LabelledSlider (label) // call base ctor
{
	m_slider.setSliderStyle  (Slider::RotaryHorizontalVerticalDrag);
	addAndMakeVisible (&m_slider);
}

LabelledRotarySlider::~LabelledRotarySlider()
{
	// TODO (probably nothing)
}

void LabelledRotarySlider::paint(Graphics& g)
{
}

void LabelledRotarySlider::resized()
{
	auto r      = getLocalBounds();
	auto width  = r.getWidth();
	auto height = r.getHeight();
	auto labelsHeight = height / squeezeFactor;

	m_slider.setTextBoxStyle (Slider::TextBoxBelow, 
		                      true, 
		                      width, 
		                      labelsHeight);

	m_nameLabel.setBounds  (r.removeFromTop (labelsHeight));
	m_slider.setBounds (r);
}