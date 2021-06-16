/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PinkTromboneAudioProcessorEditor::PinkTromboneAudioProcessorEditor (PinkTromboneAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), valueTreeState(vts), processor (p), tractUI(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
	
	tractUI.setSize(400, 300);
	addAndMakeVisible(&tractUI);
	
	tongueX.setSliderStyle (Slider::LinearBarVertical);
	tongueX.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
	tongueX.setPopupDisplayEnabled (false, false, this);
	tongueX.setTextValueSuffix (" Tongue Index");
	addAndMakeVisible (&tongueX);
    tongueXAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "tongueX", tongueX));
	vts.addParameterListener("tongueX", this);

	tongueY.setSliderStyle (Slider::LinearBarVertical);
	tongueY.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
	tongueY.setPopupDisplayEnabled (false, false, this);
	tongueY.setTextValueSuffix (" Tongue Diameter");
	addAndMakeVisible (&tongueY);
    tongueYAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "tongueY", tongueY));
	vts.addParameterListener("tongueY", this);

	constrictionX.setSliderStyle (Slider::LinearBarVertical);
	constrictionX.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
	constrictionX.setPopupDisplayEnabled (true, false, this);
	constrictionX.setTextValueSuffix (" Constriction X");
	constrictionX.setValue(1.0);
	addAndMakeVisible (&constrictionX);
	constrictionXAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "constrictionX", constrictionX));
	vts.addParameterListener("constrictionX", this);
	
	constrictionY.setSliderStyle (Slider::LinearBarVertical);
	constrictionY.setRange(0.0, 1.0, 0.01);
	constrictionY.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
	constrictionY.setPopupDisplayEnabled (true, false, this);
	constrictionY.setTextValueSuffix (" Constriction Y");
	constrictionY.setValue(1.0);
	addAndMakeVisible (&constrictionY);
	constrictionYAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "constrictionY", constrictionY));
	vts.addParameterListener("constrictionY", this);
	
	constrictionActive.setButtonText("Constriction Active");
	addAndMakeVisible(&constrictionActive);
	constrictionActiveAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "constrictionActive", constrictionActive));
	vts.addParameterListener("constrictionActive", this);
	
	muteAudio.setButtonText("Mute");
//	addAndMakeVisible(&muteAudio);
//	muteAudio.addListener(this);
}

PinkTromboneAudioProcessorEditor::~PinkTromboneAudioProcessorEditor()
{
}

//==============================================================================
void PinkTromboneAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//	this.moveTo(this.tongueLowerIndexBound, this.innerTongueControlRadius);
}

void PinkTromboneAudioProcessorEditor::resized()
{
	tongueX.setBounds (40, 30, 20, getHeight() - 60);
	tongueY.setBounds (70, 30, 20, (getHeight() - 60) / 2);
	constrictionX.setBounds (100, 30, 20, getHeight() - 60);
	constrictionY.setBounds (130, 30, 20, getHeight() - 60);
	muteAudio.setBounds(170, 30, 100, 20);
	constrictionActive.setBounds(170, 60, 100, 20);
	tractUI.setSize(getWidth(), getHeight());
}

void PinkTromboneAudioProcessorEditor::parameterChanged(const String& parameterID, float newValue)
{
	tractUI.repaint();
}
