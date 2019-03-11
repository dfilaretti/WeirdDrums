/*
  ==============================================================================

    NoiseSectionEditor.cpp
    Created: 6 Nov 2018 4:44:43pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoiseSectionEditor.h"

//==============================================================================
NoiseSectionEditor::NoiseSectionEditor(LittleTeknoDrummerAudioProcessor& p, 
	                                   int nRows, 
	                                   int nCols) :
	LtdComplexComponent (p, nRows, nCols)
{
	setLookAndFeel(&lookAndFeel);

	controls = { //{ &filterTypeSlider,      "FILTER-TYPE"},
		         { &filterCutoffSlider ,   "FILTER-CUTOFF"},
		         { &filterResonanceSlider, "FILTER-RESONANCE" },
		         { &attackSlider,          "NOISE-ATTACK" },
		         { &decaySlider,           "NOISE-DECAY" } };

	// add all conmponents
	setupChildren();
}

NoiseSectionEditor::~NoiseSectionEditor()
{
	setLookAndFeel(nullptr);
}