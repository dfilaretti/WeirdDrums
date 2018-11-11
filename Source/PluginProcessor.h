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
	Synth mySynth;
	SynthVoice *myVoice;
	
	double lastSampleRate;

	//==============================================================================
	const Identifier kValueTreeId = Identifier("PatSynth");

	const int kNumVoices = 2;

	const String kParamNameAttack          = "Attack";
	const String kParamNameDecay           = "Decay";
	const String kParamNameSustain         = "Sustain";
	const String kParamNameRelease         = "Release";
	const String kParamNameWaveType        = "Wave Type";
	const String kParamNameFilterType      = "Filter Type";
	const String kParamNameFilterCutoff    = "Cutoff";
	const String kParamNameFilterResonance = "Resonance";

	const NormalisableRange<float> kParamRangeAttack          = NormalisableRange<float>(0.1f, 5000.0f);
	const NormalisableRange<float> kParamRangeDecay           = NormalisableRange<float>(0.1f, 5000.0f);
	const NormalisableRange<float> kParamRangeSustain         = NormalisableRange<float>(0.0f, 1.0f);
	const NormalisableRange<float> kParamRangeRelease         = NormalisableRange<float>(0.1f, 1000.0f);
	const NormalisableRange<float> kParamRangeWaveType        = NormalisableRange<float>(0, 2);
	const NormalisableRange<float> kParamRangeFilterType      = NormalisableRange<float>(0, 2);
	const NormalisableRange<float> kParamRangeFilterCutoff    = NormalisableRange<float>(20.0f, 10000.0f);
	const NormalisableRange<float> kParamRangeFilterResonance = NormalisableRange<float>(1.0f, 5.0f);

	const float kParamDefaultAttack          = .1f;
	const float kParamDefaultDecay           = .5f;
	const float kParamDefaultSustain         = .8f;
	const float kParamDefaultRelease         = .2f;
	const float kParamDefaultWaveType        = 0.f;
	const float kParamDefaultFilterType      = .1f;
	const float kParamDefaultFilterCutoff    = 400.f;
	const float kParamDefaultFilterResonance = 1.f;

	//==============================================================================
	

	//==============================================================================
	void initValueTree();
	void initSynth();

	//void updateFilter();

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatSynthAudioProcessor)
};
