#include "OgreFramework.hpp"
#include "Tool.h"

using namespace ConeMaker;

void Tool::setup()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Setting up generic tool");
}

bool Tool::keyPressed(const OIS::KeyEvent &arg)
{
}

bool Tool::keyReleased(const OIS::KeyEvent &arg)
{
}

bool Tool::mouseMoved(const OIS::MouseEvent &arg)
{
}

bool Tool::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
//    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Recieved Mouse click");
}

bool Tool::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
}
