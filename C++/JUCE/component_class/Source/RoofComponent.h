/*
  ==============================================================================

    RoofComponent.h
    Created: 24 Feb 2017 11:53:29am
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef ROOFCOMPONENT_H_INCLUDED
#define ROOFCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class RoofComponent     :   public Component
{
public:
    RoofComponent()
    {
    }
    
    ~RoofComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        g.setColour (Colours::red);
        Path roof;
        roof.addTriangle(0, getHeight(), getWidth(), getHeight(), getWidth()/2, 0);
        g.fillPath(roof);
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoofComponent)
};

#endif  // ROOFCOMPONENT_H_INCLUDED