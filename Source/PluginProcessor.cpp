/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WdAudioProcessor::WdAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	), 
	parameters(*this, nullptr, "WeirdDrums", createParameterLayout())
#endif
{	
	initSynth();
	passParamPointersToVoices();
}

WdAudioProcessor::~WdAudioProcessor()
{
}

//==============================================================================
AudioProcessorValueTreeState::ParameterLayout WdAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;

	// TONE section
	
	{
		auto range = NormalisableRange<float>(20.f, 20000.f);
		range.setSkewForCentre(220.0f);
		params.push_back(std::make_unique<AudioParameterFloat>("FREQ", 
			                                                   "Freq", 
			                                                   range, 
			                                                   55.f, 
			                                                   "Freq", 
												               AudioProcessorParameter::genericParameter, 
			                                                   [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 3) + " Hz ";  },
			                                                   nullptr));
	}
	
	{
		auto range = NormalisableRange<float>(0.0001f, 1.0f);
		range.setSkewForCentre(0.2f);
		params.push_back (std::make_unique<AudioParameterFloat> ("ATTACK", 
			                                                     "Attack", 
			                                                     range,
			                                                     0.0001f, 
			                                                     "Attack", 
			                                                     AudioProcessorParameter::genericParameter,
			                                                     [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 2) + " sec ";  },
			                                                     nullptr
			                                                     ));
	}
	
	{
		auto range = NormalisableRange<float>(0.0001f, 2.0f);
		range.setSkewForCentre(0.25f);
		params.push_back (std::make_unique<AudioParameterFloat> ("DECAY", 
			                                                     "Decay", 
			                                                     range,
			                                                     0.5f, 
			                                                     "Decay", 
			                                                     AudioProcessorParameter::genericParameter, 
			                                                     [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 2) + " sec ";  }, 
			                                                     nullptr));
	
	}

	params.push_back (std::make_unique<AudioParameterFloat> ("WAVE-TYPE", 
			                                                 "Wave Type", 
                 			                                 NormalisableRange<float>(0.f, 2.f, 1.f),
			                                                 0.f, 
															 "Wave Type", 
															 AudioProcessorParameter::genericParameter,
															 [](float value, int) 
			                                                 {
			if (0 == value)
				return "SINE";
			else if (1 == value)
				return "SAW";
			else if (2 == value)
				return "SQUARE";
			else
				return "ERR";
                                                                 
			                                                 },
															 nullptr));
	
	params.push_back (std::make_unique<AudioParameterFloat> ("PITCH-ENV-AMOUNT", 
		                                                     "Pitch Env Amount", 
		                                                     NormalisableRange<float>(0.f, 1.f),
		                                                     0.f, 
		                                                     "Pitch Env Amount",
		                                                     AudioProcessorParameter::genericParameter,
		                                                     [] (float value, int) { return juce::String::toDecimalStringWithSignificantFigures (jmap (value, 0.f, 100.f), 2) + " %" ;  },
		                                                     nullptr));
	

	{
		auto range = NormalisableRange<float>(0.001f, 1.0f);
		range.setSkewForCentre(0.2f);
		params.push_back (std::make_unique<AudioParameterFloat> ("PITCH-ENV-RATE", 
			                                                     "Pitch Env Rate", 
			                                                     range,
			                                                     0.1f, 
			                                                     "Pitch Env Rate", 
			                                                     AudioProcessorParameter::genericParameter,
			                                                     [](double value, int) { return juce::String::toDecimalStringWithSignificantFigures(value, 2) + " sec ";  },
			                                                     nullptr));
	}

	params.push_back (std::make_unique<AudioParameterFloat> ("PITCH-LFO-AMOUNT", 
		                                                     "Pitch Lfo Amount", 
		                                                     NormalisableRange<float>(0.f, 1.f),
		                                                     0.f, 
		                                                     "Pitch Lfo Amount", 
		                                                     AudioProcessorParameter::genericParameter,
		                                                     [](float value, int) { return juce::String::toDecimalStringWithSignificantFigures(jmap(value, 0.f, 100.f), 2) + " %";  },
		                                                     nullptr));

	params.push_back (std::make_unique<AudioParameterFloat> ("PITCH-LFO-RATE", 
		                                                     "Pitch Lfo Rate", 
		                                                     NormalisableRange<float>(0.1f, 80.f),
		                                                     0.450f,
		                                                     "Pitch Lfo Rate",
		                                                     AudioProcessorParameter::genericParameter,
		                                                     [](double value, int) { return juce::String::toDecimalStringWithSignificantFigures(value, 3) + " Hz ";  },
		                                                     nullptr));
	
	// NOISE section

	params.push_back (std::make_unique<AudioParameterFloat> ("FILTER-TYPE", 
			                                                 "Filter Type", 
			                                                 NormalisableRange<float>(0.f, 2.f, 1.f), 
			                                                 0.f,
			                                                 "Filter Type",
			                                                 AudioProcessorParameter::genericParameter,
			                                                 [](float value, int)
			                                                 {
			if (0 == value)
				return "LP";
			else if (1 == value)
				return "HP";
			else if (2 == value)
				return "BP";
			else
				return "ERR";
			                                                  
			                                                 },
			                                                 nullptr));
	
	
	params.push_back (std::make_unique<AudioParameterFloat> ("FILTER-CUTOFF", 
			                                                 "Cutoff", 
			                                                 NormalisableRange<float>(20.f, 18000.f), 
			                                                 400.f,
			                                                 "Cutoff",
			                                                 AudioProcessorParameter::genericParameter,
			                                                 [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 3) + " Hz ";  },
			                                                 nullptr));
	
	params.push_back (std::make_unique<AudioParameterFloat> ("FILTER-RESONANCE", 
			                                                  "Resonance", 
			                                                  NormalisableRange<float>(1.f, 5.f), 
															  1.f,
			                                                  "Resonance", 
			                                                  AudioProcessorParameter::genericParameter, 
			                                                  [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 2);  }, 
			                                                  nullptr
			                                                  ));
	
	{
		auto range = NormalisableRange<float>(0.0001f, 1.f);
		range.setSkewForCentre(0.2f);
		params.push_back (std::make_unique<AudioParameterFloat> ("NOISE-ATTACK",
			                                                     "Attack", 
			                                                     range, 
			                                                     0.01f, 
			                                                     "Attack",
			                                                     AudioProcessorParameter::genericParameter,
			                                                     [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 2) + " sec ";  },
			                                                     nullptr));
	}

	{
		auto range = NormalisableRange<float>(0.0001f, 1.f);
		range.setSkewForCentre(0.3f);
		params.push_back (std::make_unique<AudioParameterFloat> ("NOISE-DECAY", 
			                                                     "Decay", 
			                                                     range,
			                                                     0.4f, 
			                                                     "Decay",
			                                                     AudioProcessorParameter::genericParameter,
			                                                     [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 2) + " sec ";  },
			                                                     nullptr));
	}
	
	// MASTER section

	params.push_back (std::make_unique<AudioParameterFloat> ("MASTER-MIX", 
			                                                 "Mix", 
			                                                 NormalisableRange<float>(0.f, 1.f), 
			                                                 0.5f, 
			                                                 "Mix",
			                                                 AudioProcessorParameter::genericParameter,
			                                                 [](float value, int /*l*/) 
			                                                 {
																auto oscValue = 1 - value;
																auto noiseValue = value;
																auto oscPercentValue = juce::String::toDecimalStringWithSignificantFigures (jmap(oscValue, 0.f, 100.f), 2);
																auto noisePercentValue = juce::String::toDecimalStringWithSignificantFigures (jmap (noiseValue, 0.f, 100.f), 2);
																return (oscPercentValue + " / " + noisePercentValue);  
			                                                 },
			                                                 nullptr));

	params.push_back (std::make_unique<AudioParameterFloat> ("MASTER-DISTORT", 
			                                                 "Distort", 
			                                                 NormalisableRange<float>(0.f, 50.f),
			                                                 0.f, 
			                                                 "Distort",
			                                                 AudioProcessorParameter::genericParameter,
			                                                 [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 3);  },
			                                                 nullptr));
	
	params.push_back (std::make_unique<AudioParameterFloat> ("MASTER-LEVEL", 
			                                                 "Level", 
			                                                 NormalisableRange<float>(-96.f, 24.f), 
			                                                 0.f,
			                                                 "Level",
			                                                 AudioProcessorParameter::genericParameter,
			                                                 [](double value, int /*l*/) { return juce::String::toDecimalStringWithSignificantFigures(value, 3) + " db ";  },
			                                                 nullptr));

	return { params.begin(), params.end() };
}

