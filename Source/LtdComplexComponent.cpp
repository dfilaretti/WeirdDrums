/*
  ==============================================================================

    LtdComplexComponent.cpp
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#include "LtdComplexComponent.h"

//==============================================================================
LtdComplexComponent::LtdComplexComponent(LittleTeknoDrummerAudioProcessor& p, 
	                                     int rows, 
	                                     int columns, 
	                                     std::string title, 
	                                     Colour backgroundColour) :
	processor(p), nRows {rows}, nCols {columns}, titleComponent {title}, backgroundColour {backgroundColour}
{
	backgroundColour = Colours::white;

	addAndMakeVisible (titleComponent);
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
	auto area             = getLocalBounds().reduced(4);
	
	auto titleArea = area.removeFromTop (kTitleSectionHeight);
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
void LtdComplexComponent::setupChild(std::pair<Component*, std::string> p)
{
	addAndMakeVisible(p.first);
	LinkComponentToAttachment(p.first, p.second);
}

void LtdComplexComponent::setupChildren()
{
	for (auto const& c : controls)
		setupChild (c);
}

void LtdComplexComponent::LinkComponentToAttachment(Component* component, std::string attachmentId)
{
	if (ComboBox* c = dynamic_cast<ComboBox*> (component))
		attachments.push_back(std::make_unique<ComboBoxAttachment>(processor.parameters, attachmentId, *c));

	if (LtdSlider* c = dynamic_cast<LtdSlider*> (component))
		attachments.push_back(std::make_unique<SliderAttachment>(processor.parameters, attachmentId, *(c->getSlider())));
}

void LtdComplexComponent::resetAllComponents()
{
	//for (auto const& c : controls)
	//{
	//	auto component = c.first;
	//	component->;
	//}
}

//==============================================================================
LtdComplexComponentTitle::LtdComplexComponentTitle (std::string t)
	: title {t}
{
}

LtdComplexComponentTitle::~LtdComplexComponentTitle()
{
}

void LtdComplexComponentTitle::paint (Graphics& g)
{

	auto area = getLocalBounds().reduced (4);
	g.setColour(background);
	g.fillRoundedRectangle(area.toFloat(), 3);
	
	g.setColour(Colours::black);
	g.setFont(Font(15.0f, Font::bold));
	g.drawText(title, area, Justification::centred, true);
}