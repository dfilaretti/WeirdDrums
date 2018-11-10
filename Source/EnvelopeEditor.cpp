/*
  ==============================================================================

    EnvelopeEditor.cpp
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "EnvelopeEditor.h"

//==============================================================================
EnvelopeEditor::EnvelopeEditor(PatSynthAudioProcessor& p) : 
	processor (p)
{
	setSize(kWidth, kHeight);

	attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&attackSlider);
	attackSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdAttack, 
		attackSlider);

	decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	decaySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&decaySlider);
	decaySliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdDecay,
		decaySlider);

	sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	sustainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&sustainSlider);
	sustainSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdSustain,
		sustainSlider);

	releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	releaseSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&releaseSlider);
	releaseSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdRelease,
		releaseSlider);
}

EnvelopeEditor::~EnvelopeEditor()
{
}

void EnvelopeEditor::paint (Graphics& g)
{
	//fancy stuff for the UI background etc
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

	g.fillAll(Colours::black);
	g.setColour(Colours::white);
	g.drawText("Envelope", titleArea, Justification::centredTop);

	//static positioning for now due to time, make dynamic later
	g.drawText("A", 53, 150, 20, 20, Justification::centredTop);
	g.drawText("D", 77, 150, 20, 20, Justification::centredTop);
	g.drawText("S", 103, 150, 20, 20, Justification::centredTop);
	g.drawText("R", 128, 150, 20, 20, Justification::centredTop);

	juce::Rectangle <float> area(25, 25, 150, 150);

	g.setColour(Colours::yellow);
	g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void EnvelopeEditor::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(50);

	attackSlider.setBounds(area.removeFromLeft(kSliderWidth).removeFromTop(kSliderHeight).withTrimmedTop(10));
	decaySlider.setBounds(area.removeFromLeft(kSliderWidth).removeFromTop(kSliderHeight).withTrimmedTop(10));
	sustainSlider.setBounds(area.removeFromLeft(kSliderWidth).removeFromTop(kSliderHeight).withTrimmedTop(10));
	releaseSlider.setBounds(area.removeFromLeft(kSliderWidth).removeFromTop(kSliderHeight).withTrimmedTop(10));
}
