/*
  ==============================================================================

    PoseDisplay.h
    Created: 5 Dec 2018 3:33:18pm
    Author:  Tom Mitchell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class PartLabel : public Component
{
public:
    PartLabel (const String& pn) : partName ("", pn)
    {
        addAndMakeVisible (partName);
        addAndMakeVisible (xLabel);
        addAndMakeVisible (yLabel);
    }
    
    void setCoordinate (float x, float y)
    {
        xLabel.getTextValue() = String (x);
        yLabel.getTextValue() = String (y);
    }
    
    void resized() override
    {
        const int width = getWidth() / 3;
        Rectangle<int> r (getLocalBounds());
        
        partName.setBounds (r.removeFromLeft (width));
        xLabel.setBounds (r.removeFromLeft (width));
        yLabel.setBounds (r);
    }
    
private:
    Label partName;
    Label xLabel;
    Label yLabel;
};

class PoseDisplay : public Component
{
public:
    PoseDisplay (const String& poseName);
    void resized();
    void setPose (const OSCMessage& message);
    
private:
    Label poseName;
    std::vector<std::unique_ptr<PartLabel>> partLabels;
};
