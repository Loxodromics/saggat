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

    ColumnLayout {

        Slider {
            id: seedSlider
            value: 289.0
            from: 0
            to: 1000
            stepSize: 0.001
        }
        Slider {
            id: scaleSlider
            value: 0.08
            from: 0
            to: 1
            stepSize: 0.001
        }
        Slider {
            id: heightSlider
            value: 1.5
            from: 0
            to: 4
            stepSize: 0.01
        }
        Slider {
            id: coldnessSlider
            value: 0.5
            from: 0
            to: 1
            stepSize: 0.01
        }
        Slider {
            id: e0Slider
            value: 1.0
        }
        Slider {
            id: e1Slider
            value: 0.5
        }
        Slider {
            id: e2Slider
            value: 0.25
        }
        Switch {
            id: heightMapSwitch
        }
    }
}
