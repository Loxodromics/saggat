QT += qml quick \
    concurrent \
    3dcore 3drender 3dinput \
    3dquick 3dquickrender 3dquickinput 3dquickextras
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/common/qmlvalues.cpp \
        src/common/values.cpp \
        src/generation/elevationprovider.cpp \
        src/generation/generator.cpp \
        src/generation/perlinnoiseelevationprovider.cpp \
        src/generation/simplexnoiseelevationprovider.cpp \
        src/graphics/geospheregeometry.cpp \
        src/graphics/geospheremesh.cpp \
        src/graphics/moonsurfacematerial.cpp \
        src/graphics/planetsurfacematerial.cpp \
        src/thirdparty/perlinnoise.cpp \
        src/thirdparty/simplexnoise.cpp

RESOURCES += qml.qrc \
    ../saggat/resource/textures.qrc \
    ../saggat/resource/shader.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        src/common/qmlvalues.h \
        src/common/values.h \
        src/generation/elevationprovider.h \
        src/generation/generator.h \
        src/generation/perlinnoiseelevationprovider.h \
        src/generation/simplexnoiseelevationprovider.h \
        src/graphics/geospheregeometry.h \
        src/graphics/geospheremesh.h \
        src/graphics/moonsurfacematerial.h \
        src/graphics/planetsurfacematerial.h \
        src/thirdparty/perlinnoise.h \
        src/thirdparty/simplexnoise.h
