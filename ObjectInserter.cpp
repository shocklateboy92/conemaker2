#include "ObjectInserter.h"
#include "OgreFramework.hpp"
#include "constants.h"

#include <OgreEntity.h>
#include <OgreSceneNode.h>

namespace ConeMaker {

ObjectInserter::ObjectInserter(Ogre::SceneNode *cursor)
    : m_cursorNode(cursor)
{
}

} // namespace ConeMaker

bool ConeMaker::ObjectInserter::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
        Ogre::SceneManager *sm = OgreFramework::getSingletonPtr()->m_pSceneMgr;

        // Create a separate entity for each ogre
        Ogre::Entity *troll = sm->createEntity("ogrehead.mesh");
        Ogre::Vector3 bounds = troll->getBoundingBox().getSize();
        Ogre::Real dim = std::max({bounds.x, bounds.y, bounds.z});
        Ogre::Real scale = GRID_SPACING / dim;
        bounds = bounds * scale * 0.5f;

        // Create a new scene node so our ogre doesn't move with the cursor.
        Ogre::SceneNode *node = sm->getRootSceneNode()->createChildSceneNode();
        node->setPosition(m_cursorNode->getPosition() +
                          Ogre::Vector3(GRID_SPACING * 0.5f));
        node->scale(Ogre::Vector3(scale));
        node->attachObject(troll);

        return true;
}

void ConeMaker::ObjectInserter::setup()
{
}
