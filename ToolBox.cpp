#include "ToolBox.h"

namespace ConeMaker {

ToolBox::ToolBox(std::vector<Tool *> boxTools)
    : m_activeTool(boxTools.front()), m_tools(boxTools)
{
}

} // namespace ConeMaker


bool ConeMaker::ToolBox::mouseMoved(const OIS::MouseEvent &arg)
{
    return m_activeTool->mouseMoved(arg);
}

bool ConeMaker::ToolBox::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    return m_activeTool->mousePressed(arg, id);
}

bool ConeMaker::ToolBox::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    return m_activeTool->mouseReleased(arg, id);
}

bool ConeMaker::ToolBox::keyPressed(const OIS::KeyEvent &arg)
{
    return m_activeTool->keyPressed(arg);
}

bool ConeMaker::ToolBox::keyReleased(const OIS::KeyEvent &arg)
{
    bool result = m_activeTool->keyReleased(arg);

    // Change after the key has been processsed, so we don't have tools still up
    if (OIS::KC_1 <= arg.key && arg.key < OIS::KC_1 + m_tools.size()) {
        m_activeTool = m_tools[OIS::KC_1 - arg.key];
    }

    return result;
}
