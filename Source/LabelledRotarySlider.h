/*
  ==============================================================================

    LabelledRotarySlider.h
    Created: 5 Mar 2019 8:38:14am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "LabelledSlider.h"

class LabelledRotarySlider	: public LabelledSlider
{
public:
	LabelledRotarySlider (juce::String label);
	~LabelledRotarySlider();

private:
	const float squeezeFactor { 5 }; // TODO: rename?

	void paint(Graphics&) override;
	void resized() override;
};
