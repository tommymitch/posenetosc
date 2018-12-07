/*
  ==============================================================================

    PoseDisplay.h
    Created: 5 Dec 2018 3:33:18pm
    Author:  Tom Mitchell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class PoseDisplay : public Component,
                    private Timer
{
public:
    PoseDisplay();
    void setPose (const OSCMessage& message);
    
    //Component
    void paint (Graphics& g) override;
    
private:
    //Timer
    void timerCallback() override;
    
    std::vector<OSCMessage> poses;
};
