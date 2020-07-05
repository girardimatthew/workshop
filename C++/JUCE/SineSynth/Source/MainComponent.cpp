#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class MainContentComponent   : public AudioAppComponent,
                               public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    :   currentSampleRate(0.0),
        currentAngle(0.0),
        angleDelta(0.0),
        currentFrequency(500.0),
        targetFrequency(currentFrequency),
        currentLevel(0.0),
        targetLevel(currentLevel)
    {
        addAndMakeVisible (frequencySlider);
        addAndMakeVisible(frequencyLabel);
        frequencySlider.setRange (50.0, 5000.0);
        frequencySlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
        frequencySlider.setSkewFactorFromMidPoint (500.0);
        frequencySlider.setValue(currentFrequency);
        frequencyLabel.setText("Frequency", dontSendNotification);
        frequencySlider.addListener (this);
        
        addAndMakeVisible(levelSlider);
        addAndMakeVisible(levelLabel);
        levelSlider.setRange(0.0, 1.0);
        levelSlider.setTextBoxStyle(Slider::TextBoxRight, false, 100, 20);
        levelSlider.setValue(currentLevel);
        levelLabel.setText("Level", dontSendNotification);
        levelSlider.addListener (this);
        
        setSize (800, 100);
        setAudioChannels (0, 2);    // no input, one output
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
    void resized() override
    {
        frequencySlider.setBounds (100, 10, getWidth() - 110, 20);
        frequencyLabel.setBounds(10, 10, 90, 20);
        
        levelSlider.setBounds (100, 50, getWidth() - 110, 20);
        levelLabel.setBounds(10, 50, 90, 20);
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        if (slider == &frequencySlider)
            targetFrequency = frequencySlider.getValue();
        else if (slider == &levelSlider)
            targetLevel = levelSlider.getValue();
        
       // std::cout << targetLevel << " - " << (float) levelSlider.getValue() << "\n";
    }

    inline void updateAngleDelta()
    {
        // const double cyclePerSample = frequencySlider.getValue() / currentSampleRate;
        const double cyclePerSample = currentFrequency / currentSampleRate;
        angleDelta = cyclePerSample * 2.0 * double_Pi;
    }
    
    //==============================================================================
    void prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate) override
    {
        currentSampleRate = sampleRate;
        updateAngleDelta();
    }

    //==============================================================================
    // we need to generate the actual sine wave and write it to the output:
    // The format of this code uses a typically pattern for DSP code. We avoid conditional statements in the inner for() loop, if possible. Instead, having the condition tested outside the loop, and we use two different, but quite similar loops depending upon whether the parameter is changing.
    //==============================================================================
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // const float level = (float) levelSlider.getValue();
        
        float* const bufferL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        float* const bufferR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
        
        const double localTargetFrequency = targetFrequency;
        const float  localTargetLevel = targetLevel;
        
        const float levelIncrement = (localTargetLevel - currentLevel) / bufferToFill.numSamples;
        
        if (localTargetFrequency != currentFrequency)
        {
            const double frequencyIncrement = (localTargetFrequency - currentFrequency) / bufferToFill.numSamples;
            
            for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
            {
                const float currentSample = (float) std::sin(currentAngle);
                currentFrequency += frequencyIncrement;
                updateAngleDelta();
                currentAngle += angleDelta;
                level += levelIncrement;
                const float localSample = currentSample * level;
                bufferL[sample] = localSample;
                bufferR[sample] = localSample;
            }
            
            currentFrequency = localTargetFrequency;
        }
        else
        {
            // Fill the required number of samples with noise between -1.0 and +0.1
            for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
            {
                const float currentSample = (float) std::sin(currentAngle);
                currentAngle += angleDelta;
                level += levelIncrement;
                const float localSample = currentSample * level;
                bufferL[sample] = localSample;
                bufferR[sample] = localSample;
            }
        }
        currentLevel = localTargetLevel;
    }

    void releaseResources() override
    {
        Logger::getCurrentLogger()->writeToLog ("Releasing audio resources");
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);
    }

private:
    //==============================================================================
    Slider frequencySlider;
    Slider levelSlider;
    
    Label levelLabel;
    Label frequencyLabel;
    
    double currentSampleRate, currentAngle, angleDelta;
    double currentFrequency, targetFrequency;
    float currentLevel, targetLevel;
    float level;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
