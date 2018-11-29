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

	// Pitch Envelope
	static String paramIdPitchEnvAmount;
	static String paramIdPitchEnvRate;

	// Pitch Lfo
	static String paramIdPitchLfoAmount;
	static String paramIdPitchLfoRate;

	//=======================================================
	// NOISE SECTION
	//=======================================================

	// filter param IDs
	static String paramIdNoiseFilterType;
	static String paramIdNoiseFilterCutoff;
	static String paramIdNoiseFilterReso;
	// Noise amplitude
	static String paramIdNoiseAttack;
	static String paramIdNoiseDecay;

	//=======================================================
	// MASTER SECTION
	//=======================================================

	static String paramIdMasterMix;
	static String paramIdMasterEqFreq;
	static String paramIdMasterEqGain;
	static String paramIdMasterDistort;
	static String paramIdMasterLevel;
	static String paramIdMasterPan;
};
