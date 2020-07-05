/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"
#include "math.h"

//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */

MainContentComponent::MainContentComponent() {
    panSlider.setRange(0.0, 1.0);
    panSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
    panLabel.setText("Pan", dontSendNotification);
    
    addAndMakeVisible(panSlider);
    addAndMakeVisible(panLabel);
    
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

void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
    // Your audio-processing code goes here!
    // For more details, see the help for AudioProcessor::getNextAudioBlock()
    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    // bufferToFill.clearActiveBufferRegion();
    
    const float level = (float) panSlider.getValue();
    const float levelScale = 0.5f - 0.25f;
    
    for (int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel){
        
        // Get a pointer to the start sample in the buffer for this audio output channel
        float* const buffer_L = bufferToFill.buffer->getWritePointer(0);
        float* const buffer_R = bufferToFill.buffer->getWritePointer(1);
        
        const float panL = sqrt(1.0f-(level*level) - level*level);
        const float panR = sqrt(level*level + level*level);
        
        // Print to Console 
        // std::cout << panL << ", " << panR << std::endl;
        
        // Fill the required number of samples with noise between -1.0 and +0.1
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
            buffer_L[sample] = (random.nextFloat() * levelScale) * panL;
            buffer_R[sample] = (random.nextFloat() * levelScale) * panR;
        }
        
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
    panSlider.setBounds(100, 10, getWidth() - 110, 20);
    panLabel.setBounds(10, 10, 90, 20);
}