/*
  ==============================================================================

    LtdComplexComponent.cpp
    Created: 5 Mar 2019 3:46:46pm
    Author:  dfila

  ==============================================================================
*/

#include "LtdComplexComponent.h"

LtdComplexComponent::LtdComplexComponent(LittleTeknoDrummerAudioProcessor& p) :
	processor(p)
{
	// add all conmponents
	//setupChildernComponents();
}

LtdComplexComponent::~LtdComplexComponent()
{
}

void LtdComplexComponent::paint(Graphics& g)
{
	// TODO
}

void LtdComplexComponent::resized()
{
	auto area = getLocalBounds();
	auto componentWidth = area.getWidth() / 10;

	// position all our controls
	for (auto const& c : controls)
		c.first->setBounds(area.removeFromLeft(componentWidth));
}

void LtdComplexComponent::setupChildernComponents()
{
	for (auto const& c : controls)
	{
		addAndMakeVisible(c.first);
		LinkComponentToAttachment(c.first, c.second);
	}
}

void LtdComplexComponent::LinkComponentToAttachment(Component* component, std::string attachmentId)
{
	if (ComboBox* c = dynamic_cast<ComboBox*> (component))
		attachments.push_back(std::make_unique<ComboBoxAttachment>(processor.parameters, attachmentId, *c));

	if (LtdSlider* c = dynamic_cast<LtdSlider*> (component))
		attachments.push_back(std::make_unique<SliderAttachment>(processor.parameters, attachmentId, *(c->getSlider())));
}

