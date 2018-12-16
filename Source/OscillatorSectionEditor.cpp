/*
  ==============================================================================

    OscillatorSectionEditor.cpp
    Created: 6 Nov 2018 2:36:24pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscillatorSectionEditor.h"

//==============================================================================
OscillatorSectionEditor::OscillatorSectionEditor(PatSynthAudioProcessor& p) 
	: processor(p)
{
	frequencySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	frequencySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&frequencySlider);
	frequencySliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdFreq,
		frequencySlider);

	// setup combo box
	oscComboBox.addItem(kMenuItemSineText,   kMenuItemSineId);
	oscComboBox.addItem(kMenuItemSawText,    kMenuItemSawId);
	oscComboBox.addItem(kMenuItemSquareText, kMenuItemSquareId);
	oscComboBox.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscComboBox);
	oscComboBoxAttachment = new ComboBoxAttachment(
		processor.parameters, 
		Globals::paramIdWaveType, 
		oscComboBox);

	// amp attack/decay sliders
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

	// pitch env sliders
	pitchEnvAmountSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	pitchEnvAmountSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&pitchEnvAmountSlider);
	pitchEnvAmountAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdPitchEnvAmount,
		pitchEnvAmountSlider);

	pitchEnvRateSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	pitchEnvRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&pitchEnvRateSlider);
	pitchEnvAmountAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdPitchEnvAmount,
		pitchEnvAmountSlider);

	// pitch lfo sliders
	pitchLfoAmountSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	pitchLfoAmountSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&pitchLfoAmountSlider);
	pitchLfoAmountAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdPitchLfoAmount,
		pitchLfoAmountSlider);

	pitchLfoRateSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	pitchLfoRateSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&pitchLfoRateSlider);
	pitchLfoRateSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdPitchLfoRate,
		pitchLfoRateSlider);
}

OscillatorSectionEditor::~OscillatorSectionEditor()
{
}

void OscillatorSectionEditor::paint (Graphics& g)
{
	g.setColour(Colours::blueviolet);
	g.fillRect(titleArea);

	g.setColour(Colours::white);
	g.drawText("OSC", titleArea, Justification::centred);
}

void OscillatorSectionEditor::resized()
{
	// Update rectangles sizes
	area = getLocalBounds();
	titleArea = area.removeFromTop(kTitleHeight);
	controlsArea = area;
	waveformArea = controlsArea.removeFromTop(kWaveformHeight);
	ampArea = controlsArea.removeFromRight(kAmpWidth);
	modArea = controlsArea.removeFromRight(kModWidth);

	// Add waevform selection combobox
	auto waveformComboBoxArea = waveformArea.removeFromTop(50);
	oscComboBox.setBounds(waveformComboBoxArea);

	// Add frequency slider
	auto frequencySliderArea = waveformArea.removeFromTop(50);
	frequencySlider.setBounds(frequencySliderArea);

	// Add attack/decay sliders
	auto attackSliderArea = ampArea.removeFromLeft(50);
	attackSlider.setBounds(attackSliderArea);
	auto decaySliderArea = ampArea.removeFromLeft(50);
	decaySlider.setBounds(decaySliderArea);

	// add pitch envelope (rotary) sliders
	auto pitchEnvSlidersArea = modArea.removeFromRight(75);
	
	auto pitchEnvDepthArea = pitchEnvSlidersArea.removeFromTop(75);
	pitchEnvAmountSlider.setBounds(pitchEnvDepthArea);
	
	auto pitchEnvRateArea = pitchEnvSlidersArea.removeFromTop(75);
	pitchEnvRateSlider.setBounds(pitchEnvRateArea);

	// add pitch lfo (rotary) sliders
	auto pitchLfoSlidersArea = modArea.removeFromRight(75);

	auto pitchLfoDepthArea = pitchLfoSlidersArea.removeFromTop(75);
	pitchLfoAmountSlider.setBounds(pitchLfoDepthArea);

	auto pitchLfoRateArea = pitchLfoSlidersArea.removeFromTop(75);
	pitchLfoRateSlider.setBounds(pitchLfoRateArea);
}
