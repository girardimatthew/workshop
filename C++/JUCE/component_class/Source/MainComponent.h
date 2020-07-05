/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "SceneComponent.h"

class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible(scene);
        setSize(600, 400);                          // SceneComponent object is added as a child component
    }
    
    ~MainContentComponent()
    {
    }

    void paint (Graphics&) override
    {
    }
    
    void resized() override
    {
        scene.setBounds(0, 0, getWidth(), getHeight());
        // scene.setBounds (getLocalBounds());
    }

private:
    // SceneComponent object, it draws the actual scene
    SceneComponent scene;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

#endif  // MAINCOMPONENT_H_INCLUDED
