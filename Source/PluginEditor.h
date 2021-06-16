/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "TractUI.hpp"

//==============================================================================
/**
*/
class PinkTromboneAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener, private ToggleButton::Listener
{
public:
    PinkTromboneAudioProcessorEditor (PinkTromboneAudioProcessor&, AudioProcessorValueTreeState&);
    ~PinkTromboneAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    AudioProcessorValueTreeState& valueTreeState;

	// TODO: remove all references to pre-ValueTreeState callbacks and variables
	void sliderValueChanged (Slider* slider) override;
	void buttonClicked (Button* button) override;
	void buttonStateChanged (Button* button) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PinkTromboneAudioProcessor& processor;

    Slider tongueX;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> tongueXAttachment;

    Slider tongueY;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> tongueYAttachment;
    
	Slider constrictionX;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> constrictionXAttachment;

	Slider constrictionY;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> constrictionYAttachment;

	ToggleButton constrictionActive;
	ToggleButton muteAudio;
	TractUI tractUI;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PinkTromboneAudioProcessorEditor)
};
