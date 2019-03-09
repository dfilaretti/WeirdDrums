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
NoiseSectionEditor::NoiseSectionEditor(LittleTeknoDrummerAudioProcessor& p) :
	LtdComplexComponent (p)
{
	controls = { { &filterTypeSlider,      "FILTER-TYPE"},
		         { &filterCutoffSlider ,   "FILTER-CUTOFF"},
		         { &filterResonanceSlider, "FILTER-RESONANCE" },
		         { &attackSlider,          "NOISE-ATTACK" },
		         { &decaySlider,           "NOISE-DECAY" } };

	// add all conmponents
	setupChildren();
}

NoiseSectionEditor::~NoiseSectionEditor()
{
}