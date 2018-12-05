/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    for (int i = 0; i < numPoses; i++)
    {
        poseDisplays.push_back (std::make_unique<PoseDisplay> ("Pose " + String (i)));
        addAndMakeVisible (*poseDisplays[i]);
    }
    
    oscReceiver.addListener (this);
    if (oscReceiver.connect (9876) == false)
        AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                     "Connection Error !",
                                     "Could not open port 9876");
    
    setSize (1200, 400);
}

MainComponent::~MainComponent()
{
    oscReceiver.disconnect();
}

void MainComponent::resized()
{
    const int width = getWidth() / numPoses;
    Rectangle<int> r (getLocalBounds());
    
    for (auto& p : poseDisplays)
        p->setBounds (r.removeFromLeft (width));
}

//==============================================================================
void MainComponent::oscMessageReceived (const OSCMessage& message)
{
    const int poseId = message.getAddressPattern().toString().getTrailingIntValue();
    poseDisplays[poseId]->setPose (message);
}
