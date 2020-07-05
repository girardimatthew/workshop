/*
  ==============================================================================

    StreetComponent.h
    Created: 24 Feb 2017 1:46:16pm
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef STREETCOMPONENT_H_INCLUDED
#define STREETCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class StreetComponent   :   public Component
{
public:
    StreetComponent()
    {
        addAndMakeVisible(house);
    }
    
    ~StreetComponent()
    {
    }
    
    void resized() override
    {
    }
    
    
private:
    HouseComponent house;
};

#endif  // STREETCOMPONENT_H_INCLUDED