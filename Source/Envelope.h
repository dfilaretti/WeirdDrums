/*
  ==============================================================================

    Envelope.h
    Created: 16 Jan 2019 9:27:13pm
    Author:  dfila

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/**
    A very simple percussive-style envelope class.

    To use it, call setSampleRate() with the current sample rate and give it some parameters
    with setParameters() then call getNextSample() to get the envelope value to be applied
    to each audio sample or applyEnvelopeToBuffer() to apply the envelope to a whole buffer.

	Notice the envelope is "one-shot". 

*/
class Envelope
{
public:
    //==============================================================================
    Envelope()
    {
        setSampleRate (44100.0);
        setParameters ({});
    }

    //==============================================================================
    /** Holds the parameters being used by an ADSR object. */
    struct Parameters
    {
        /** Attack time in seconds. */
        float attack  = 0.1f;

        /** Decay time in seconds. */
        float decay   = 0.1f;
    };

    /** Sets the parameters that will be used by an ADSR object.

        You must have called setSampleRate() with the correct sample rate before
        this otherwise the values may be incorrect!

        @see getParameters
    */
    void setParameters (const Parameters& newParameters)
    {
        currentParameters = newParameters;

        calculateRates (newParameters);
    }

    /** Returns the parameters currently being used by an ADSR object.

        @see setParameters
    */
    const Parameters& getParameters() const    { return currentParameters; }

    /** Returns true if the envelope is in its attack, decay, sustain or release stage. */
    bool isActive() const noexcept             { return currentState != State::idle; }

    //==============================================================================
    /** Sets the sample rate that will be used for the envelope.

        This must be called before the getNextSample() or setParameters() methods.
    */
    void setSampleRate (double sampleRate)
    {
        jassert (sampleRate > 0.0);
        sr = sampleRate;
    }

    //==============================================================================
    /** Resets the envelope to an idle state. */
    void reset()
    {
        envelopeVal  = 0.0f;
		tailOff      = 0;
        currentState = State::idle;
    }

    /** Starts the attack phase of the envelope. */
    void noteOn()
    {
        if      (attackRate > 0.0f)  currentState = State::attack;
        else if (decayRate > 0.0f)   currentState = State::decay;
    }

    /** Starts the release phase of the envelope. */
    void noteOff()
    {
        if (currentState != State::idle)
        {
			if (tailOff == 0.0)
				tailOff = 1.0;
            
			currentState = State::tailOff;
        }
    }

    //==============================================================================
    /** Returns the next sample value for an ADSR object.
    */
    float getNextSample()
    {

        if (currentState == State::idle)
            return 0.0f;

        if (currentState == State::attack)
        {
            envelopeVal += attackRate;

            if (envelopeVal >= 1.0f)
            {
                envelopeVal = 1.0f;

				jassert (decayRate > 0);
				currentState = State::decay;
            }
        }
        else if (currentState == State::decay)
        {
            envelopeVal -= decayRate;

            if (envelopeVal <= 0 /*sustainLevel*/)
            {
				reset();
            }
        }
		else if (currentState == State::tailOff)
		{
			envelopeVal *= tailOff;
            tailOff     *= 0.99;

			if (tailOff <= 0.005)
				reset();
		}

        return envelopeVal;
    }

    /** This method will conveniently apply the next numSamples number of envelope values
        to an AudioBuffer.
    */
    template<typename FloatType>
    void applyEnvelopeToBuffer (AudioBuffer<FloatType>& buffer, int startSample, int numSamples)
    {
        jassert (startSample + numSamples <= buffer.getNumSamples());

        auto numChannels = buffer.getNumChannels();

        while (--numSamples >= 0)
        {
            auto env = getNextSample();

            for (int i = 0; i < numChannels; ++i)
                buffer.getWritePointer (i)[startSample] *= env;

            ++startSample;
        }
    }

private:
    //==============================================================================
    void calculateRates (const Parameters& parameters)
    {
        // need to call setSampleRate() first!
        jassert (sr > 0.0);

        attackRate  = (parameters.attack  > 0.0f ? static_cast<float> (1.0f                  / (parameters.attack * sr))  : -1.0f);
        decayRate   = (parameters.decay   > 0.0f ? static_cast<float> ((1.0f - sustainLevel) / (parameters.decay * sr))   : -1.0f);
    }

    //==============================================================================
    enum class State { idle, attack, decay, tailOff };

    State currentState = State::idle;
    Parameters currentParameters;

    double sr = 0.0;
	double tailOff = 0.0;

    float envelopeVal = 0.0f;

    float sustainLevel = 0.0f;
    float attackRate = 0.0f, decayRate = 0.0f;

};