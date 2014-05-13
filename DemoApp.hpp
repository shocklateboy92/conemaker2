//|||||||||||||||||||||||||||||||||||||||||||||||

#ifndef OGRE_DEMO_HPP
#define OGRE_DEMO_HPP

//|||||||||||||||||||||||||||||||||||||||||||||||

#include "OgreFramework.hpp"
#include "TileCursor.h"

//|||||||||||||||||||||||||||||||||||||||||||||||

class DemoApp : public OIS::KeyListener, OIS::MouseListener
{
public:
    static const constexpr Ogre::Real GRID_SIZE = 100.0f;
    static const constexpr Ogre::Real GRID_SPACING = 10.0f;
    static const constexpr Ogre::Real CURSOR_SIZE = GRID_SPACING;
    static const constexpr Ogre::Real CONE_SIZE = 60.0f;

    static const constexpr auto BASE_MATERIAL = "BaseWhiteNoLighting";

    DemoApp();
	~DemoApp();

	void startDemo();
	
	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);
    bool mouseMoved(const OIS::MouseEvent &arg);
    bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

private:
	void setupDemoScene();
    void setupGrid();

    void runDemo();

	Ogre::SceneNode*			m_pOgreHeadNode;
	Ogre::Entity*				m_pOgreHeadEntity;

	bool						m_bShutdown;

    std::vector<CM::Tool*>      m_tools;
};

//|||||||||||||||||||||||||||||||||||||||||||||||

#endif 

//|||||||||||||||||||||||||||||||||||||||||||||||
