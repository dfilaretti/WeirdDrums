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
	                             std::string title, 
	                             Colour backgroundColour) :
	processor(p), 
	nRows {rows}, 
	nCols {columns}, 
	titleComponent {title}, 
	backgroundColour {backgroundColour}
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

	titleComponent.setBounds (titleArea);

	int nComponents       = nRows;
	auto nItems           = controls.size();
	auto width            = area.getWidth();
	auto height           = area.getHeight();
	auto componentWidth   = height / nComponents;

	std::vector<Rectangle<int>> columns;
	for (auto i = 0; i < nCols; i++)
	{
		columns.push_back (area.removeFromLeft (width / nCols));
	}

	for (auto i = 0; i < controls.size(); i++)
	{
		auto columnId = i / nRows;
		auto componentArea = columns[columnId].removeFromTop(componentWidth).reduced(10);

		controls[i].first->setBounds (componentArea);
	}
}

//==============================================================================
void Grid2d::setupChild(std::pair<Component*, std::string> p)
{
	addAndMakeVisible(p.first);
	LinkComponentToAttachment(p.first, p.second);
}

void Grid2d::setupChildren()
{
	for (auto const& c : controls)
		setupChild (c);
}

void Grid2d::LinkComponentToAttachment(Component* component, std::string attachmentId)
{
	if (ComboBox* c = dynamic_cast<ComboBox*> (component))
		attachments.push_back(std::make_unique<ComboBoxAttachment>(processor.parameters, attachmentId, *c));

	if (LabelledSlider* c = dynamic_cast<LabelledSlider*> (component))
		attachments.push_back(std::make_unique<SliderAttachment>(processor.parameters, attachmentId, *(c->getSlider())));
}

//==============================================================================
Grid2d::Grid2dTitle::Grid2dTitle (std::string t)
{
	/*titleLabel.setColour(Label::textColourId, Colours::black);*/
	titleLabel.setFont(Font(15.0f, Font::bold));
	titleLabel.setText(t, dontSendNotification);
	titleLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(titleLabel);
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

	g.fillRoundedRectangle(area.toFloat(), 3);
}

void Grid2d::Grid2dTitle::resized()
{
	auto area = getLocalBounds().reduced(4);

	Colour textColour;
	if (auto lf = dynamic_cast<WdLookAndFeel*> (&getLookAndFeel()))
		textColour = lf->colour2;

	titleLabel.setColour(Label::textColourId, textColour);

	titleLabel.setBounds(area);
}