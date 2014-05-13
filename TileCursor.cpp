#include "OgreFramework.hpp"
#include "TileCursor.h"
#include "constants.h"

#include <OgreManualObject.h>
#include <OgreSceneNode.h>
#include <OgreRenderOperation.h>

namespace ConeMaker {

void TileCursor::setup()
{
    OgreFramework::getSingletonPtr()->m_pLog->logMessage("Setting up tile cursor");
    Ogre::SceneManager *sm = OgreFramework::getSingletonPtr()->m_pSceneMgr;

    m_pBasePlane = sm->createManualObject(OBJ_BASE_PLANE);
    m_pBasePlane->begin(CM::BASE_MATERIAL, Ogre::RenderOperation::OT_TRIANGLE_STRIP);
    m_pBasePlane->position(0, 0, 0);
    m_pBasePlane->position(0, 0, CURSOR_SIZE);
    m_pBasePlane->position(CURSOR_SIZE, 0, 0);
    m_pBasePlane->position(CURSOR_SIZE, 0, CURSOR_SIZE);
    m_pBasePlane->end();
    m_cursorNode = sm->getRootSceneNode()->createChildSceneNode("cursorNode");
    m_cursorNode->attachObject(m_pBasePlane);

    // We want it to start off (and probably stay) at ground level
    m_activeLevel = Ogre::Plane(Ogre::Vector3::UNIT_Y, 0);
}

Ogre::SceneNode *TileCursor::getTileNode()
{
    return m_cursorNode;
}

bool TileCursor::mouseMoved(const OIS::MouseEvent &arg)
{
    const OIS::MouseState s = arg.state;
    Ogre::Viewport *vp = OgreFramework::getSingletonPtr()->m_pViewport;

    Ogre::Ray mouseRay =  OgreFramework::getSingletonPtr()->m_pCamera->getCameraToViewportRay(
                (Ogre::Real) s.X.abs / vp->getActualWidth(),
                (Ogre::Real) s.Y.abs / vp->getActualHeight());

    auto r = mouseRay.intersects(m_activeLevel);
    if (r.first) { // it actually intersects
        auto pos = mouseRay.getPoint(r.second);
        auto gridPos = Ogre::Vector3(floor(pos.x / GRID_SPACING) * GRID_SPACING,
                                     pos.y,
                                     floor(pos.z / GRID_SPACING) * GRID_SPACING);
        m_cursorNode->setPosition(gridPos);
    }

    return true;
}

} // namespace ConeMaker
