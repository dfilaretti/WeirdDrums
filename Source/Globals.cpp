/*
  ==============================================================================

    Globals.cpp
    Created: 6 Nov 2018 10:34:17pm
    Author:  dfila

  ==============================================================================
*/

#include "Globals.h"

// ADSR
String Globals::paramIdAttack         = "ATTACK";
String Globals::paramIdDecay          = "DECAY";
String Globals::paramIdSustain        = "SUSTAIN";
String Globals::paramIdRelease        = "RELEASE";
// OSC
String Globals::paramIdWaveType       = "WAVE-TYPE";
// PITCH ENVELOPE
String Globals::paramIdPitchEnvAmount = "PITCH-ENV-AMOUNT";
String Globals::paramIdPitchEnvRate   = "PITCH-ENV-RATE";
// PITCH LFO
String Globals::paramIdPitchLfoAmount = "PITCH-LFO-AMOUNT";
String Globals::paramIdPitchLfoRate   = "PITCH-LFO-RATE";

//=======================================================
// NOISE SECTION
//=======================================================

// NOISE FILTER
String Globals::paramIdNoiseFilterType     = "FILTER-TYPE";
String Globals::paramIdNoiseFilterCutoff   = "FILTER-CUTOFF";
String Globals::paramIdNoiseFilterReso     = "FILTER-RESONANCE";
// NOISE AMPLITUDE
String Globals::paramIdNoiseAttack    = "NOISE-ATTACK";
String Globals::paramIdNoiseDecay     = "NOISE-DECAY";

//=======================================================
// MASTER SECTION
//=======================================================

// OSC/NOISE MIX
String Globals::paramIdMasterMix      = "MASTER-MIX";
// GLOBAL EQ
String Globals::paramIdMasterEqFreq   = "MASTER-EQ-FREQ";
String Globals::paramIdMasterEqGain   = "MASTER-EQ-GAIN";
// DISTORTION
String Globals::paramIdMasterDistort  = "MASTER-DISTORT";
// LEVEL & PAN
String Globals::paramIdMasterLevel    = "MASTER-LEVEL";
String Globals::paramIdMasterPan      = "MASTER-PAN";