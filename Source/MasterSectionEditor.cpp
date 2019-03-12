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
	                                     int nRows, 
	                                     int nCols, 
	                                     std::string title) : 
	LtdComplexComponent(p, nRows, nCols, title)
{
	setLookAndFeel(&lookAndFeel);

	controls = { { &mixSlider,     "MASTER-MIX"},
			     //{ &eqFreqSlider , "MASTER-EQ-FREQ"},
			     { &distortSlider, "MASTER-DISTORT" },
			     //{ &eqGainSlider,  "MASTER-EQ-GAIN" },
			     { &levelSlider,   "MASTER-LEVEL" },
		         //{ &panSlider,     "MASTER-PAN" }, 
		         { &filterTypeSlider,      "FILTER-TYPE"},
	}; 

	setupChildren();
}

MasterSectionEditor::~MasterSectionEditor()
{
	setLookAndFeel(nullptr);
}