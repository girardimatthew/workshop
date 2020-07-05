/*
  ==============================================================================

    HouseComponent.h
    Created: 24 Feb 2017 11:33:50am
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef HOUSECOMPONENT_H_INCLUDED
#define HOUSECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "WallComponent.h"
#include "RoofComponent.h"

class HouseComponent    :   public Component
{
public:
    HouseComponent()
    {
        addAndMakeVisible(wall);
        addAndMakeVisible(roof);
    }
    
    ~HouseComponent()
    {
    }
    
    void resized() override
    {
        const int separation = jlimit(2, 10, getHeight()/20);
        
        // roof.setBounds(0, 0, getWidth(), getHeight() * 0.2 - separation/2);
        // wall.setBounds(0, getHeight() * 0.20 + separation / 2, getWidth(), getHeight() * 0.80 - separation);
        
        roof.setBounds(0, 0, getWidth(), getHeight() * 0.2 - separation/2);
        wall.setBounds(0, getHeight() * 0.20 + separation / 2, getWidth(), getHeight() * 0.80 - separation);
    }
    
private:
    WallComponent wall;
    RoofComponent roof;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HouseComponent)
};

#endif  // HOUSECOMPONENT_H_INCLUDED