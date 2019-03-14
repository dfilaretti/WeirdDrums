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
	LtdComplexComponent (LittleTeknoDrummerAudioProcessor& /*processor*/,  
		                 int                               /*nRows*/, 
		                 int                               /*nColumns*/, 
		                 std::string                       /*title*/, 
		                 Colour                            /*backgroundColour*/);
	~LtdComplexComponent();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

	//==============================================================================
	void setBackgroundColour(Colour c);

protected:
	//==============================================================================
	void setupChildren();
	std::vector<std::pair<Component*, std::string>> controls;

private:
	//==============================================================================
	void LinkComponentToAttachment(Component*, std::string);
	void setupChild(std::pair<Component*, std::string>);

	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef std::variant<std::unique_ptr<SliderAttachment>, std::unique_ptr<ComboBoxAttachment>> Attachment;

	//==============================================================================
	int kTitleSectionHeight = 30;

	//==============================================================================
	Colour backgroundColour;
	int nRows;
	int nCols;

	//==============================================================================
	LtdComplexComponentTitle titleComponent { "sample title" };

	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
	std::vector<Attachment> attachments;
};