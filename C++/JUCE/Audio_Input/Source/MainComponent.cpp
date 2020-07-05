#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                               public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    :   currentLevel(0.0),
        targetLevel(currentLevel)
    {
        levelSlider.setRange (0.0, 1.0);
        levelSlider.setValue ((double) currentLevel, dontSendNotification);
        levelSlider.addListener(this);
        levelSlider.setTextBoxStyle (Slider::TextBoxRight, false, 100, 20);
        levelLabel.setText ("Gain Level", dontSendNotification);
        
        addAndMakeVisible(levelSlider);
        addAndMakeVisible(levelLabel);
        
        setSize (600, 100);
        setAudioChannels (2, 2);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        if (slider == &levelSlider)
            targetLevel = (float) levelSlider.getValue();
    }

    //==============================================================================
    void prepareToPlay (int /*samplesPerBlockExpected*/, double /*sampleRate*/) override
    {
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        AudioIODevice* device = deviceManager.getCurrentAudioDevice();
        const BigInteger activeInputChannels = device->getActiveInputChannels();
        const BigInteger activeOutputChannels = device->getActiveOutputChannels();
        const int maxInputChannels = activeInputChannels.getHighestBit() + 1;
        const int maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
        
        for (int channel = 0; channel < maxOutputChannels; ++channel)
        {
            if ((!activeOutputChannels[channel]) || maxInputChannels == 0)
            {
                bufferToFill.buffer->clear(channel, bufferToFill.startSample, bufferToFill.numSamples);
            }
            else
            {
                const int actualInputChannel = channel % maxInputChannels;
                
                if (!activeOutputChannels[channel])
                {
                    bufferToFill.buffer->clear(channel, bufferToFill.startSample, bufferToFill.numSamples);
                }
                else
                {
                    const float* inBuffer = bufferToFill.buffer->getReadPointer(actualInputChannel, bufferToFill.startSample);
                    float* outBuffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
                    
                    for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
                    {
                        // outBuffer[sample] = inBuffer[sample] * random.nextFloat() * level;
                        outBuffer[sample] = inBuffer[sample];        // no noise
                    }
                }
            }
        }
        
        const float localTargetLevel = targetLevel;
        bufferToFill.buffer->applyGainRamp (bufferToFill.startSample, bufferToFill.numSamples, currentLevel, localTargetLevel);
        currentLevel = localTargetLevel;
    }

    void releaseResources() override
    {
        Logger::getCurrentLogger()->writeToLog("Releasing audio resources");
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);
    }

    void resized() override
    {
        levelLabel.setBounds (10, 10, 90, 20);
        levelSlider.setBounds (100, 10, getWidth() - 110, 20);
    }


private:
    //==============================================================================
    Random random;
    Slider levelSlider;
    Label levelLabel;
    
    float currentLevel, targetLevel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
