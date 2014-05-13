#ifndef CONEMAKER_TILECURSOR_H
#define CONEMAKER_TILECURSOR_H

#include "Tool.h"
#include <Ogre.h>

namespace ConeMaker {

class TileCursor : public Tool
{
public:
    static const constexpr auto OBJ_BASE_PLANE = "basePlane";

    void setup();
    Ogre::SceneNode* getTileNode();

    // MouseListener interface
public:
    virtual bool mouseMoved(const OIS::MouseEvent &arg);

private:
    Ogre::ManualObject  *m_pBasePlane;
    Ogre::SceneNode     *m_cursorNode;

    Ogre::Plane m_activeLevel;
};

} // namespace ConeMaker

namespace CM = ConeMaker;

#endif // CONEMAKER_TILECURSOR_H
