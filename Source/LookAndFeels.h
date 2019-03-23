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
class WdLookAndFeel : public LookAndFeel_V4 
{
public:
	//==============================================================================
	// We currently use a simple 4-colours scheme. Not sure is this is idea, and 
	// not sure if we'll be changing it in future. Let's keep it for the time being.

	Colour colour1; // plugin title, version, author etc.
	Colour colour2; // "dark" colour
	Colour colour3; // "medium" colour
	Colour colour4; // "light" colour

	//==============================================================================
	WdLookAndFeel ()
	{
	}

	//==============================================================================
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

	Font getTextButtonFont(TextButton&, int buttonHeight) override
	{
		return Font(15.0f, Font::bold);
	}

	//==============================================================================
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

	//==============================================================================
	void setTheme1() 
	{
		colour1 = Colours::black;
		colour2 = Colours::black;
		colour3 = Colours::grey;
		colour4 = Colours::lightgrey;
		initColours();
	}

	void setTheme2()
	{
		colour1 = Colour(0xff771bc6);
		colour2 = Colour(0xff771bc6);
		colour3 = Colour(0xfff26ab9);
		colour4 = Colour(0xffffe07a);
		initColours();
	}

	void setTheme3()
	{
		colour1 = Colour(0xff2172ba);
		colour2 = Colour(0xff2172ba);
		colour3 = Colour(0xff2098ba);
		colour4 = Colour(0xff1fbaa8);
		initColours();
	}

	void setTheme4()
	{
		colour1 = Colour(0xff9f4ebf);
		colour2 = Colour(0xff9f4ebf);
		colour3 = Colour(0xff3e9157);
		colour4 = Colour(0xfff4a358);
		initColours();
	}

	void setTheme5()
	{
		colour1 = Colours::darkgrey;
		colour2 = Colours::grey;
		colour3 = Colours::darkgrey;
		colour4 = Colours::lightgrey;
		initColours();
	}

private:
	void initColours()
	{
		setColour(Slider::thumbColourId,          colour2);
		setColour(TextButton::textColourOnId,     colour2);
		setColour(TextButton::textColourOffId,    colour2);
		setColour(Slider::textBoxTextColourId,    colour3);
		setColour(TextButton::buttonColourId,     colour3);
		setColour(Slider::backgroundColourId,     colour4);
		setColour(Label::textColourId,            colour4);
		setColour(Slider::textBoxOutlineColourId, Colours::transparentBlack);
	}
};