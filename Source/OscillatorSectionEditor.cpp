/*
  ==============================================================================

    OscillatorSectionEditor.cpp
    Created: 6 Nov 2018 2:36:24pm
    Author:  dfila

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscillatorSectionEditor.h"

//==============================================================================
OscillatorSectionEditor::OscillatorSectionEditor (LittleTeknoDrummerAudioProcessor& p) 
	: LtdComplexComponent(p)
{
	// setup combo box
	oscComboBox.addItem (kMenuItemSineText,   kMenuItemSineId);
	oscComboBox.addItem (kMenuItemSawText,    kMenuItemSawId);
	oscComboBox.addItem (kMenuItemSquareText, kMenuItemSquareId);
	oscComboBox.setJustificationType (Justification::centred);

	controls = { { &m_oscSlider,            "WAVE-TYPE"},
		         //{ &oscComboBox,            "WAVE-TYPE"},
			     { &m_freqSlider,           "FREQ"},
			     { &m_attackSlider ,        "ATTACK"},
			     { &m_decaySlider,          "DECAY" },
			     { &m_pitchEnvAmountSlider, "PITCH-ENV-AMOUNT" },
			     { &m_pitchEnvRateSlider,   "PITCH-ENV-RATE" },
			     { &m_pitchLfoAmountSlider, "PITCH-LFO-AMOUNT" },
			     { &m_pitchLfoRateSlider,   "PITCH-LFO-RATE" } };

	// add all conmponents
	setupChildren();
}

OscillatorSectionEditor::~OscillatorSectionEditor()
{
}