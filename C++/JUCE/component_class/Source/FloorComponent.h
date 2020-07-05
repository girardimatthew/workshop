/*
  ==============================================================================

    FloorComponent.h
    Created: 24 Feb 2017 11:33:40am
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef FLOORCOMPONENT_H_INCLUDED
#define FLOORCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "WallComponent.h"
#include "RoofComponent.h"

class FloorComponent    :   public Component
{
public:
    FloorComponent()
    {
    }
    
    ~FloorComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        g.setColour(Colours::green);
        g.drawLine(0, getHeight()/2, getWidth(), getHeight()/2, 5);
        // g.drawLine(0, getHeight() - 50 , getWidth(), getHeight() - 50, 3);
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FloorComponent)
};

#endif  // FLOORCOMPONENT_H_INCLUDED