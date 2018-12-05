/*
  ==============================================================================

    PoseDisplay.cpp
    Created: 5 Dec 2018 3:33:18pm
    Author:  Tom Mitchell

  ==============================================================================
*/

#include "PoseDisplay.h"

const StringArray partNames = {"nose",
                               "leftEye",
                               "rightEye",
                               "leftEar",
                               "rightEar",
                               "leftShoulder",
                               "rightShoulder",
                               "leftElbow",
                               "rightElbow",
                               "leftWrist",
                               "rightWrist",
                               "leftHip",
                               "rightHip",
                               "leftKnee",
                               "rightKnee",
                               "leftAnkle",
                               "rightAnkle"};

PoseDisplay::PoseDisplay (const String& pn) : poseName ("",pn)
{
    addAndMakeVisible (poseName);
    for (int i = 0; i < partNames.size(); i++)
    {
        partLabels.push_back (std::make_unique<PartLabel>(partNames[i]));
        addAndMakeVisible (*partLabels[i]);
    }
}

void PoseDisplay::resized()
{
    const int height = getHeight() / (partLabels.size() + 1);
    Rectangle<int> r (getLocalBounds());

    poseName.setBounds (r.removeFromTop(height));
    for (auto& l : partLabels)
        l->setBounds (r.removeFromTop (height));
}

void PoseDisplay::setPose (const OSCMessage& message)
{
    for (int i = 0; i + 2 < message.size(); i += 3)
    {
        jassert (message[i].isString());
        jassert (message[i+1].isFloat32());
        jassert (message[i+2].isFloat32());
        
        const String partName = message[i].getString();
        const float x = message[i+1].getFloat32();
        const float y = message[i+2].getFloat32();
        
        partLabels[partNames.indexOf (partName)]->setCoordinate (x, y);
    }
}
