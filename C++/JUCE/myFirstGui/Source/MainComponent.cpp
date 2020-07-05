/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour(setR, setG, setB));
    g.setFont (Font (16.0f));
    g.setColour (Colours::darkblue);
    g.drawText ("Hello World! " + currentSizeAsString, getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    currentSizeAsString = String (getWidth()) + " x " + String (getHeight());
    setR = getWidth() % 255;
    setG = getHeight() % 255;
    setB = (getWidth() - getHeight()) % 255;
}
