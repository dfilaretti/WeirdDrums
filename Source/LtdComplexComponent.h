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
	class LtdComplexComponentTitle : public Component
	{
	public:
		//==============================================================================
		LtdComplexComponentTitle(std::string);
		~LtdComplexComponentTitle();

		//==============================================================================
		void paint(Graphics&) override;
		void resized() override;
	private:
		//==============================================================================
		Label titleLabel;
		Colour background = Colours::grey;
	};

protected:
	//==============================================================================
	void setupChildren();

	//==============================================================================
	std::vector<std::pair<Component*, std::string>> controls;

private:
	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef std::variant<std::unique_ptr<SliderAttachment>, std::unique_ptr<ComboBoxAttachment>> Attachment;

	//==============================================================================
	const int kTitleSectionHeight = 30;

	//==============================================================================
	Colour backgroundColour;
	int nRows;
	int nCols;

	//==============================================================================
	void LinkComponentToAttachment(Component*, std::string);
	void setupChild(std::pair<Component*, std::string>);

	//==============================================================================
	LtdComplexComponentTitle titleComponent;

	//==============================================================================
	LittleTeknoDrummerAudioProcessor& processor;

	//==============================================================================
	std::vector<Attachment> attachments;
};