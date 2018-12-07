/*
  ==============================================================================

    PoseDisplay.cpp
    Created: 5 Dec 2018 3:33:18pm
    Author:  Tom Mitchell

  ==============================================================================
*/

#include "PoseDisplay.h"

PoseDisplay::PoseDisplay()
{
    startTimerHz (60);
}

void PoseDisplay::paint (Graphics& g)
{
    for (auto& p : poses)
    {
        const int poseId = p.getAddressPattern().toString().getTrailingIntValue();
        switch (poseId)
        {
            case 0:
            default: g.setColour (Colours::white);      break;
            case 1:  g.setColour (Colours::red);        break;
            case 2:  g.setColour (Colours::green);      break;
            case 3:  g.setColour (Colours::blue);       break;
            case 4:  g.setColour (Colours::purple);     break;
            case 5:  g.setColour (Colours::cyan);       break;
            case 6:  g.setColour (Colours::yellow);     break;
            case 7:  g.setColour (Colours::orange);     break;
            case 8:  g.setColour (Colours::chartreuse); break;
            case 9:  g.setColour (Colours::azure);      break;
        }
        
        for (int i = 0; (i + 2) < p.size(); i += 3)
        {
            jassert (p[i].isString());
            jassert (p[i+1].isFloat32());
            jassert (p[i+2].isFloat32());
            
            //const String partName = p[i].getString();
            const float x = p[i+1].getFloat32();
            const float y = p[i+2].getFloat32();
            
            const Rectangle<float> part ({0.f ,0.f },{10.f, 10.f});
            
            g.fillEllipse (part.withCentre ({x, y}));
        }
        p.clear();
    }
    
}

void PoseDisplay::setPose (const OSCMessage& pose)
{
    const int poseId = pose.getAddressPattern().toString().getTrailingIntValue();
    
    if (poses.size() < (poseId + 1))
        poses.resize (poseId + 1, OSCMessage ("/empty")); //arg, no default constructor in Juce
    
    //coalesce into our vector for repainting on the timer
    poses[poseId] = std::move (pose);
}

void PoseDisplay::timerCallback()
{
    repaint();
}
