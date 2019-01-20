/*
  ==============================================================================

    LookAndFeels.h
    Created: 17 Jan 2019 10:08:38pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class LittleDrumSynthLookAndFeel : public LookAndFeel_V4 
{
public:
	LittleDrumSynthLookAndFeel ()
	{
		// thumb
        setColour (Slider::thumbColourId, Colours::grey);
        
		// fill
		setColour (Slider::trackColourId, Colours::white);
        setColour (Slider::ColourIds::rotarySliderFillColourId, Colours::white);

	}


	void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style, Slider& slider) override
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

	void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
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
	}

};

class OscSectionLookAndFeel : public LittleDrumSynthLookAndFeel 
{
public:
    OscSectionLookAndFeel()
    {
        auto col = Colours::lightcyan;
		setColour (Slider::trackColourId, col);
		setColour (Slider::ColourIds::rotarySliderFillColourId, col);
    }
};

class NoiseSectionLookAndFeel : public LittleDrumSynthLookAndFeel 
{
public:
    NoiseSectionLookAndFeel()
    {
		auto col = Colours::lightgreen;
		setColour (Slider::trackColourId, col);
		setColour (Slider::ColourIds::rotarySliderFillColourId, col);
    }
};

class MasterSectionLookAndFeel : public LittleDrumSynthLookAndFeel 
{
public:
    MasterSectionLookAndFeel()
    {
        auto col = Colours::lightpink;
		setColour (Slider::trackColourId, col);
		setColour (Slider::ColourIds::rotarySliderFillColourId, col);
    }
};