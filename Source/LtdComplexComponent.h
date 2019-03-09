/*
  ==============================================================================

    LtdComplexComponent.h
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LtdSlider.h"
#include <variant>

class LtdComplexComponent :		public Component
{
public:
	//==============================================================================
	LtdComplexComponent (LittleTeknoDrummerAudioProcessor& /*p*/);
	~LtdComplexComponent();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

//protected:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef std::variant<std::unique_ptr<SliderAttachment>, std::unique_ptr<ComboBoxAttachment>> Attachment;

	//==============================================================================
	void LinkComponentToAttachment(Component*, std::string);
	void setupChildernComponents();

	//==============================================================================
	std::vector<std::pair<Component*, std::string>> controls;
private:
	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

	//================ ==============================================================
	Colour backgroundColour;

	//==============================================================================
	std::vector<Attachment> attachments;



};