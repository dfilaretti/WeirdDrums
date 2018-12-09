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
	// setup filter type combo box
	filterTypeComboBox.addItem(kMenuItemLowPassText,  kMenuItemLowPassId);
	filterTypeComboBox.addItem(kMenuItemHighPassText, kMenuItemHighPassId);
	filterTypeComboBox.addItem(kMenuItemBandPassText, kMenuItemSBandPassId);
	filterTypeComboBox.setJustificationType(Justification::centred);
	addAndMakeVisible(&filterTypeComboBox);
	filterTypeComboBoxAttachment = new ComboBoxAttachment(
		processor.parameters, 
		Globals::paramIdNoiseFilterType, 
		filterTypeComboBox);

	// setup cutoff slider
	filterCutoffSlider.setSliderStyle(Slider::LinearHorizontal);
	filterCutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterCutoffSlider);
	filterCutoffSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdNoiseFilterCutoff,
		filterCutoffSlider);
	//filterCutoffSlider.setSkewFactorFromMidPoint(1000.0); // NB: must be after init the attachment ^^^

	// setup resonance slider
	filterResonanceSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterResonanceSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&filterResonanceSlider);
	filterResonanceSliderAttachment = new SliderAttachment(
		processor.parameters, 
		Globals::paramIdNoiseFilterReso,
		filterResonanceSlider);

	// setup attack slider
	attackSlider.setSliderStyle(Slider::LinearVertical);
	attackSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&attackSlider);
	attackSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdNoiseAttack,
		attackSlider);

	// setup decay slider
	decaySlider.setSliderStyle(Slider::LinearVertical);
	decaySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&decaySlider);
	decaySliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdNoiseDecay,
		decaySlider);
}

NoiseSectionEditor::~NoiseSectionEditor()
{
}

void NoiseSectionEditor::paint (Graphics& g)
{
	g.setColour(Colours::purple);
	g.fillRect(titleArea);

	g.setColour(Colours::white);
	g.drawText("NOISE", titleArea, Justification::centred);
}

void NoiseSectionEditor::resized()
{
	//juce::Rectangle<int> area = getLocalBounds().reduced(40);
	//filterTypeComboBox.setBounds(area.removeFromTop(20));
	//filterCutoffSlider.setBounds(30, 100, 70, 70);
	//filterResonanceSlider.setBounds(100, 100, 70, 70);

	// Update rectangles sizes
	area = getLocalBounds();
	titleArea = area.removeFromTop(kTitleHeight);
	controlsArea = area;
	waveformArea = controlsArea.removeFromTop(kWaveformHeight);
	ampArea = controlsArea.removeFromRight(kAmpWidth);
	miscArea = controlsArea.removeFromRight(kModWidth);

	// Add filter type combobox
	auto filterTypeComboBoxArea = waveformArea.removeFromTop(50);
	filterTypeComboBox.setBounds(filterTypeComboBoxArea);

	// Add frequency slider
	auto frequencySliderArea = waveformArea.removeFromTop(50);
	filterCutoffSlider.setBounds(frequencySliderArea);

	// Add attack/decay sliders
	auto attackSliderArea = ampArea.removeFromLeft(50);
	attackSlider.setBounds(attackSliderArea);
	auto decaySliderArea = ampArea.removeFromLeft(50);
	decaySlider.setBounds(decaySliderArea);

	// add pitch envelope (rotary) sliders
	auto pitchEnvSlidersArea = miscArea.removeFromRight(75);

	// --
	auto pitchLfoSlidersArea = miscArea.removeFromRight(75);

	auto filterResonanceArea = pitchLfoSlidersArea.removeFromTop(75);
	filterResonanceSlider.setBounds(filterResonanceArea);

}