//==============================================================================
const String WdAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WdAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WdAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WdAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WdAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WdAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WdAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WdAudioProcessor::setCurrentProgram (int /*index*/)
{
}

const String WdAudioProcessor::getProgramName (int /*index*/)
{
    return {};
}

void WdAudioProcessor::changeProgramName (int /*index*/, const String& /*newName*/)
{
}

//==============================================================================
void WdAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	mySynth.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
}

void WdAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WdAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void WdAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;

    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	mySynth.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
// TODO: maybe the synth itself should do this?
void WdAudioProcessor::initSynth()
{
	// Add voices to the synth
	mySynth.clearVoices();
	for (int i = 0; i < kNumVoices; i++)
	{
		mySynth.addVoice(new SynthVoice());
	}

	// Add sounds to the synth
	mySynth.clearSounds();
	mySynth.addSound(new SynthSound());
}

void WdAudioProcessor::passParamPointersToVoices()
{
	// Pass pointers to params to the synth voice
	for (int i = 0; i < mySynth.getNumVoices(); i++)
	{
		if ((myVoice = dynamic_cast<SynthVoice*> (mySynth.getVoice(i))) != nullptr)
		{
			myVoice -> setParamPointers (
				parameters.getRawParameterValue ("ATTACK"), 
				parameters.getRawParameterValue ("DECAY"),
				parameters.getRawParameterValue ("FREQ"),
				parameters.getRawParameterValue ("WAVE-TYPE"),
				parameters.getRawParameterValue ("PITCH-ENV-AMOUNT"),
				parameters.getRawParameterValue ("PITCH-ENV-RATE"),
				parameters.getRawParameterValue ("PITCH-LFO-AMOUNT"),
				parameters.getRawParameterValue ("PITCH-LFO-RATE"),
				parameters.getRawParameterValue ("FILTER-TYPE"),
				parameters.getRawParameterValue ("FILTER-CUTOFF"),
				parameters.getRawParameterValue ("FILTER-RESONANCE"),
				parameters.getRawParameterValue ("NOISE-ATTACK"),
				parameters.getRawParameterValue ("NOISE-DECAY"),
				parameters.getRawParameterValue ("MASTER-MIX"),
				parameters.getRawParameterValue ("MASTER-EQ-FREQ"),
				parameters.getRawParameterValue ("MASTER-EQ-GAIN"),
				parameters.getRawParameterValue ("MASTER-DISTORT"),
				parameters.getRawParameterValue ("MASTER-LEVEL"),
				parameters.getRawParameterValue ("MASTER-PAN")
			);
		}
	}
}

//==============================================================================
bool WdAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WdAudioProcessor::createEditor()
{
    return new WdAudioProcessorEditor (*this);
}

//==============================================================================
void WdAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	auto state = parameters.copyState();
	std::unique_ptr<XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void WdAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(parameters.state.getType()))
			parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WdAudioProcessor();
}
