#include "ObjectInserter.h"
#include "OgreFramework.hpp"

#include <OgreSceneNode.h>

namespace ConeMaker {

ObjectInserter::ObjectInserter(Ogre::SceneNode *cursor)
    : m_cursorNode(cursor)
{
}

} // namespace ConeMaker

bool ConeMaker::ObjectInserter::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
        Ogre::Entity *troll = m_SceneMgr->createEntity("ogrehead.mesh");
        Ogre::Vector3 bounds = troll->getBoundingBox().getSize();
        Ogre::Real dim = std::max({bounds.x, bounds.y, bounds.z});
        Ogre::Real scale = GRID_SPACING / dim;
        bounds = bounds * scale * 0.5f;

        Ogre::SceneNode *sn = OgreFramework::getSingletonPtr()->m_pSceneMgr->getRootSceneNode();
        Ogre::SceneNode *node = sn->createChildSceneNode();
        node->setPosition(p.x + bounds.x, p.y + bounds.y, p.z + bounds.z);
//        node->showBoundingBox(true);
        node->scale(scale, scale, scale);
        node->attachObject(troll);
}

void ConeMaker::ObjectInserter::setup()
{
}
