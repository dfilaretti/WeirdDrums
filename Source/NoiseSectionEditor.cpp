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
	// setup combo box
	filterTypeComboBox.addItem(kMenuItemLowPassText,  kMenuItemLowPassId);
	filterTypeComboBox.addItem(kMenuItemHighPassText, kMenuItemHighPassId);
	filterTypeComboBox.addItem(kMenuItemBandPassText, kMenuItemSBandPassId);
	filterTypeComboBox.setJustificationType (Justification::centred);

	controls = { { &filterTypeSlider,      "FILTER-TYPE"},
		         //{ &filterTypeComboBox,    "FILTER-TYPE"}, 
		         { &filterCutoffSlider ,   "FILTER-CUTOFF"},
		         { &filterResonanceSlider, "FILTER-RESONANCE" },
		         { &attackSlider,          "NOISE-ATTACK" },
		         { &decaySlider,           "NOISE-DECAY" } };

	// add all conmponents
	setupChildernComponents();
}

NoiseSectionEditor::~NoiseSectionEditor()
{
}