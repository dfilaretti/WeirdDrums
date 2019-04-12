/*
  ==============================================================================

    Grid2d.cpp
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#include "Grid2d.h"

//==============================================================================
Grid2d::Grid2d(WdAudioProcessor& p, 
	                             int rows, 
	                             int columns, 
	                             std::string title) :
	processor(p), 
	nRows {rows}, 
	nCols {columns}, 
	titleComponent {title}
{
	addAndMakeVisible (titleComponent);
}

Grid2d::~Grid2d()
{
}

//==============================================================================
void Grid2d::paint(Graphics& g)
{
	auto area = getLocalBounds().reduced(4);

	Colour backgroundColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		backgroundColour = lf->colour2;

	g.setColour (backgroundColour);
	g.fillRoundedRectangle (area.toFloat(), 3);
}

void Grid2d::resized()
{
	auto area             = getLocalBounds().reduced(4);
	auto titleArea        = area.removeFromTop (kTitleSectionHeight);
	auto nComponents      = nRows;
	auto width            = area.getWidth();
	auto height           = area.getHeight();
	auto componentWidth   = height / nComponents;
	
	titleComponent.setBounds (titleArea);

	std::vector<Rectangle<int>> columns;
	for (auto i = 0; i < nCols; i++)
	{
		columns.push_back (area.removeFromLeft (width / nCols));
	}

	for (auto i = 0; i < components.size(); i++)
	{
		auto columnId = i / nRows;
		auto componentArea = columns[columnId].removeFromTop (componentWidth).reduced(10);

		components[i]->setBounds (componentArea);
	}
}

//==============================================================================
void Grid2d::addRotarySlider(juce::String name, std::string paramId)
{
	components.push_back(std::unique_ptr<Component> {new LabelledRotarySlider { name }});
	paramIds.push_back (paramId);

	setupChild (components.back().get(), paramId);
}

void Grid2d::setupChild (Component* component, std::string paramId)
{
	// Make component visible
	addAndMakeVisible(component);

	// "Connect" component to the desired param, via the appropriate Attachment
	if (ComboBox * c = dynamic_cast<ComboBox*> (component))
		attachments.push_back (std::make_unique<ComboBoxAttachment> (processor.parameters, paramId, *c));
	if (LabelledSlider * c = dynamic_cast<LabelledSlider*> (component))
		attachments.push_back (std::make_unique<SliderAttachment> (processor.parameters, paramId, *(c->getSlider())));
	// if (...)
}

//==============================================================================
Grid2d::Grid2dTitle::Grid2dTitle (std::string t)
{
	titleLabel.setFont (Font(15.0f, Font::bold));
	titleLabel.setText (t, dontSendNotification);
	titleLabel.setJustificationType (Justification::centred);
	addAndMakeVisible (titleLabel);
}

Grid2d::Grid2dTitle::~Grid2dTitle()
{
}

void Grid2d::Grid2dTitle::paint (Graphics& g)
{
	auto area = getLocalBounds().reduced (4);

	Colour backgroundColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		backgroundColour = lf->colour3;

	g.setColour(backgroundColour);

	g.fillRoundedRectangle (area.toFloat(), 3);
}

void Grid2d::Grid2dTitle::resized()
{
	auto area = getLocalBounds().reduced(4);

	Colour textColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		textColour = lf->colour2;

	titleLabel.setColour(Label::textColourId, textColour);

	titleLabel.setBounds (area);
}