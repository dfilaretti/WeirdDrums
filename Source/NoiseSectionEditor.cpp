/*
  ==============================================================================

    NoiseSectionEditor.cpp
    Created: 6 Nov 2018 4:44:43pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoiseSectionEditor.h"

//==============================================================================
NoiseSectionEditor::NoiseSectionEditor(PatSynthAudioProcessor& p) :
	processor(p)
{
	// setup size
	setSize(kWidth, kHeight);

	// setup filter type combo box
	filterTypeComboBox.addItem(kMenuItemLowPassText,  kMenuItemLowPassId);
	filterTypeComboBox.addItem(kMenuItemHighPassText, kMenuItemHighPassId);
	filterTypeComboBox.addItem(kMenuItemBandPassText, kMenuItemSBandPassId);
	filterTypeComboBox.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterTypeComboBox);
	filterTypeComboBoxAttachment = new ComboBoxAttachment(
		processor.parameters, 
		Globals::paramIdFilterType, 
		filterTypeComboBox);

	// setup cutoff slider
	filterCutoffSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterCutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterCutoffSlider);
	filterCutoffSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdFilterCutoff,
		filterCutoffSlider);
	filterCutoffSlider.setSkewFactorFromMidPoint(1000.0); // NB: must be after init the attachment ^^^

	// setup resonance slider
	filterResonanceSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterResonanceSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterResonanceSlider);
	filterResonanceSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdFilterReso,
		filterResonanceSlider);
}

NoiseSectionEditor::~NoiseSectionEditor()
{
}

void NoiseSectionEditor::paint (Graphics& g)
{
	juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);
	g.fillAll(Colours::black);
	g.setColour(Colours::white);
	g.drawText("Noise", titleArea, Justification::centredTop);

	juce::Rectangle<float> area (25, 25, 150, 150);
	g.setColour(Colours::yellow);
	g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void NoiseSectionEditor::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(40);
	filterTypeComboBox.setBounds(area.removeFromTop(20));
	filterCutoffSlider.setBounds(30, 100, 70, 70);
	filterResonanceSlider.setBounds(100, 100, 70, 70);
}
