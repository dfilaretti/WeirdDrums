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

class LtdComplexComponentTitle : public Component
{
public:
	//==============================================================================
	LtdComplexComponentTitle (std::string);
	~LtdComplexComponentTitle();

	//==============================================================================
	void paint(Graphics&) override;
	//void resized() override;
private:
	std::string title;
	Colour background = Colours::grey;
};

class LtdComplexComponent :		public Component
{
public:
	//==============================================================================
	LtdComplexComponent (LittleTeknoDrummerAudioProcessor& /*p*/, int, int, std::string);
	~LtdComplexComponent();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

	//==============================================================================
	void setBackgroundColour(Colour c);
	void setTitle (std::string t);

//protected:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef std::variant<std::unique_ptr<SliderAttachment>, std::unique_ptr<ComboBoxAttachment>> Attachment;

	//==============================================================================
	void LinkComponentToAttachment(Component*, std::string);
	void setupChildren();
	void setupChild(std::pair<Component*, std::string>);

	//==============================================================================
	std::vector<std::pair<Component*, std::string>> controls;

	//==============================================================================
	//Label titleLabel;
private:
	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
	int nRows;
	int nCols;

	//==============================================================================
	LtdComplexComponentTitle titleComponent { "sample title" };

	//==============================================================================
	int titleSectionHeight = 30;

	//==============================================================================
	Colour backgroundColour;

	//==============================================================================
	std::vector<Attachment> attachments;
};