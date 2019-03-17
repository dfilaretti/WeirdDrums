/*
  ==============================================================================

    LookAndFeels.h
    Created: 17 Jan 2019 10:08:38pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

/* This is the parent LookAndFeel for the various sections of the instrument. 
   The idea is that this class sets up the various appearance, while derived
   classes will have to set up things like colours etc.

   NB: the drawLinearSlider and drawRotarySlider methods are mostly copy
       of JUCE's builtin versions, with some modifications. 
*/
class LittleTeknoDrummerLookAndFeel : public LookAndFeel_V4 
{
public:
	LittleTeknoDrummerLookAndFeel ()
	{
		setColour(Slider::thumbColourId, Colours::black);
		setColour(Slider::backgroundColourId, Colours::lightgrey);
		setColour(Label::textColourId, Colours::lightgrey);
		setColour(Slider::textBoxOutlineColourId, Colours::transparentBlack);
		setColour(Slider::textBoxTextColourId, Colours::grey);
		setColour(TextButton::buttonColourId, Colours::grey);
		setColour(TextButton::textColourOnId, Colours::black);
		setColour(TextButton::textColourOffId, Colours::black);
	}

	void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour,
		bool isMouseOverButton, bool isButtonDown) override
	{
		auto edge = isMouseOverButton ? 2 : 4;
		auto alpha = isButtonDown ? 0.6f : 1.0f;
		auto buttonArea = button.getLocalBounds().reduced(edge);
		
		g.setColour(backgroundColour.withAlpha(alpha));
		g.fillRoundedRectangle(buttonArea.toFloat(), 4);
	}

	void drawButtonText(Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown) override
	{
		auto font = getTextButtonFont(button, button.getHeight());
		g.setFont(font);
		g.setColour(button.findColour(button.getToggleState() ? TextButton::textColourOnId
			: TextButton::textColourOffId)
			.withMultipliedAlpha(button.isEnabled() ? 1.0f : 0.5f));
		
		auto yIndent = jmin(4, button.proportionOfHeight(0.3f));
		auto cornerSize = jmin(button.getHeight(), button.getWidth()) / 2;
		auto fontHeight = roundToInt(font.getHeight() * 0.6f);
		auto leftIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
		auto rightIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
		auto textWidth = button.getWidth() - leftIndent - rightIndent;
		auto edge = 0;
		auto offset = 0; // isButtonDown ? edge / 2 : 0;
		if (textWidth > 0)
			g.drawFittedText(button.getButtonText(),
				leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
				Justification::centred, 2);
	}

	void drawRotarySlider(Graphics& g,
		int x,
		int y,
		int width,
		int height,
		float sliderPos,
		const float rotaryStartAngle,
		const float rotaryEndAngle,
		Slider& slider) override
	{
		auto radius = jmin(width / 2, height / 2) - 4.0f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + height * 0.5f;

		// draw ellipse (circle)
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;
		g.setColour(slider.findColour(Slider::backgroundColourId));
		g.fillEllipse(rx, ry, rw, rw);

		// outline
		//g.setColour(Colours::grey);
		//g.drawEllipse(rx, ry, rw, rw, 4.0f);

		// draw pointer
		Path p;
		auto pointerLength = radius * 0.60f;
		auto pointerThickness = 8.0f;
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		// pointer
		g.setColour(slider.findColour(Slider::thumbColourId));
		g.fillPath(p);
	}

	Font getTextButtonFont(TextButton&, int buttonHeight) override
	{
		return Font(15.0f, Font::bold);
	}
};