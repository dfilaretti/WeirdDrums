/*
  ==============================================================================

    LtdComplexComponent.cpp
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#include "LtdComplexComponent.h"

//==============================================================================
//LtdComplexComponent::LtdComplexComponent(LittleTeknoDrummerAudioProcessor& p) :
//	processor(p)
//{
//	backgroundColour = Colours::white;
//}

LtdComplexComponent::LtdComplexComponent(LittleTeknoDrummerAudioProcessor& p, 
	                                     int rows, 
	                                     int columns) :
	processor(p), nRows {rows}, nCols {columns}
{
	backgroundColour = Colours::white;
}

LtdComplexComponent::~LtdComplexComponent()
{
}

//==============================================================================
void LtdComplexComponent::paint(Graphics& g)
{
	auto area = getLocalBounds().reduced(4);
	g.setColour (backgroundColour);
	g.fillRoundedRectangle (area.toFloat(), 3);
}

void LtdComplexComponent::resized()
{
	int nComponents       = nRows;
	auto nItems           = controls.size();
	auto area             = getLocalBounds().reduced(4);
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
		auto componentArea = columns[columnId].removeFromTop(componentWidth);

		controls[i].first->setBounds (componentArea);
	}
}

void LtdComplexComponent::setBackgroundColour(Colour c)
{
	backgroundColour = c;
}


//==============================================================================
void LtdComplexComponent::setupChild(std::pair<Component*, std::string> p)
{
	addAndMakeVisible(p.first);
	LinkComponentToAttachment(p.first, p.second);
}

void LtdComplexComponent::setupChildren()
{
	for (auto const& c : controls)
	{
		setupChild (c);
	}
}

void LtdComplexComponent::LinkComponentToAttachment(Component* component, std::string attachmentId)
{
	if (ComboBox* c = dynamic_cast<ComboBox*> (component))
		attachments.push_back(std::make_unique<ComboBoxAttachment>(processor.parameters, attachmentId, *c));

	if (LtdSlider* c = dynamic_cast<LtdSlider*> (component))
		attachments.push_back(std::make_unique<SliderAttachment>(processor.parameters, attachmentId, *(c->getSlider())));
}

