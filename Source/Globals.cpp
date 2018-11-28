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
// FILTER
String Globals::paramIdFilterType     = "FILTER-TYPE";
String Globals::paramIdFilterCutoff   = "FILTER-CUTOFF";
String Globals::paramIdFilterReso     = "FILTER-RESONANCE";
// PITCH ENVELOPE
String Globals::paramIdPitchEnvAmount = "PITCH-ENV-AMOUNT";
String Globals::paramIdPitchEnvRate   = "PITCH-ENV-RATE";
// PITCH LFO
String Globals::paramIdPitchLfoAmount = "PITCH-LFO-AMOUNT";
String Globals::paramIdPitchLfoRate   = "PITCH-LFO-RATE";

//=======================================================
// NOISE SECTION
//=======================================================

// NOISE AMPLITUDE
String Globals::paramIdNoiseAttack    = "NOISE-ATTACK";
String Globals::paramIdNoiseDecay     = "NOISE-DECAY";
