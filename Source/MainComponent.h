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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component,
                       public ComboBox::Listener,
                       public Slider::Listener
{
public:
    //==============================================================================
    MainComponent (PatSynthAudioProcessor& p);
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PatSynthAudioProcessor& processor;

	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

	ScopedPointer<SliderAttachment> mixSliderAttachment;
	ScopedPointer<SliderAttachment> eqFreqSliderAttachment;
	ScopedPointer<SliderAttachment> distortSliderAttachment;
	ScopedPointer<SliderAttachment> eqGainSliderAttachment;
	ScopedPointer<SliderAttachment> levelSliderAttachment;
	ScopedPointer<SliderAttachment> panSliderAttachment;

	ScopedPointer<ComboBoxAttachment>
		oscComboBoxAttachment;
	ScopedPointer<SliderAttachment>
		frequencySliderAttachment,
		oscAttackSliderAttachment,
		oscDecaySliderAttachment,
		pitchEnvAmountAttachment,
		pitchEnvRateSliderAttachment,
		pitchLfoAmountAttachment,
		pitchLfoRateSliderAttachment;

	ScopedPointer<ComboBoxAttachment>
		filterTypeComboBoxAttachment;
	ScopedPointer<SliderAttachment>
		filterCutoffSliderAttachment,
		filterResonanceSliderAttachment;
	ScopedPointer<SliderAttachment>
		noiseAttackSliderAttachment, noiseDecaySliderAttachment;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<ComboBox> oscComboBox;
    std::unique_ptr<Label> oscWaveformLabel;
    std::unique_ptr<Slider> pitchEnvAmountSlider;
    std::unique_ptr<Label> oscWaveformLabel2;
    std::unique_ptr<Slider> pitchEnvRateSlider;
    std::unique_ptr<Label> oscWaveformLabel3;
    std::unique_ptr<Slider> pitchLfoRateSlider;
    std::unique_ptr<Label> oscWaveformLabel4;
    std::unique_ptr<Slider> pitchLfoAmountSlider;
    std::unique_ptr<Label> oscWaveformLabel5;
    std::unique_ptr<Label> oscWaveformLabel6;
    std::unique_ptr<Slider> frequencySlider;
    std::unique_ptr<Slider> oscAttackSlider;
    std::unique_ptr<Label> oscWaveformLabel9;
    std::unique_ptr<Slider> oscDecaySlider;
    std::unique_ptr<Label> oscWaveformLabel10;
    std::unique_ptr<ComboBox> filterTypeComboBox;
    std::unique_ptr<Label> oscWaveformLabel7;
    std::unique_ptr<Slider> noiseDecaySlider;
    std::unique_ptr<Label> oscWaveformLabel8;
    std::unique_ptr<Label> oscWaveformLabel11;
    std::unique_ptr<Slider> noiseAttackSlider;
    std::unique_ptr<Label> oscWaveformLabel12;
    std::unique_ptr<Slider> filterResonanceSlider;
    std::unique_ptr<Label> oscWaveformLabel13;
    std::unique_ptr<Slider> filterCutoffSlider;
    std::unique_ptr<GroupComponent> groupComponent3;
    std::unique_ptr<Slider> distortSlider;
    std::unique_ptr<Label> oscWaveformLabel15;
    std::unique_ptr<Label> oscWaveformLabel16;
    std::unique_ptr<Slider> eqGainSlider;
    std::unique_ptr<Label> oscWaveformLabel17;
    std::unique_ptr<Slider> eqFreqSlider;
    std::unique_ptr<Label> oscWaveformLabel18;
    std::unique_ptr<Slider> mixSlider;
    std::unique_ptr<Slider> panSlider;
    std::unique_ptr<Label> oscWaveformLabel14;
    std::unique_ptr<Slider> levelSlider;
    std::unique_ptr<Label> oscWaveformLabel19;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

