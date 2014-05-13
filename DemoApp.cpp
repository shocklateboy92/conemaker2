//|||||||||||||||||||||||||||||||||||||||||||||||

#include "DemoApp.hpp"
#include "Nothing.h"
#include "ObjectInserter.h"
#include "ToolBox.h"

#include <OgreLight.h>
#include <OgreWindowEventUtilities.h>
#include <OgreSceneNode.h>

//|||||||||||||||||||||||||||||||||||||||||||||||

DemoApp::DemoApp()
{
	m_pOgreHeadNode			= 0;
	m_pOgreHeadEntity		= 0;

}

//|||||||||||||||||||||||||||||||||||||||||||||||

DemoApp::~DemoApp()
{
	delete OgreFramework::getSingletonPtr();
}

//|||||||||||||||||||||||||||||||||||||||||||||||

void DemoApp::startDemo()
{
	new OgreFramework();
    if(!OgreFramework::getSingletonPtr()->initOgre("DemoApp v1.0", this, this))
		return;
	
	m_bShutdown = false;

	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Demo initialized!");

	setupDemoScene();
	runDemo();
}

//|||||||||||||||||||||||||||||||||||||||||||||||

void DemoApp::setupDemoScene()
{
    auto sm = OgreFramework::getSingletonPtr()->m_pSceneMgr;

    auto skyColor = Ogre::ColourValue(60.0f/255,130.0f/255,1.0f);
    OgreFramework::getSingletonPtr()->m_pViewport->setBackgroundColour(skyColor);

    sm->createLight("Light")->setPosition(75, 75, 75);

    setupGrid();

    CM::TileCursor *cursor = new CM::TileCursor;
    cursor->setup();

    m_tools = {
        cursor,
        new CM::ToolBox({
            new CM::Nothing,
            new CM::ObjectInserter(cursor->getTileNode())
        })
    };
}

void DemoApp::setupGrid()
{
    auto sm = OgreFramework::getSingletonPtr()->m_pSceneMgr;

    // Render the bottom grid using lines
    Ogre::ManualObject *man = sm->createManualObject("grid");
    man->begin(BASE_MATERIAL, Ogre::RenderOperation::OT_LINE_LIST);
    for (Ogre::Real i = -GRID_SIZE + GRID_SPACING; i < GRID_SIZE; i += GRID_SPACING) {
        man->position(i, 0, -GRID_SIZE);
        man->position(i, 0, GRID_SIZE);

        man->position(-GRID_SIZE, 0, i);
        man->position(GRID_SIZE, 0, i);
    }
    man->end();
    sm->getRootSceneNode()->attachObject(man);
}

//|||||||||||||||||||||||||||||||||||||||||||||||

void DemoApp::runDemo()
{
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Start main loop...");
	
	double timeSinceLastFrame = 0;
	double startTime = 0;

	OgreFramework::getSingletonPtr()->m_pRenderWnd->resetStatistics();
	
	while(!m_bShutdown && !OgreFramework::getSingletonPtr()->isOgreToBeShutDown()) 
	{
		if(OgreFramework::getSingletonPtr()->m_pRenderWnd->isClosed())m_bShutdown = true;

		Ogre::WindowEventUtilities::messagePump();
	
		if(OgreFramework::getSingletonPtr()->m_pRenderWnd->isActive())
		{
			startTime = OgreFramework::getSingletonPtr()->m_pTimer->getMillisecondsCPU();
					
			OgreFramework::getSingletonPtr()->m_pKeyboard->capture();
			OgreFramework::getSingletonPtr()->m_pMouse->capture();

			OgreFramework::getSingletonPtr()->updateOgre(timeSinceLastFrame);
			OgreFramework::getSingletonPtr()->m_pRoot->renderOneFrame();
		
			timeSinceLastFrame = OgreFramework::getSingletonPtr()->m_pTimer->getMillisecondsCPU() - startTime;
		}
		else
		{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            Sleep(1000);
#else
            sleep(1);
#endif
		}
	}

	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Main loop quit");
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Shutdown OGRE...");
}

//|||||||||||||||||||||||||||||||||||||||||||||||

bool DemoApp::keyPressed(const OIS::KeyEvent &keyEventRef)
{
    for (auto t : m_tools) {
        t->keyPressed(keyEventRef);
    }

	OgreFramework::getSingletonPtr()->keyPressed(keyEventRef);

	return true;
}

//|||||||||||||||||||||||||||||||||||||||||||||||

bool DemoApp::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    for (auto t : m_tools) {
        t->keyReleased(keyEventRef);
    }

	OgreFramework::getSingletonPtr()->keyReleased(keyEventRef);
	
    return true;
}

bool DemoApp::mouseMoved(const OIS::MouseEvent &arg)
{
    for (auto t : m_tools) {
        t->mouseMoved(arg);
    }
    return OgreFramework::getSingletonPtr()->mouseMoved(arg);
}

bool DemoApp::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    for (auto t : m_tools) {
        t->mousePressed(arg, id);
    }
    return OgreFramework::getSingletonPtr()->mousePressed(arg, id);
}

bool DemoApp::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    for (auto t : m_tools) {
        t->mouseReleased(arg, id);
    }
    return OgreFramework::getSingletonPtr()->mouseReleased(arg, id);
}

//|||||||||||||||||||||||||||||||||||||||||||||||
