//|||||||||||||||||||||||||||||||||||||||||||||||

#ifndef OGRE_DEMO_HPP
#define OGRE_DEMO_HPP

//|||||||||||||||||||||||||||||||||||||||||||||||

#include "OgreFramework.hpp"

//|||||||||||||||||||||||||||||||||||||||||||||||

class DemoApp : public OIS::KeyListener
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

private:
	void setupDemoScene();
    void setupGrid();

    void runDemo();

	Ogre::SceneNode*			m_pOgreHeadNode;
	Ogre::Entity*				m_pOgreHeadEntity;

	bool						m_bShutdown;
};

//|||||||||||||||||||||||||||||||||||||||||||||||

#endif 

//|||||||||||||||||||||||||||||||||||||||||||||||