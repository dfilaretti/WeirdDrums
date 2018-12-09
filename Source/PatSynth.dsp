import("stdfaust.lib");

// ------------------------------------------
// UTILITIES (custom envs etc. )
// ------------------------------------------

// Just a copy/paste of en.ar. 
// TODO: make it exponential. Even better: make adjustable curve
perc (a,r,t) = cnt(totalTime,totalTime,on) : ba.bpf.start(0,0) :
	ba.bpf.point(attTime,1) : ba.bpf.end(attTime+relTime,0)
with{
	cnt(count,init,trig) = \(c).(ba.if(trig > 0, 0, min(count, c+1))) ~+ (init-init');
	on = (t-t')>0;
	attTime = ma.SR*a;
	relTime = ma.SR*r;
	totalTime = attTime+relTime;
};


// ------------------------------------------
// OSC SECTION
// ------------------------------------------

oscSection (trig) = trig : env * signal with {	
    oscWave         = nentry  ("[1]wave",              0,     0,     2,     1); // 0: saw | 1: sine | 2: square
    freq            = hslider ("[2]freq",              55,    20,    2000,  0.001) : si.smoo;	
    attack          = hslider ("[3]attack",            0.001, 0.001, 1,     0.001) : si.smoo;
    release         = hslider ("[4]release",           0.5,   0.001, 1,     0.001) : si.smoo;
    pitchEnvAmount  = hslider ("[5]pitch-env-amount",  100  , 0,     10000, 0.001) : si.smoo;
    pitchEnvAttack  = hslider ("[6]pitch-env-attack",  0.001, 0.001, 1,     0.001) : si.smoo;
    pitchEnvRelease = hslider ("[7]pitch-env-release", 0.1,   0.001, 1,     0.001) : si.smoo;
    pitchLfoFreq    = hslider ("[8]pitch-lfo-freq",    0.1,   0.1,   40,    0.001) : si.smoo;
    pitchLfoAmount  = hslider ("[9]pitch-lfo-amount",  0,     0,     10000, 0.001) : si.smoo;
    env             = perc (attack, release);
    pitch           = freq + (pitchEnv * pitchEnvAmount) + (os.oscsin (pitchLfoFreq) * pitchLfoAmount);
    pitchEnv        = trig : perc (pitchEnvAttack, pitchEnvRelease); 
    signal          = select3 (oscWave, os.oscsin (pitch), os.sawtooth (pitch), os.square (pitch));
};

// ------------------------------------------
// NOISE SECTION
// ------------------------------------------

noiseSection (trig) = env * signal with {
    filterType      = nentry  ("[1]filter-type",     1,     0,     2,     1); 
    envType         = nentry  ("[2]env-type",        0,     0,     2,     1);
    cutoff          = hslider ("[3]cutoff",          10000, 50,    10000, 0.001) : si.smoo;
    reso            = hslider ("[4]reso",            0.9,   0.9,   10,    0.001) : si.smoo;
    attack          = hslider ("[5]attack",          0.001, 0.001, 1,     0.001) : si.smoo;
    release         = hslider ("[6]release",         0.2,     0.001, 1,   0.001) : si.smoo;
    noise           = no.noise;
    linEnv          = trig : perc (attack, release);
    expEnv          = trig : perc (attack, release);
    customEnv       = trig : perc (attack, release);
    env             = select3 (envType, linEnv, expEnv, customEnv);
    lp              = fi.resonlp (cutoff, reso, 1);
    hp              = fi.resonhp (cutoff, reso, 1);
    bp              = fi.resonbp (cutoff, reso, 1); 	
    signal          = select3 (filterType, lp (noise), hp (noise), bp (noise));
};

// ------------------------------------------
// MASTER SECTION
// ------------------------------------------

masterSection (oscSignal, noiseSignal) = scaledOscSig, scaledNoiseSig :> (distortion : eq) * gain : sp.panner (pan) with {
    mix             = hslider("[1]mix", 0.15 , 0, 1, 0.001) : si.smoo;
    gain            = hslider("[2]gain", 1 , 0, 2, 0.001) : si.smoo;
    drive           = hslider("[3]drive", 0 , 0, 1, 0.001) : si.smoo;
    eqFreq          = hslider("[4]eq-freq", 100 , 20, 10000, 0.001) : si.smoo;
    eqGain          = hslider("[4]eq-gain", 0 , -12, 12, 0.001) : si.smoo;
    pan             = hslider("[5]pan", 0.5 , 0, 1, 0.001) : si.smoo;
    scaledOscSig    = oscSignal * oscLevel;
    scaledNoiseSig  = noiseSignal * noiseLevel;
    distortion      = ef.cubicnl(drive, 0);
    eq              = fi.peak_eq_cq(eqGain, eqFreq, 1);
    oscLevel        = 1 - mix;
    noiseLevel      = mix;
};

// ------------------------------------------
// OUTPUT
// ------------------------------------------

mySynth (trigger) = hgroup ("PatSynth", vgroup("osc", trigger : oscSection) , vgroup ("noise", trigger : noiseSection) : vgroup("master", masterSection));

  process = gate : mySynth with {
  gate  = button("gate") : si.smoo;
};
