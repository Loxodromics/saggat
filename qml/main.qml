import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Scene3D 2.0
import QtQuick.Window 2.11
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Saggat")

    Image {
        id: backdrop
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/textures/sky.png"
        anchors.fill: parent
    }

    Scene3D {
        id: scene3d
        anchors.fill: parent
        focus: true
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        SceneRoot {
            id: sceneRoot
        }
    }

    Button {
        id: generateButton

        text: qsTr("Generate")

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        onClicked: {
            sceneRoot.generate()
        }
    }

    MouseArea {
        id: sliderHider

        hoverEnabled: true

        anchors.top: terrainControls.top
        anchors.bottom: terrainControls.bottom
        anchors.left: terrainControls.left
        anchors.right: terrainControls.right
    }

//    PerlinControls {
//        id: terrainControls
//    }

    SimplexControls {
        id: terrainControls
    }
}
