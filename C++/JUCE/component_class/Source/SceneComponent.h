/*
  ==============================================================================

    SceneComponent.h
    Created: 24 Feb 2017 11:27:26am
    Author:  Matteo Girardi

  ==============================================================================
*/

#ifndef SCENECOMPONENT_H_INCLUDED
#define SCENECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "FloorComponent.h"
#include "HouseComponent.h"
#include "SunComponent.h"
#include "StreetComponent.h"

class SceneComponent    :   public Component
{
public:
    SceneComponent()
    {
        addAndMakeVisible(floor);
        addAndMakeVisible(house);
        addAndMakeVisible(sun);
        addAndMakeVisible(anotherFloor);
        addAndMakeVisible(street);
    }
    
    ~SceneComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        // draw the sky
        g.fillAll(Colours::lightblue);
    }
    
    void resized() override
    {
        floor.setBounds(10, 297, 580, 5);
        house.setBounds(300, 70, 200, 220);
        sun.setBounds(520, 10, 60, 60);
        anotherFloor.setBounds(10, 350, 580, 5);
        street.setBounds(50,50,50,50);
    }
    
private:
    FloorComponent floor;
    HouseComponent house;
    FloorComponent anotherFloor;
    SunComponent sun;
    StreetComponent street;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};
#endif  // SCENECOMPONENT_H_INCLUDED