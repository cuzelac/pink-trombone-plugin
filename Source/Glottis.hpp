//
//  Glottis.hpp
//  PinkTrombone - VST3
//
//  Created by Samuel Tarakajian on 8/28/19.
//

#ifndef Glottis_hpp
#define Glottis_hpp

#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"

class Glottis {
public:
	Glottis(double sampleRate, AudioProcessorValueTreeState& vts);
	~Glottis();
	double runStep(double lambda, double noiseSource);
	void finishBlock();
	double getNoiseModulator();
	
private:
	void setupWaveform(double lambda);
	double normalizedLFWaveform(double t);

	AudioProcessorValueTreeState& valueTreeState;

	// Parameters that live inside valueTreeState
	std::atomic<float>* autoWobble = nullptr;
	std::atomic<float>* UIFrequency = nullptr;
	std::atomic<float>* UITenseness = nullptr;
	
	double sampleRate;
	double timeInWaveform;
	double frequency, oldFrequency, newFrequency, smoothFrequency;
	double oldTenseness, newTenseness;
	double waveformLength;
	double Rd;
	double alpha;
	double E0;
	double epsilon;
	double shift;
	double Delta;
	double Te;
	double omega;
	double totalTime;
	double intensity, loudness;
	double vibratoAmount;
	double vibratoFrequency;
	bool isTouched;
	bool alwaysVoice;
};

#endif /* Glottis_hpp */
