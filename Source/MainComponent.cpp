/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (PatSynthAudioProcessor& p)
    : processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("OSCILLATOR")));
    addAndMakeVisible (groupComponent.get());
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xff57ff00));

    groupComponent->setBounds (16, 40, 352, 280);

    groupComponent2.reset (new GroupComponent ("new group",
                                               TRANS("NOISE")));
    addAndMakeVisible (groupComponent2.get());
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0xffff00b5));

    groupComponent2->setBounds (375, 39, 312, 185);

    oscComboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (oscComboBox.get());
    oscComboBox->setEditableText (false);
    oscComboBox->setJustificationType (Justification::centredLeft);
    oscComboBox->setTextWhenNothingSelected (String());
    oscComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    oscComboBox->addItem (TRANS("Sine"), 1);
    oscComboBox->addItem (TRANS("Saw"), 2);
    oscComboBox->addItem (TRANS("Square"), 3);
    oscComboBox->addListener (this);

    oscComboBox->setBounds (168, 64, 136, 24);

    oscWaveformLabel.reset (new Label ("new label",
                                       TRANS("WAVEFORM")));
    addAndMakeVisible (oscWaveformLabel.get());
    oscWaveformLabel->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel->setJustificationType (Justification::centredLeft);
    oscWaveformLabel->setEditable (false, false, false);
    oscWaveformLabel->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel->setBounds (32, 64, 96, 24);

    pitchEnvAmountSlider.reset (new Slider ("pitchEnvAmountSlider"));
    addAndMakeVisible (pitchEnvAmountSlider.get());
    pitchEnvAmountSlider->setRange (0, 10, 0);
    pitchEnvAmountSlider->setSliderStyle (Slider::LinearHorizontal);
    pitchEnvAmountSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    pitchEnvAmountSlider->setBounds (160, 192, 192, 24);

    oscWaveformLabel2.reset (new Label ("new label",
                                        TRANS("FREQUENCY")));
    addAndMakeVisible (oscWaveformLabel2.get());
    oscWaveformLabel2->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel2->setJustificationType (Justification::centredLeft);
    oscWaveformLabel2->setEditable (false, false, false);
    oscWaveformLabel2->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel2->setBounds (32, 96, 104, 24);

    pitchEnvRateSlider.reset (new Slider ("pitchEnvRateSlider"));
    addAndMakeVisible (pitchEnvRateSlider.get());
    pitchEnvRateSlider->setRange (0, 10, 0);
    pitchEnvRateSlider->setSliderStyle (Slider::LinearHorizontal);
    pitchEnvRateSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    pitchEnvRateSlider->setBounds (160, 224, 192, 24);

    oscWaveformLabel3.reset (new Label ("new label",
                                        TRANS("LFO DEPTH")));
    addAndMakeVisible (oscWaveformLabel3.get());
    oscWaveformLabel3->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel3->setJustificationType (Justification::centredLeft);
    oscWaveformLabel3->setEditable (false, false, false);
    oscWaveformLabel3->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel3->setBounds (32, 128, 104, 24);

    pitchLfoRateSlider.reset (new Slider ("pitchLfoRateSlider"));
    addAndMakeVisible (pitchLfoRateSlider.get());
    pitchLfoRateSlider->setRange (0, 10, 0);
    pitchLfoRateSlider->setSliderStyle (Slider::LinearHorizontal);
    pitchLfoRateSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    pitchLfoRateSlider->setBounds (160, 160, 192, 24);

    oscWaveformLabel4.reset (new Label ("new label",
                                        TRANS("LFO RATE")));
    addAndMakeVisible (oscWaveformLabel4.get());
    oscWaveformLabel4->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel4->setJustificationType (Justification::centredLeft);
    oscWaveformLabel4->setEditable (false, false, false);
    oscWaveformLabel4->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel4->setBounds (32, 160, 104, 24);

    pitchLfoAmountSlider.reset (new Slider ("pitchLfoAmountSlider"));
    addAndMakeVisible (pitchLfoAmountSlider.get());
    pitchLfoAmountSlider->setRange (0, 10, 0);
    pitchLfoAmountSlider->setSliderStyle (Slider::LinearHorizontal);
    pitchLfoAmountSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    pitchLfoAmountSlider->setBounds (160, 128, 192, 24);

    oscWaveformLabel5.reset (new Label ("new label",
                                        TRANS("PCH ENV DEPTH")));
    addAndMakeVisible (oscWaveformLabel5.get());
    oscWaveformLabel5->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel5->setJustificationType (Justification::centredLeft);
    oscWaveformLabel5->setEditable (false, false, false);
    oscWaveformLabel5->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel5->setBounds (32, 192, 120, 24);

    oscWaveformLabel6.reset (new Label ("new label",
                                        TRANS("PCH ENV RATE")));
    addAndMakeVisible (oscWaveformLabel6.get());
    oscWaveformLabel6->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel6->setJustificationType (Justification::centredLeft);
    oscWaveformLabel6->setEditable (false, false, false);
    oscWaveformLabel6->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel6->setBounds (32, 224, 120, 24);

    frequencySlider.reset (new Slider ("frequencySlider"));
    addAndMakeVisible (frequencySlider.get());
    frequencySlider->setRange (0, 10, 0);
    frequencySlider->setSliderStyle (Slider::LinearHorizontal);
    frequencySlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    frequencySlider->addListener (this);

    frequencySlider->setBounds (160, 96, 192, 24);

    oscAttackSlider.reset (new Slider ("oscAttackSlider"));
    addAndMakeVisible (oscAttackSlider.get());
    oscAttackSlider->setRange (0, 10, 0);
    oscAttackSlider->setSliderStyle (Slider::LinearHorizontal);
    oscAttackSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    oscAttackSlider->setBounds (160, 256, 192, 24);

    oscWaveformLabel9.reset (new Label ("new label",
                                        TRANS("ATTACK\n")));
    addAndMakeVisible (oscWaveformLabel9.get());
    oscWaveformLabel9->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel9->setJustificationType (Justification::centredLeft);
    oscWaveformLabel9->setEditable (false, false, false);
    oscWaveformLabel9->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel9->setBounds (32, 256, 120, 24);

    oscDecaySlider.reset (new Slider ("oscDecaySlider"));
    addAndMakeVisible (oscDecaySlider.get());
    oscDecaySlider->setRange (0, 10, 0);
    oscDecaySlider->setSliderStyle (Slider::LinearHorizontal);
    oscDecaySlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);

    oscDecaySlider->setBounds (160, 288, 192, 24);

    oscWaveformLabel10.reset (new Label ("new label",
                                         TRANS("DECAY")));
    addAndMakeVisible (oscWaveformLabel10.get());
    oscWaveformLabel10->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel10->setJustificationType (Justification::centredLeft);
    oscWaveformLabel10->setEditable (false, false, false);
    oscWaveformLabel10->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel10->setBounds (32, 288, 120, 24);

    filterTypeComboBox.reset (new ComboBox ("filterTypeComboBox"));
    addAndMakeVisible (filterTypeComboBox.get());
    filterTypeComboBox->setEditableText (false);
    filterTypeComboBox->setJustificationType (Justification::centredLeft);
    filterTypeComboBox->setTextWhenNothingSelected (String());
    filterTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filterTypeComboBox->addItem (TRANS("LO PASS"), 1);
    filterTypeComboBox->addItem (TRANS("HI PASS"), 2);
    filterTypeComboBox->addItem (TRANS("BAND PASS"), 3);
    filterTypeComboBox->addListener (this);

    filterTypeComboBox->setBounds (527, 63, 136, 24);

    oscWaveformLabel7.reset (new Label ("new label",
                                        TRANS("FILTER TYPE")));
    addAndMakeVisible (oscWaveformLabel7.get());
    oscWaveformLabel7->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel7->setJustificationType (Justification::centredLeft);
    oscWaveformLabel7->setEditable (false, false, false);
    oscWaveformLabel7->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel7->setBounds (391, 63, 96, 24);

    noiseDecaySlider.reset (new Slider ("decaySlider"));
    addAndMakeVisible (noiseDecaySlider.get());
    noiseDecaySlider->setRange (0, 10, 0);
    noiseDecaySlider->setSliderStyle (Slider::LinearHorizontal);
    noiseDecaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    noiseDecaySlider->setBounds (519, 191, 150, 24);

    oscWaveformLabel8.reset (new Label ("new label",
                                        TRANS("CUTOFF")));
    addAndMakeVisible (oscWaveformLabel8.get());
    oscWaveformLabel8->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel8->setJustificationType (Justification::centredLeft);
    oscWaveformLabel8->setEditable (false, false, false);
    oscWaveformLabel8->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel8->setBounds (391, 95, 104, 24);

    oscWaveformLabel11.reset (new Label ("new label",
                                         TRANS("RESONANCE")));
    addAndMakeVisible (oscWaveformLabel11.get());
    oscWaveformLabel11->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel11->setJustificationType (Justification::centredLeft);
    oscWaveformLabel11->setEditable (false, false, false);
    oscWaveformLabel11->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel11->setBounds (391, 127, 104, 24);

    noiseAttackSlider.reset (new Slider ("noiseAttackSlider"));
    addAndMakeVisible (noiseAttackSlider.get());
    noiseAttackSlider->setRange (0, 10, 0);
    noiseAttackSlider->setSliderStyle (Slider::LinearHorizontal);
    noiseAttackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    noiseAttackSlider->setBounds (519, 159, 150, 24);

    oscWaveformLabel12.reset (new Label ("new label",
                                         TRANS("ATTACK\n")));
    addAndMakeVisible (oscWaveformLabel12.get());
    oscWaveformLabel12->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel12->setJustificationType (Justification::centredLeft);
    oscWaveformLabel12->setEditable (false, false, false);
    oscWaveformLabel12->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel12->setBounds (391, 159, 104, 24);

    filterResonanceSlider.reset (new Slider ("filterResonanceSlider"));
    addAndMakeVisible (filterResonanceSlider.get());
    filterResonanceSlider->setRange (0, 10, 0);
    filterResonanceSlider->setSliderStyle (Slider::LinearHorizontal);
    filterResonanceSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    filterResonanceSlider->setBounds (519, 127, 150, 24);

    oscWaveformLabel13.reset (new Label ("new label",
                                         TRANS("DECAY")));
    addAndMakeVisible (oscWaveformLabel13.get());
    oscWaveformLabel13->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel13->setJustificationType (Justification::centredLeft);
    oscWaveformLabel13->setEditable (false, false, false);
    oscWaveformLabel13->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel13->setBounds (391, 191, 120, 24);

    filterCutoffSlider.reset (new Slider ("filterCutoffSlider"));
    addAndMakeVisible (filterCutoffSlider.get());
    filterCutoffSlider->setRange (0, 10, 0);
    filterCutoffSlider->setSliderStyle (Slider::LinearHorizontal);
    filterCutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    filterCutoffSlider->setBounds (519, 95, 150, 24);

    groupComponent3.reset (new GroupComponent ("new group",
                                               TRANS("MASTER")));
    addAndMakeVisible (groupComponent3.get());
    groupComponent3->setColour (GroupComponent::outlineColourId, Colour (0xff00d7ff));

    groupComponent3->setBounds (376, 232, 312, 224);

    distortSlider.reset (new Slider ("distortSlider"));
    addAndMakeVisible (distortSlider.get());
    distortSlider->setRange (0, 10, 0);
    distortSlider->setSliderStyle (Slider::LinearHorizontal);
    distortSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    distortSlider->setBounds (520, 360, 150, 24);

    oscWaveformLabel15.reset (new Label ("new label",
                                         TRANS("MIX")));
    addAndMakeVisible (oscWaveformLabel15.get());
    oscWaveformLabel15->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel15->setJustificationType (Justification::centredLeft);
    oscWaveformLabel15->setEditable (false, false, false);
    oscWaveformLabel15->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel15->setBounds (392, 264, 104, 24);

    oscWaveformLabel16.reset (new Label ("new label",
                                         TRANS("EQ FREQ")));
    addAndMakeVisible (oscWaveformLabel16.get());
    oscWaveformLabel16->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel16->setJustificationType (Justification::centredLeft);
    oscWaveformLabel16->setEditable (false, false, false);
    oscWaveformLabel16->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel16->setBounds (392, 296, 104, 24);

    eqGainSlider.reset (new Slider ("eqGainSlider"));
    addAndMakeVisible (eqGainSlider.get());
    eqGainSlider->setRange (0, 10, 0);
    eqGainSlider->setSliderStyle (Slider::LinearHorizontal);
    eqGainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    eqGainSlider->setBounds (520, 328, 150, 24);

    oscWaveformLabel17.reset (new Label ("new label",
                                         TRANS("EQ GAIN")));
    addAndMakeVisible (oscWaveformLabel17.get());
    oscWaveformLabel17->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel17->setJustificationType (Justification::centredLeft);
    oscWaveformLabel17->setEditable (false, false, false);
    oscWaveformLabel17->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel17->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel17->setBounds (392, 328, 104, 24);

    eqFreqSlider.reset (new Slider ("eqFreqSlider"));
    addAndMakeVisible (eqFreqSlider.get());
    eqFreqSlider->setRange (0, 10, 0);
    eqFreqSlider->setSliderStyle (Slider::LinearHorizontal);
    eqFreqSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    eqFreqSlider->setBounds (520, 296, 150, 24);

    oscWaveformLabel18.reset (new Label ("new label",
                                         TRANS("DISTORT")));
    addAndMakeVisible (oscWaveformLabel18.get());
    oscWaveformLabel18->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel18->setJustificationType (Justification::centredLeft);
    oscWaveformLabel18->setEditable (false, false, false);
    oscWaveformLabel18->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel18->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel18->setBounds (392, 360, 120, 24);

    mixSlider.reset (new Slider ("mixSlider"));
    addAndMakeVisible (mixSlider.get());
    mixSlider->setRange (0, 10, 0);
    mixSlider->setSliderStyle (Slider::LinearHorizontal);
    mixSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    mixSlider->setBounds (520, 264, 150, 24);

    panSlider.reset (new Slider ("panSlider"));
    addAndMakeVisible (panSlider.get());
    panSlider->setRange (0, 10, 0);
    panSlider->setSliderStyle (Slider::LinearHorizontal);
    panSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    panSlider->setBounds (520, 392, 150, 24);

    oscWaveformLabel14.reset (new Label ("new label",
                                         TRANS("PAN")));
    addAndMakeVisible (oscWaveformLabel14.get());
    oscWaveformLabel14->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel14->setJustificationType (Justification::centredLeft);
    oscWaveformLabel14->setEditable (false, false, false);
    oscWaveformLabel14->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel14->setBounds (392, 392, 120, 24);

    levelSlider.reset (new Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 10, 0);
    levelSlider->setSliderStyle (Slider::LinearHorizontal);
    levelSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);

    levelSlider->setBounds (520, 424, 150, 24);

    oscWaveformLabel19.reset (new Label ("new label",
                                         TRANS("LEVEL")));
    addAndMakeVisible (oscWaveformLabel19.get());
    oscWaveformLabel19->setFont (Font ("Bahnschrift", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    oscWaveformLabel19->setJustificationType (Justification::centredLeft);
    oscWaveformLabel19->setEditable (false, false, false);
    oscWaveformLabel19->setColour (TextEditor::textColourId, Colours::black);
    oscWaveformLabel19->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    oscWaveformLabel19->setBounds (392, 424, 120, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 500);


    //[Constructor] You can add your own custom stuff here..
	// MASTER
	//mixSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterMix,
	//	*mixSlider);

	//eqFreqSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterEqFreq,
	//	*eqFreqSlider);

	//distortSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterDistort,
	//	*distortSlider);

	//eqGainSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterEqGain,
	//	*eqGainSlider);

	//levelSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterLevel,
	//	*levelSlider);

	//panSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdMasterPan,
	//	*panSlider);

	//// OSC

	frequencySliderAttachment = new SliderAttachment(
		processor.parameters,
		Globals::paramIdFreq,
		*frequencySlider);

	//oscComboBoxAttachment = new ComboBoxAttachment(
	//	processor.parameters,
	//	Globals::paramIdWaveType,
	//	*oscComboBox);

	//oscAttackSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdAttack,
	//	*oscAttackSlider);

	//oscDecaySliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdDecay,
	//	*oscDecaySlider);

	//pitchEnvAmountAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdPitchEnvAmount,
	//	*pitchEnvAmountSlider);

	//pitchEnvRateSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdPitchEnvRate,
	//	*pitchEnvRateSlider);

	//pitchLfoAmountAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdPitchLfoAmount,
	//	*pitchLfoAmountSlider);

	//pitchLfoRateSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdPitchLfoRate,
	//	*pitchLfoRateSlider);

	//// NOISE

	//filterTypeComboBoxAttachment = new ComboBoxAttachment(
	//	processor.parameters,
	//	Globals::paramIdNoiseFilterType,
	//	*filterTypeComboBox);

	//filterCutoffSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdNoiseFilterCutoff,
	//	*filterCutoffSlider);

	//filterResonanceSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdNoiseFilterReso,
	//	*filterResonanceSlider);

	//noiseAttackSliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdNoiseAttack,
	//	*noiseAttackSlider);

	//noiseDecaySliderAttachment = new SliderAttachment(
	//	processor.parameters,
	//	Globals::paramIdNoiseDecay,
	//	*noiseDecaySlider);


    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    groupComponent2 = nullptr;
    oscComboBox = nullptr;
    oscWaveformLabel = nullptr;
    pitchEnvAmountSlider = nullptr;
    oscWaveformLabel2 = nullptr;
    pitchEnvRateSlider = nullptr;
    oscWaveformLabel3 = nullptr;
    pitchLfoRateSlider = nullptr;
    oscWaveformLabel4 = nullptr;
    pitchLfoAmountSlider = nullptr;
    oscWaveformLabel5 = nullptr;
    oscWaveformLabel6 = nullptr;
    frequencySlider = nullptr;
    oscAttackSlider = nullptr;
    oscWaveformLabel9 = nullptr;
    oscDecaySlider = nullptr;
    oscWaveformLabel10 = nullptr;
    filterTypeComboBox = nullptr;
    oscWaveformLabel7 = nullptr;
    noiseDecaySlider = nullptr;
    oscWaveformLabel8 = nullptr;
    oscWaveformLabel11 = nullptr;
    noiseAttackSlider = nullptr;
    oscWaveformLabel12 = nullptr;
    filterResonanceSlider = nullptr;
    oscWaveformLabel13 = nullptr;
    filterCutoffSlider = nullptr;
    groupComponent3 = nullptr;
    distortSlider = nullptr;
    oscWaveformLabel15 = nullptr;
    oscWaveformLabel16 = nullptr;
    eqGainSlider = nullptr;
    oscWaveformLabel17 = nullptr;
    eqFreqSlider = nullptr;
    oscWaveformLabel18 = nullptr;
    mixSlider = nullptr;
    panSlider = nullptr;
    oscWaveformLabel14 = nullptr;
    levelSlider = nullptr;
    oscWaveformLabel19 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff272626));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == oscComboBox.get())
    {
        //[UserComboBoxCode_oscComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_oscComboBox]
    }
    else if (comboBoxThatHasChanged == filterTypeComboBox.get())
    {
        //[UserComboBoxCode_filterTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_filterTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == frequencySlider.get())
    {
        //[UserSliderCode_frequencySlider] -- add your slider handling code here..
        //[/UserSliderCode_frequencySlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="PatSynthAudioProcessor&amp; p"
                 variableInitialisers="processor (p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="700"
                 initialHeight="500">
  <BACKGROUND backgroundColour="ff272626"/>
  <GROUPCOMPONENT name="new group" id="f1ec165b1b1c7225" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="16 40 352 280" outlinecol="ff57ff00"
                  title="OSCILLATOR"/>
  <GROUPCOMPONENT name="new group" id="c03a6ea20eb588c7" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="375 39 312 185" outlinecol="ffff00b5"
                  title="NOISE"/>
  <COMBOBOX name="new combo box" id="dfa8498bc4c4bef" memberName="oscComboBox"
            virtualName="" explicitFocusOrder="0" pos="168 64 136 24" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="766465f79403a06c" memberName="oscWaveformLabel"
         virtualName="" explicitFocusOrder="0" pos="32 64 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="WAVEFORM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchEnvAmountSlider" id="b1fbacdeee652f82" memberName="pitchEnvAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="160 192 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="54d06a0380503b21" memberName="oscWaveformLabel2"
         virtualName="" explicitFocusOrder="0" pos="32 96 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FREQUENCY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchEnvRateSlider" id="6e91a614842c11ed" memberName="pitchEnvRateSlider"
          virtualName="" explicitFocusOrder="0" pos="160 224 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="74bd9a7cb2a9c38e" memberName="oscWaveformLabel3"
         virtualName="" explicitFocusOrder="0" pos="32 128 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO DEPTH" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchLfoRateSlider" id="3e75c3ada42c79ee" memberName="pitchLfoRateSlider"
          virtualName="" explicitFocusOrder="0" pos="160 160 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="ce871c2dff2a7e88" memberName="oscWaveformLabel4"
         virtualName="" explicitFocusOrder="0" pos="32 160 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO RATE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchLfoAmountSlider" id="d8bdb24720fa96f2" memberName="pitchLfoAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="160 128 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="333c2fc5856506f0" memberName="oscWaveformLabel5"
         virtualName="" explicitFocusOrder="0" pos="32 192 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PCH ENV DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bahnschrift"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6d66b0ebadd0a3dc" memberName="oscWaveformLabel6"
         virtualName="" explicitFocusOrder="0" pos="32 224 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PCH ENV RATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bahnschrift"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="frequencySlider" id="2c624ebe710e897b" memberName="frequencySlider"
          virtualName="" explicitFocusOrder="0" pos="160 96 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="oscAttackSlider" id="7450b06b6e079686" memberName="oscAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="160 256 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="d79170e86d05d168" memberName="oscWaveformLabel9"
         virtualName="" explicitFocusOrder="0" pos="32 256 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ATTACK&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bahnschrift"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="oscDecaySlider" id="247b7616819a9caa" memberName="oscDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="160 288 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="6bd6fbbec9efcaae" memberName="oscWaveformLabel10"
         virtualName="" explicitFocusOrder="0" pos="32 288 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="DECAY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="filterTypeComboBox" id="ef03293bcf4c4035" memberName="filterTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="527 63 136 24" editable="0"
            layout="33" items="LO PASS&#10;HI PASS&#10;BAND PASS" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="89546058362ef0f" memberName="oscWaveformLabel7"
         virtualName="" explicitFocusOrder="0" pos="391 63 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FILTER TYPE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bahnschrift"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="decaySlider" id="7fe635dfe4073fc0" memberName="noiseDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="519 191 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="4a4b426864d21ae3" memberName="oscWaveformLabel8"
         virtualName="" explicitFocusOrder="0" pos="391 95 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="CUTOFF" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ecfd26a0ec442508" memberName="oscWaveformLabel11"
         virtualName="" explicitFocusOrder="0" pos="391 127 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="RESONANCE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="noiseAttackSlider" id="df18bc71fd9b48a7" memberName="noiseAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="519 159 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="fc05c7bc41b9c8e5" memberName="oscWaveformLabel12"
         virtualName="" explicitFocusOrder="0" pos="391 159 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="ATTACK&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bahnschrift"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="filterResonanceSlider" id="9e7a5f18c8a125f4" memberName="filterResonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="519 127 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="7f9f31de9c0b9a24" memberName="oscWaveformLabel13"
         virtualName="" explicitFocusOrder="0" pos="391 191 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="DECAY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="filterCutoffSlider" id="d328df1e64503bc9" memberName="filterCutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="519 95 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <GROUPCOMPONENT name="new group" id="fedf657842f0201e" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="376 232 312 224" outlinecol="ff00d7ff"
                  title="MASTER"/>
  <SLIDER name="distortSlider" id="68b2a19a79a15d18" memberName="distortSlider"
          virtualName="" explicitFocusOrder="0" pos="520 360 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="70faa42f4d806f0c" memberName="oscWaveformLabel15"
         virtualName="" explicitFocusOrder="0" pos="392 264 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIX" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f42a071249180edf" memberName="oscWaveformLabel16"
         virtualName="" explicitFocusOrder="0" pos="392 296 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="EQ FREQ" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="eqGainSlider" id="90292ea89fb59a9e" memberName="eqGainSlider"
          virtualName="" explicitFocusOrder="0" pos="520 328 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="5ad726e45d5448fe" memberName="oscWaveformLabel17"
         virtualName="" explicitFocusOrder="0" pos="392 328 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="EQ GAIN" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="eqFreqSlider" id="9df2c3bb2b5f5c5d" memberName="eqFreqSlider"
          virtualName="" explicitFocusOrder="0" pos="520 296 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="7cd974d04b02dafd" memberName="oscWaveformLabel18"
         virtualName="" explicitFocusOrder="0" pos="392 360 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="DISTORT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="mixSlider" id="254cd5829605a295" memberName="mixSlider"
          virtualName="" explicitFocusOrder="0" pos="520 264 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="panSlider" id="39449e4ea652942d" memberName="panSlider"
          virtualName="" explicitFocusOrder="0" pos="520 392 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="bab3150f36a7006f" memberName="oscWaveformLabel14"
         virtualName="" explicitFocusOrder="0" pos="392 392 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PAN" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="levelSlider" id="701cc9dd3505aded" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="520 424 150 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <LABEL name="new label" id="bbac941b94441226" memberName="oscWaveformLabel19"
         virtualName="" explicitFocusOrder="0" pos="392 424 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bahnschrift" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

