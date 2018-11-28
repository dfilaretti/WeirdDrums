/*
  ==============================================================================

    Common.h
    Created: 6 Nov 2018 10:24:55pm
    Author:  dfila

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Globals
{
public:
	//=======================================================
	// OSC SECTION
	//=======================================================
	
	// ADSR param IDs
	static String paramIdAttack;
	static String paramIdDecay;
	static String paramIdSustain;
	static String paramIdRelease;
	
	// osc param IDs
	static String paramIdWaveType;

	// filter param IDs
	static String paramIdFilterType;
	static String paramIdFilterCutoff;
	static String paramIdFilterReso;
	
	// Pitch Envelope
	static String paramIdPitchEnvAmount;
	static String paramIdPitchEnvRate;

	// Pitch Lfo
	static String paramIdPitchLfoAmount;
	static String paramIdPitchLfoRate;

	//=======================================================
	// NOISE SECTION
	//=======================================================

	// Noise amplitude
	static String paramIdNoiseAttack;
	static String paramIdNoiseDecay;


};
