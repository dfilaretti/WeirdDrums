/*
  ==============================================================================

    LtdSlider.h
    Created: 5 Mar 2019 8:38:02am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class LtdSlider :	public Component
{
public:
	//==============================================================================
	LtdSlider (juce::String label);
	~LtdSlider();

	//==============================================================================
	void paint(Graphics&) override = 0;
	void resized() override = 0;

	//==============================================================================
	Slider* getSlider();

protected:
	Slider m_slider;
	Label m_label;
};