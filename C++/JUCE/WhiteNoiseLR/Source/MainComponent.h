/*
  ==============================================================================

    MainComponent.h
    Created: 20 Feb 2017 10:38:48pm
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public AudioAppComponent {
    public:
    //==========================================================================
    MainContentComponent();
    ~MainContentComponent();
    
    void prepareToPlay (int, double) override;
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    void releaseResources() override;
    
    void paint (Graphics&) override;
    void resized() override;
    
    private:
    Random random;
    
    Slider levelSlider_Lch;
    Slider levelSlider_Rch;
    
    Label levelLabel_Lch;
    Label levelLabel_Rch;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }



#endif  // MAINCOMPONENT_H_INCLUDED
