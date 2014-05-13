#ifndef CONEMAKER_OBJECTINSERTER_H
#define CONEMAKER_OBJECTINSERTER_H

#include "Tool.h"
#include <Ogre.h>

namespace ConeMaker {

class ObjectInserter : public Tool
{
public:
    ObjectInserter(Ogre::SceneNode *cursor);

    // MouseListener interface
public:
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

    // Tool interface
public:
    virtual void setup();

private:
    Ogre::SceneNode *m_cursorNode;
};

} // namespace ConeMaker

#endif // CONEMAKER_OBJECTINSERTER_H
