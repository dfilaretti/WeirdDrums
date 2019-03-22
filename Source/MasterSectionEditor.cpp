/*
  ==============================================================================

    MasterSectionEditor.cpp
    Created: 6 Nov 2018 3:44:06pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MasterSectionEditor.h"

//==============================================================================
MasterSectionEditor::MasterSectionEditor(LittleTeknoDrummerAudioProcessor& p, 
	                                     int nRows, int nCols, 
	                                     std::string title, 
	                                     Colour backgroundColour) : 
	LtdComplexComponent(p, nRows, nCols, title, backgroundColour)
{
	controls = { { &mixSlider,        "MASTER-MIX"},
			     { &distortSlider,    "MASTER-DISTORT" },
			     { &levelSlider,      "MASTER-LEVEL" },
		         { &filterTypeSlider, "FILTER-TYPE"},
	}; 

	setupChildren();
}

MasterSectionEditor::~MasterSectionEditor()
{
	setLookAndFeel(nullptr);
}