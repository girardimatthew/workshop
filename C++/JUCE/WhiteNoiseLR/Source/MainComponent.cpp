/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

MainContentComponent::MainContentComponent() {
    levelSlider_Lch.setRange(0.0, 1.0);
    levelSlider_Lch.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    levelLabel_Lch.setText("Noise Level_Lch", dontSendNotification);
    
    levelSlider_Rch.setRange(0.0, 1.0);
    levelSlider_Rch.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    levelLabel_Rch.setText("Noise Level_Rch", dontSendNotification);
    
    addAndMakeVisible(levelSlider_Lch);
    addAndMakeVisible(levelLabel_Lch);
    
    addAndMakeVisible(levelSlider_Rch);
    addAndMakeVisible(levelLabel_Rch);
    
    setSize (800, 100);
    setAudioChannels (0, 2);        // specify the number of input and output channels that we want to open
}

MainContentComponent::~MainContentComponent() {
    shutdownAudio();
}

void MainContentComponent::prepareToPlay (int /*samplesPerBlockExpected*/, double /*sampleRate*/) {
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.
    
    // For more details, see the help for AudioProcessor::prepareToPlay()
    // String message;
    // message << "Preparing to play audio..." << newLine;
    // message << " samplePerBlockExpected = " << samplesPerBlockExpected << newLine;
    // message << " sampleRate = " << sampleRate;
    // Logger::getCurrentLogger()->writeToLog(message);
}

//void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
//    // Your audio-processing code goes here!
//    // For more details, see the help for AudioProcessor::getNextAudioBlock()
//    // Right now we are not producing any data, in which case we need to clear the buffer
//    // (to prevent the output of random noise)
//    // bufferToFill.clearActiveBufferRegion();
//    
//    const float level_Lch = (float) levelSlider_Lch.getValue();
//    const float level_Rch = (float) levelSlider_Rch.getValue();
//    
//    const float levelScale_Lch = level_Lch * 2.0f;
//    const float levelScale_Rch = level_Rch * 2.0f;
//    
//    for (int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel){
//        
//        if (channel==0) {
//            // Get a pointer to the start sample in the buffer for this audio output channel
//            float* const buffer_Lch = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
//        
//            // Fill the required number of samples with noise between -1.0 and +0.1
//            for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
//                // const float noise = random.nextFloat() * 2.0f - 1.0f;
//                buffer_Lch[sample] = random.nextFloat() * levelScale_Lch - level_Lch;
//            }
//        }
//    
//        if (channel==1){
//            // Get a pointer to the start sample in the buffer for this audio output channel
//            float* const buffer_Rch = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
//            
//            // Fill the required number of samples with noise between -1.0 and +0.1
//            for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
//                // const float noise = random.nextFloat() * 2.0f - 1.0f;
//                buffer_Rch[sample] = random.nextFloat() * levelScale_Rch - level_Rch;
//            }
//        }
//    }
//}

void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
    // Your audio-processing code goes here!
    // For more details, see the help for AudioProcessor::getNextAudioBlock()
    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    // bufferToFill.clearActiveBufferRegion();
    
    const float level_Lch = (float) levelSlider_Lch.getValue();
    const float level_Rch = (float) levelSlider_Rch.getValue();
    
    const float levelScale_Lch = level_Lch * 2.0f;
    const float levelScale_Rch = level_Rch * 2.0f;
    
    float* const buffer_Lch = bufferToFill.buffer->getWritePointer(0);
    float* const buffer_Rch = bufferToFill.buffer->getWritePointer(1);

    // Fill the required number of samples with noise between -1.0 and +0.1
    for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
        // const float noise = random.nextFloat() * 2.0f - 1.0f;
        buffer_Lch[sample] = random.nextFloat() * levelScale_Lch - level_Lch;
        buffer_Rch[sample] = random.nextFloat() * levelScale_Rch - level_Rch;
    }
}

void MainContentComponent::releaseResources() {
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.
    // For more details, see the help for AudioProcessor::releaseResources()
    Logger::getCurrentLogger()->writeToLog ("Releasing audio resources");
}

void MainContentComponent::paint (Graphics& g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::lightgrey);
    // You can add your drawing code here!
}

void MainContentComponent::resized() {
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    levelSlider_Lch.setBounds(100, 10, getWidth() - 110, 20);
    levelLabel_Lch.setBounds(10, 10, 90, 20);
    
    levelSlider_Rch.setBounds(100, 50, getWidth() - 110, 20);
    levelLabel_Rch.setBounds(10, 50, 90, 20);
}