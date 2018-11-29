/*
  ==============================================================================

    MasterSectionEditor.cpp
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MasterSectionEditor.h"

//==============================================================================
MasterSectionEditor::MasterSectionEditor(PatSynthAudioProcessor& p) : 
	processor (p)
{
	// mix slider
	mixSlider.setSliderStyle(Slider::LinearHorizontal);
	mixSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&mixSlider);
	mixSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterMix,
		mixSlider);

	// eq freq slider
	eqFreqSlider.setSliderStyle(Slider::LinearHorizontal);
	eqFreqSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&eqFreqSlider);
	eqFreqSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterEqFreq,
		eqFreqSlider);
	
	// distort (rotary) slider
	distortSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	distortSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&distortSlider);
	distortSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterDistort,
		distortSlider);

	// eq gain (rotary) slider
	eqGainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	eqGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&eqGainSlider);
	eqGainSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterEqGain,
		eqGainSlider);

	// level (rotary) slider
	levelSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	levelSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&levelSlider);
	levelSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterLevel,
		levelSlider);

	// pan (rotary) slider
	panSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	panSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(&panSlider);
	panSliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdMasterPan,
		panSlider);
}

MasterSectionEditor::~MasterSectionEditor()
{
}

void MasterSectionEditor::paint (Graphics& g)
{
	g.setColour(Colours::darkseagreen);
	g.fillRect(titleArea);

	g.setColour(Colours::white);
	g.drawText("MASTER", titleArea, Justification::centred);
}

void MasterSectionEditor::resized()
{
	// Update rectangles sizes
	area = getLocalBounds();
	titleArea = area.removeFromTop(kTitleHeight);
	controlsArea = area;
	waveformArea = controlsArea.removeFromTop(kWaveformHeight);
	ampArea = controlsArea.removeFromRight(kAmpWidth);
	miscArea = controlsArea.removeFromRight(kModWidth);

	// --
	auto mixSliderArea = waveformArea.removeFromTop(50);
	mixSlider.setBounds(mixSliderArea);

	// --
	auto eqFreqSliderArea = waveformArea.removeFromTop(50);
	eqFreqSlider.setBounds(eqFreqSliderArea);

	// --
	auto eqGainAndPanlidersArea = miscArea.removeFromRight(75);

	auto eqGainSliderArea = eqGainAndPanlidersArea.removeFromTop(75);
	eqGainSlider.setBounds(eqGainSliderArea);

	auto panSliderArea = eqGainAndPanlidersArea.removeFromTop(75);
	panSlider.setBounds(panSliderArea);

	// ---
	auto pitchLfoSlidersArea = miscArea.removeFromRight(75);

	auto filterResonanceArea = pitchLfoSlidersArea.removeFromTop(75);
	distortSlider.setBounds(filterResonanceArea);

	auto levelArea = pitchLfoSlidersArea.removeFromTop(75);
	levelSlider.setBounds(levelArea);
}
