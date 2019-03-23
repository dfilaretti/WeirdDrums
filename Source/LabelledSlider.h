/*
  ==============================================================================

    LabelledSlider.h
    Created: 5 Mar 2019 8:38:02am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class LabelledSlider :	public Component
{
public:
	//==============================================================================
	LabelledSlider (juce::String label);
	~LabelledSlider();

	//==============================================================================
	void paint(Graphics&) override = 0;
	void resized() override = 0;

	//==============================================================================
	Slider* getSlider();

protected:
	Slider m_slider;
	Label m_nameLabel;
};