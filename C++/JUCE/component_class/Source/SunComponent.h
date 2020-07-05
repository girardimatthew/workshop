/*
  ==============================================================================

    SunComponent.h
    Created: 24 Feb 2017 1:30:18pm
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef SUNCOMPONENT_H_INCLUDED
#define SUNCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SunComponent      :   public Component
{
public:
    SunComponent()
    {
    }
    
    ~SunComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        g.setColour(Colours::yellow);
        
        const float lineThickness = 3.0f;
        g.drawEllipse (lineThickness * 0.5f,
                       lineThickness * 0.5f,
                       getWidth() - lineThickness,
                       getHeight() - lineThickness,
                       lineThickness);
        
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SunComponent)
};

#endif  // SUNCOMPONENT_H_INCLUDED