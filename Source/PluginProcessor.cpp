/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PatSynthAudioProcessor::PatSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	), 
	parameters(*this, nullptr)
#endif
{	
	// Add voices to the synth
	mySynth.clearVoices();
	for (int i = 0; i < 1; i++)
	{
		mySynth.addVoice(new MyVoice());
	}

	// Add sounds to the synth
	mySynth.clearSounds();
	mySynth.addSound(new MySound());
}

PatSynthAudioProcessor::~PatSynthAudioProcessor()
{
	
}

//==============================================================================
const String PatSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PatSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PatSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PatSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PatSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PatSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PatSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PatSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String PatSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void PatSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PatSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	mySynth.setCurrentPlaybackSampleRate(sampleRate);
}

void PatSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PatSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PatSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// This is here to avoid people getting screaming feedback
	// when they first compile a plugin, but obviously you don't need to keep
	// this code if your algorithm always overwrites all the output channels.
	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool PatSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PatSynthAudioProcessor::createEditor()
{
    return new PatSynthAudioProcessorEditor (*this);
}

//==============================================================================
void PatSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	//auto state = parameters.copyState();
	//std::unique_ptr<XmlElement> xml(state.createXml());
	//copyXmlToBinary(*xml, destData);
}

void PatSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	//std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	//if (xmlState.get() != nullptr)
	//	if (xmlState->hasTagName(parameters.state.getType()))
	//		parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PatSynthAudioProcessor();
}

