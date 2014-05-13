#ifndef TOOL_H
#define TOOL_H

#include <OISKeyboard.h>
#include <OISMouse.h>

namespace ConeMaker {

class Tool : public OIS::KeyListener, public OIS::MouseListener
{
public:
    virtual void setup();

    // KeyListener interface
public:
    bool keyPressed(const OIS::KeyEvent &arg) override;
    bool keyReleased(const OIS::KeyEvent &arg) override;

    // MouseListener interface
public:
    bool mouseMoved(const OIS::MouseEvent &arg) override;
    bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
    bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) override;
};

}

#endif // TOOL_H
