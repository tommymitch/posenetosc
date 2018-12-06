/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible (poseDisplay);
    
    oscReceiver.addListener (this);
    if (oscReceiver.connect (9876) == false)
        AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                     "Connection Error !",
                                     "Could not open port 9876");
    
    setSize (600, 500); // same dimensions as PoseNet video component
}

MainComponent::~MainComponent()
{
    oscReceiver.disconnect();
}

void MainComponent::resized()
{
    poseDisplay.setBounds (getLocalBounds());
}

//==============================================================================
void MainComponent::oscMessageReceived (const OSCMessage& message)
{
    MessageManager::callAsync ([this, m = message](){poseDisplay.setPose (m);}); //pop to message thread
}
