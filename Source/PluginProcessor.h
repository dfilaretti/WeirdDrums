/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Synth.h"
#include "SynthVoice.h"
#include "SynthSound.h"
#include "Globals.h"

//==============================================================================
/**
*/
class PatSynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PatSynthAudioProcessor();
    ~PatSynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

	//==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//==============================================================================
	AudioProcessorValueTreeState parameters;

private:
	//==============================================================================
	Synth mySynth;
	SynthVoice *myVoice;
	
	//==============================================================================
	double lastSampleRate;

	//==============================================================================
	const int kNumVoices = 1;
	const Identifier kValueTreeId = Identifier("PatSynth");

	//==============================================================================
	// OSC SECTION
	const String kParamNameFreq                 = "Freq";
	const String kParamNameAttack               = "Attack";
	const String kParamNameDecay                = "Decay";
	const String kParamNameWaveType             = "Wave Type";
	const String kParamNamePitchEnvAmount       = "Pitch Env Amount";
	const String kParamNamePitchEnvRate         = "Pitch Env Rate";
	const String kParamNamePitchLfoAmount       = "Pitch Lfo Amount";
	const String kParamNamePitchLfoRate         = "Pitch Lfo Rate";
	// NOISE SECTION
	const String kParamNameNoiseAttack          = "Attack";
	const String kParamNameNoiseDecay           = "Decay";
	const String kParamNameNoiseFilterType      = "Filter Type";
	const String kParamNameNoiseFilterCutoff    = "Cutoff";
	const String kParamNameNoiseFilterResonance = "Resonance";
	// MASTER SECTION
	const String kParamNameMasterMix            = "Mix";
	const String kParamNameMasterEqFreq         = "EqFreq";
	const String kParamNameMasterEqGain         = "EqGain";
	const String kParamNameMasterDistort        = "Distort";
	const String kParamNameMasterLevel          = "Level";
	const String kParamNameMasterPan            = "Pan";

	//==============================================================================
	// OSC SECTION
	const NormalisableRange<float> kParamRangeFreq            = NormalisableRange<float>(20.0f,    20000.0f,  0.0001,  0.35); // hz
	const NormalisableRange<float> kParamRangeAttack          = NormalisableRange<float>(0.0001f,  1.0f,      0.0001,  0.35);
	const NormalisableRange<float> kParamRangeDecay           = NormalisableRange<float>(0.0001f,  2.0f,      0.0001,  0.35);
	const NormalisableRange<float> kParamRangeWaveType        = NormalisableRange<float>(0, 2);
	const NormalisableRange<float> kParamRangePitchEnvAmount  = NormalisableRange<float>(-1.0f,    1.0f,      0.0001,  1);
	const NormalisableRange<float> kParamRangePitchEnvRate    = NormalisableRange<float>(0.0001f,  1.0f,      0.0001,  0.35); 
	const NormalisableRange<float> kParamRangePitchLfoAmount  = NormalisableRange<float>(0.0f,     1.0f);
	const NormalisableRange<float> kParamRangePitchLfoRate    = NormalisableRange<float>(0.01f,    80.0f,     0.0001);
	// NOISE SECTION
	const NormalisableRange<float> kParamRangeNoiseAttack          = NormalisableRange<float>(0.0001f, 1.0f, 0.0001f, 0.35);
	const NormalisableRange<float> kParamRangeNoiseDecay           = NormalisableRange<float>(0.0001f, 2.0f, 0.0001f, 0.35);
	const NormalisableRange<float> kParamRangeNoiseFilterType      = NormalisableRange<float>(0, 2);
	const NormalisableRange<float> kParamRangeNoiseFilterCutoff    = NormalisableRange<float>(20.0f, 10000.0f);
	const NormalisableRange<float> kParamRangeNoiseFilterResonance = NormalisableRange<float>(1.0f, 5.0f, 0.0001, 0.4);
	// MASTER SECTION
	const NormalisableRange<float> kParamRangeMasterMix       = NormalisableRange<float>(0, 1);
	const NormalisableRange<float> kParamRangeMasterEqFreq    = NormalisableRange<float>(20, 15000);
	const NormalisableRange<float> kParamRangeMasterEqGain    = NormalisableRange<float>(-12, 12); // db
	const NormalisableRange<float> kParamRangeMasterDistort   = NormalisableRange<float>(0.f, 50.f);
	const NormalisableRange<float> kParamRangeMasterLevel     = NormalisableRange<float>(-24, 24);
	const NormalisableRange<float> kParamRangeMasterPan       = NormalisableRange<float>(-1, 1);

	//==============================================================================
	// OSC SECTION
	const float kParamDefaultFreq                 = 55.0f;
	const float kParamDefaultAttack               = 0.0001f;
	const float kParamDefaultDecay                = 0.5f;
	const float kParamDefaultWaveType             = 0.f;
	const float kParamDefaultPitchEnvAmount       = 0.0f;
	const float kParamDefaultPitchEnvRate         = 0.1f;
	const float kParamDefaultPitchLfoAmount       = 0.0f;
	const float kParamDefaultPitchLfoRate         = 0.5f;
	// NOISE SECTION
	const float kParamDefaultNoiseAttack          = 0.01f;
	const float kParamDefaultNoiseDecay           = 0.5f;
	const float kParamDefaultNoiseFilterType      = .1f;
	const float kParamDefaultNoiseFilterCutoff    = 400.f;
	const float kParamDefaultNoiseFilterResonance = 1.f;
	// MASTER SECTION
	const float kParamDefaultMasterMix            = 0.5f;
	const float kParamDefaultMasterEqFreq         = 1000.f;
	const float kParamDefaultMasterEqGain         = 0.f;
	const float kParamDefaultMasterDistort        = 0.f;
	const float kParamDefaultMasterLevel          = 0.f;
	const float kParamDefaultMasterPan            = 0.f;

	//==============================================================================
	void initValueTree();
	void initSynth();

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatSynthAudioProcessor)
};
