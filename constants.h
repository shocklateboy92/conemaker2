#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Ogre.h>

namespace ConeMaker {
    static const constexpr Ogre::Real GRID_SIZE = 100.0f;
    static const constexpr Ogre::Real GRID_SPACING = 10.0f;
    static const constexpr Ogre::Real CURSOR_SIZE = GRID_SPACING;
    static const constexpr Ogre::Real CONE_SIZE = 60.0f;

    static const constexpr auto BASE_MATERIAL = "BaseWhiteNoLighting";
}

#endif // CONSTANTS_H
