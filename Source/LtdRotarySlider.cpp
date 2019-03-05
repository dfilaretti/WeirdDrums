/*
  ==============================================================================

    LtdRotarySlider.cpp
    Created: 5 Mar 2019 8:38:14am
    Author:  dfila

  ==============================================================================
*/

#include "LtdRotarySlider.h"

LtdRotarySlider::LtdRotarySlider (juce::String label, juce::LookAndFeel* lookAndFeel)
	: LtdSlider (label, lookAndFeel) // call base ctor
{
	m_slider.setLookAndFeel  (lookAndFeel);
	m_slider.setSliderStyle  (Slider::RotaryHorizontalVerticalDrag);
	m_slider.setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
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

	m_label.setBounds  (r.removeFromTop (height / 6));
	m_slider.setBounds (r);
}