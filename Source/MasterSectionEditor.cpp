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
MasterSectionEditor::MasterSectionEditor(LittleTeknoDrummerAudioProcessor& p) : 
	LtdComplexComponent(p)
{

	controls = { { &mixSlider,     "MASTER-MIX"},
			     { &eqFreqSlider , "MASTER-EQ-FREQ"},
			     { &distortSlider, "MASTER-DISTORT" },
			     { &eqGainSlider,  "MASTER-EQ-GAIN" },
			     { &levelSlider,   "MASTER-LEVEL" },
		         { &panSlider,     "MASTER-PAN" }
	}; 

	setupChildernComponents();
}

MasterSectionEditor::~MasterSectionEditor()
{
}