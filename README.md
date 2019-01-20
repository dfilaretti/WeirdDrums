# LDS - Little Drum Synth

A simple drum synthesiser plugin inspired by the awesome [Sonic Charge Microtonic](https://soniccharge.com/microtonic), one of my favourite plugins.
All sounds are synthesised in realtime, no samples are used. 

It is written in C++ and the [JUCE](https://juce.com/) framework. 

![Waveshaper-Screenshot](media/img/screenshot-medium.png)

Audio examples (more to come!):

* [Example 1](https://dfilaretti.github.io/assets/loop1.wav)
* [Example 2](https://dfilaretti.github.io/assets/loop2.wav)
* [Example 3](https://dfilaretti.github.io/assets/loop3.wav)

## Architecture / how to use

As the Mictoronic, the architecture is quite simple. We have essentially three components

* **oscillator section**: this offers a single oscillator with a selectable waveform (currently sine, saw and square), whose amplitude is modulated by a simple "percussive style" Attack-Decay (AD) envelope. In addition, the pitch of the oscillator can also be modulated via a second AD envelope and/or a simple sine-wave LFO. More modulation options may become available in future. 

* **noise section**: this consists of a white noise generator going through a filter and finally through an AD envelope. The filter can be Low-Pass (LP), High-Pass (HP) or Band-Pass (BP) and its cutoff frequency and envelope are adjustable. 

* **master section**: this is where the _oscillator_ and _noise_ signal are mixed together (via the _mix_ slider) and some effects and global volume adjustments are applied. 

## Faq

## Todo / Contributions
