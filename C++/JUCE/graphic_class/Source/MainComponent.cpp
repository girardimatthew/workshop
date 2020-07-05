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
//==============================================================================
MainContentComponent::~MainContentComponent()
{
}
//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::lightblue);
    
    g.setColour (Colours::darkblue);
    g.setFont(Font ("Times New Roman", 20.0f, Font::bold | Font::italic));
    //g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    g.drawText ("Hello World!", 20, 40, 200, 40, true);
    
    g.setColour (Colours::black);
    g.setFont(Font ("Times New Roman", 30.0f, Font::underlined | Font::italic));
    g.drawText ("Ciao Mondo!", 20, 80, 110, 40, true);
    
    g.setFont(Font ("Times New Roman", 15.0f, Font::italic));
    g.drawMultiLineText("Multiple lines examples", 20, 150, 55);
    
    // Draw line
    g.setColour (Colours::green);
    g.drawLine (10, 300, 590, 300, 5);
    
    // Dashed Line
    float dashPattern[2] = {8.0, 8.0};
    Line<float> dashedLine (10, 310, 590, 310);
    g.setColour(Colours::green);
    g.drawDashedLine(dashedLine, dashPattern, 2, 2.0);
    
    // Draw arrow line
    Line<float> arrowLine (10, 330, 590, 330);
    g.setColour(Colours::darkblue);
    g.drawArrow(arrowLine, 3.0, 12.0, 12.0);
    
    // Draw rectangle
    // g.setColour (Colours::sandybrown);
    // g.drawRect (300, 120, 200, 170, 3);
    // g.fillRect (300, 120, 200, 170);
    
    // Draw rectangle
    // more convenient class
    Rectangle<int> house (300, 120, 200, 170);
    // g.setColour (Colours::deeppink);
    g.fillCheckerBoard(house, 30, 10, Colours::sandybrown, Colours::saddlebrown);
    // g.fillRect (house);
    
    // Rounded rectangle
    g.setColour (Colours::darkgrey);
    g.drawRoundedRectangle(200, 120, 50, 50, 5, 5);
    g.fillRect(200, 120, 50, 50);
    
    // Drawing circles
    g.setColour (Colours::yellow);
    g.drawEllipse (530, 10, 60, 60, 3);
    
    // Write a wrapper function around the Graphics::drawEllipse() function for drawing circles more conveniently. The function
    // should take the coordinates of a point and a radius, and then draw a circle with the centre at this point and the given
    // radius.
    // drawCircle(g, 450, 10, 4.0);

    // Drawing other polygons
    g.setColour (Colours::red);
    Path roof;
    roof.addTriangle (300, 110, 500, 110, 400, 70);
    g.fillPath (roof);
    
}
//==============================================================================
void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
//==============================================================================
//void drawCircle(Graphics& g, float x, float y, float radius) {
//    g.setColour(Colours::black);
//    g.drawEllipse(x, y, radius, radius, 3);
//}
