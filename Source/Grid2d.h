/*
  ==============================================================================

    Grid2d.h
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LookAndFeels.h"
#include "LabelledRotarySlider.h"
#include <variant>

class Grid2d :		public Component
{
public:
	//==============================================================================
	Grid2d (WdAudioProcessor& /*processor*/,  
		    int               /*nRows*/, 
		    int               /*nColumns*/, 
		    std::string       /*title*/);

	~Grid2d();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

	//==============================================================================
	class Grid2dTitle : public Component
	{
	public:
		//==============================================================================
		Grid2dTitle(std::string);
		~Grid2dTitle();

		//==============================================================================
		void paint(Graphics&) override;
		void resized() override;
	private:
		//==============================================================================
		Label titleLabel;
	};
	
	//==============================================================================
	void addRotarySlider(juce::String name, std::string paramId);
	//void addComboBox  (...);
	//void addSlider    (...);
	// ... etc ...

	//==============================================================================
	void setupChild(Component*, std::string);

private:
	//==============================================================================
	std::vector<std::unique_ptr<Component>> components;
	std::vector<std::string> paramIds;

	//==============================================================================
	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
	typedef std::variant<std::unique_ptr<SliderAttachment>, std::unique_ptr<ComboBoxAttachment>> Attachment;

	//==============================================================================
	const int kTitleSectionHeight { 30 };

	//==============================================================================
	Grid2dTitle titleComponent;
	int nRows;
	int nCols;

	//==============================================================================
	WdAudioProcessor& processor;
	std::vector<Attachment> attachments;
};