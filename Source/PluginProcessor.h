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

//==============================================================================
/**
*/
class WdAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    WdAudioProcessor();
    ~WdAudioProcessor();

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
	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	//==============================================================================
	Synth mySynth;
	SynthVoice *myVoice;
	
	//==============================================================================
	double lastSampleRate;

	//==============================================================================
	const int kNumVoices = 3;
	const Identifier kValueTreeId = Identifier("WeirdDrums");

	//==============================================================================
	void initSynth();
	void passParamPointersToVoices();

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WdAudioProcessor)
};
