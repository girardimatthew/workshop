/*
  ==============================================================================

    WallComponent.h
    Created: 24 Feb 2017 11:53:40am
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef WALLCOMPONENT_H_INCLUDED
#define WALLCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class WallComponent     :   public Component
{
public:
    WallComponent()
    {
    }
    
    ~WallComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        g.fillCheckerBoard(getLocalBounds(), 30, 10, Colours::sandybrown, Colours::saddlebrown);
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WallComponent)
};

#endif  // WALLCOMPONENT_H_INCLUDED
