/*
  ==============================================================================

    LtdRotarySlider.h
    Created: 5 Mar 2019 8:38:14am
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "LtdSlider.h"
//#include "../JuceLibraryCode/JuceHeader.h"

class LtdRotarySlider	: public LtdSlider
{
public:
	LtdRotarySlider (juce::String label);
	~LtdRotarySlider();

private:
	void paint(Graphics&) override;
	void resized() override;
};
