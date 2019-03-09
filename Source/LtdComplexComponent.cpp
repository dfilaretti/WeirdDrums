/*
  ==============================================================================

    LtdComplexComponent.cpp
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#include "LtdComplexComponent.h"

//==============================================================================
LtdComplexComponent::LtdComplexComponent(LittleTeknoDrummerAudioProcessor& p) :
	processor(p)
{
	backgroundColour = Colours::white;
}

LtdComplexComponent::~LtdComplexComponent()
{
}

//==============================================================================
void LtdComplexComponent::paint(Graphics& g)
{
	auto area = getLocalBounds().reduced(10, 5);
	g.setColour (backgroundColour);
	g.fillRoundedRectangle (area.toFloat(), 10.0f);
}

void LtdComplexComponent::resized()
{
	auto area = getLocalBounds();
	auto componentWidth = area.getWidth() / 8;

	// position all our controls
	for (auto const& c : controls)
		c.first->setBounds(area.removeFromLeft(componentWidth).reduced(10));
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

