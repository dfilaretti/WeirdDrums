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
NoiseSectionEditor::NoiseSectionEditor(WdAudioProcessor& p, 
	                                   int nRows, int nCols, 
	                                   std::string title) :
	Grid2d (p, nRows, nCols, title)
{
	controls = 
	{
		{ &filterCutoffSlider ,   "FILTER-CUTOFF"},
		{ &filterResonanceSlider, "FILTER-RESONANCE" },
		{ &attackSlider,          "NOISE-ATTACK" },
		{ &decaySlider,           "NOISE-DECAY" } 
	};

	setupChildren();
}

NoiseSectionEditor::~NoiseSectionEditor()
{
	setLookAndFeel(nullptr);
}