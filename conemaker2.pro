TEMPLATE = app
TARGET = conemaker2

DEFINES -= UNICODE
CONFIG -= qt
CONFIG += c++11

unix {
    # You may need to change this include directory
    INCLUDEPATH += /usr/include/OGRE
    INCLUDEPATH += /usr/include/OGRE/Overlay
    INCLUDEPATH += /usr/include/OIS
    CONFIG += link_pkgconfig
    PKGCONFIG += OGRE
}
win32 {
    LIBS *= user32.lib
    LIBS += -L$(OGRE_HOME)\\boost\\lib
    release:LIBS += -L$(OGRE_HOME)\\lib\\release
    debug:LIBS += -L$(OGRE_HOME)\\lib\\debug
    INCLUDEPATH += $(OGRE_HOME)\\include
    INCLUDEPATH += $(OGRE_HOME)\\include\\OIS
    INCLUDEPATH += $(OGRE_HOME)\\include\\OGRE
    INCLUDEPATH += $(OGRE_HOME)\\boost
    # If you are using Ogre 1.9 also include the following line:
    INCLUDEPATH += $(OGRE_HOME)\\include\\OGRE\\Overlay
}
debug {
    TARGET = $$join(TARGET,,,d)
    #LIBS *= -lOgreMain_d -lOIS_d
    # If you are using Ogre 1.9 also include -lOgreOverlay_d, like this:
    LIBS *= -lOgreMain -lOIS -lOgreOverlay
    LIBS *= -lboost_system
}
release {
    LIBS *= -lOgreMain -lOIS
    # If you are using Ogre 1.9 also include -lOgreOverlay, like this:
    LIBS *= -lOgreMain -lOIS -lOgreOverlay
}

HEADERS += \
    OgreFramework.hpp \
    DemoApp.hpp \
    TileCursor.h \
    constants.h \
    Tool.h \
    ObjectInserter.h \
    ToolBox.h

SOURCES += \
    OgreFramework.cpp \
    DemoApp.cpp \
    main.cpp \
    TileCursor.cpp \
    Tool.cpp \
    ObjectInserter.cpp \
    ToolBox.cpp
