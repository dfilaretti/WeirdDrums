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
		//auto buttonArea = button.getLocalBounds();
		//g.setColour(backgroundColour);
		//g.fillRect(buttonArea);

		auto buttonArea = button.getLocalBounds();
		auto edge = 4;
		buttonArea.removeFromLeft(edge);
		buttonArea.removeFromTop(edge);
		// shadow
		g.setColour(Colours::black);
		g.fillRoundedRectangle (buttonArea.toFloat(), 4);
		auto offset = isButtonDown ? -edge / 2 : -edge;
		buttonArea.translate(offset, offset);
		g.setColour(backgroundColour);
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
		auto edge = 4;
		auto offset = isButtonDown ? edge / 2 : 0;
		if (textWidth > 0)
			g.drawFittedText(button.getButtonText(),
				leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
				Justification::centred, 2);
	}

	Font getTextButtonFont(TextButton&, int buttonHeight) override
	{
		//return { jmin(16.0f, buttonHeight * 0.6f) };
		return Font(15.0f, Font::bold);
	}

	void drawLinearSlider (Graphics&                 g, 
		                   int                       x, 
		                   int                       y, 
		                   int                       width, 
		                   int                       height,
                           float                     sliderPos,
                           float                     minSliderPos,
                           float                     maxSliderPos,
                           const Slider::SliderStyle style, 
		                   Slider&                   slider) override
	{
		if (slider.isBar())
		{
			g.setColour (slider.findColour (Slider::trackColourId));
			g.fillRect (slider.isHorizontal() ? Rectangle<float> (static_cast<float> (x), y + 0.5f, sliderPos - x, height - 1.0f)
											  : Rectangle<float> (x + 0.5f, sliderPos, width - 1.0f, y + (height - sliderPos)));
		}
		else
		{
			auto isTwoVal   = (style == Slider::SliderStyle::TwoValueVertical   || style == Slider::SliderStyle::TwoValueHorizontal);
			auto isThreeVal = (style == Slider::SliderStyle::ThreeValueVertical || style == Slider::SliderStyle::ThreeValueHorizontal);

			auto trackWidth = jmin (6.0f, slider.isHorizontal() ? height * 0.25f : width * 0.25f) * 1.3f;

			Point<float> startPoint (slider.isHorizontal() ? x : x + width * 0.5f,
									 slider.isHorizontal() ? y + height * 0.5f : height + y);

			Point<float> endPoint (slider.isHorizontal() ? width + x : startPoint.x,
								   slider.isHorizontal() ? startPoint.y : y);

			Path backgroundTrack;
			backgroundTrack.startNewSubPath (startPoint);
			backgroundTrack.lineTo (endPoint);
			g.setColour (slider.findColour (Slider::backgroundColourId));
			g.strokePath (backgroundTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

			Path valueTrack;
			Point<float> minPoint, maxPoint, thumbPoint;

			if (isTwoVal || isThreeVal)
			{
				minPoint = { slider.isHorizontal() ? minSliderPos : width * 0.5f,
							 slider.isHorizontal() ? height * 0.5f : minSliderPos };

				if (isThreeVal)
					thumbPoint = { slider.isHorizontal() ? sliderPos : width * 0.5f,
								   slider.isHorizontal() ? height * 0.5f : sliderPos };

				maxPoint = { slider.isHorizontal() ? maxSliderPos : width * 0.5f,
							 slider.isHorizontal() ? height * 0.5f : maxSliderPos };
			}
			else
			{
				auto kx = slider.isHorizontal() ? sliderPos : (x + width * 0.5f);
				auto ky = slider.isHorizontal() ? (y + height * 0.5f) : sliderPos;

				minPoint = startPoint;
				maxPoint = { kx, ky };
			}

			auto thumbWidth = getSliderThumbRadius (slider) * 0.5;

			valueTrack.startNewSubPath (minPoint);
			valueTrack.lineTo (isThreeVal ? thumbPoint : maxPoint);
			g.setColour (slider.findColour (Slider::trackColourId));
			g.strokePath (valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

			if (! isTwoVal)
			{
				g.setColour (slider.findColour (Slider::thumbColourId));
				g.fillEllipse (Rectangle<float> (static_cast<float> (thumbWidth), static_cast<float> (thumbWidth)).withCentre (isThreeVal ? thumbPoint : maxPoint));
			}

			if (isTwoVal || isThreeVal)
			{
				auto sr = jmin (trackWidth, (slider.isHorizontal() ? height : width) * 0.4f);
				auto pointerColour = slider.findColour (Slider::thumbColourId);

				if (slider.isHorizontal())
				{
					drawPointer (g, minSliderPos - sr,
								 jmax (0.0f, y + height * 0.5f - trackWidth * 2.0f),
								 trackWidth * 2.0f, pointerColour, 2);

					drawPointer (g, maxSliderPos - trackWidth,
								 jmin (y + height - trackWidth * 2.0f, y + height * 0.5f),
								 trackWidth * 2.0f, pointerColour, 4);
				}
				else
				{
					drawPointer (g, jmax (0.0f, x + width * 0.5f - trackWidth * 2.0f),
								 minSliderPos - trackWidth,
								 trackWidth * 2.0f, pointerColour, 1);

					drawPointer (g, jmin (x + width - trackWidth * 2.0f, x + width * 0.5f), maxSliderPos - sr,
								 trackWidth * 2.0f, pointerColour, 3);
				}
			}
		}
	}

	/*void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{
		auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
		auto fill    = slider.findColour (Slider::rotarySliderFillColourId);

		auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

		auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
		auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		auto lineW = jmin (8.0f, radius * 0.5f);
		auto arcRadius = radius - lineW * 0.5f;

		Path backgroundArc;
		backgroundArc.addCentredArc (bounds.getCentreX(),
									 bounds.getCentreY(),
									 arcRadius,
									 arcRadius,
									 0.0f,
									 rotaryStartAngle,
									 rotaryEndAngle,
									 true);

		g.setColour (outline);
		g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

		if (slider.isEnabled())
		{
			Path valueArc;
			valueArc.addCentredArc (bounds.getCentreX(),
									bounds.getCentreY(),
									arcRadius,
									arcRadius,
									0.0f,
									rotaryStartAngle,
									toAngle,
									true);

			g.setColour (fill);
			g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
		}

		auto thumbWidth = lineW * 0.8f;
		Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
								 bounds.getCentreY() + arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));

		g.setColour (slider.findColour (Slider::thumbColourId));
		g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
	}*/

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
		//g.setColour(Colours::red);
		//g.drawEllipse(rx, ry, rw, rw, 1.0f);

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

};

//==============================================================================
//class OscSectionLookAndFeel : public LittleTeknoDrummerLookAndFeel 
//{
//public:
//    OscSectionLookAndFeel()
//    {
//    }
//};
//
//class NoiseSectionLookAndFeel : public LittleTeknoDrummerLookAndFeel 
//{
//public:
//    NoiseSectionLookAndFeel()
//    {
//    }
//};
//
//class MasterSectionLookAndFeel : public LittleTeknoDrummerLookAndFeel 
//{
//public:
//    MasterSectionLookAndFeel()
//    {
//    }
//};