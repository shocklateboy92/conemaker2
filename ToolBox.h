#ifndef CONEMAKER_TOOLBOX_H
#define CONEMAKER_TOOLBOX_H

#include "Tool.h"

namespace ConeMaker {

class ToolBox : public Tool
{
public:
    ToolBox(std::vector<ConeMaker::Tool*> boxTools);

private:
    ConeMaker::Tool *m_activeTool;
    std::vector<ConeMaker::Tool*> m_tools;

    // MouseListener interface
public:
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

    // KeyListener interface
public:
    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
};

} // namespace ConeMaker

#endif // CONEMAKER_TOOLBOX_H
