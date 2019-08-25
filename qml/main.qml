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

        anchors.top: sliderLayout.top
        anchors.bottom: sliderLayout.bottom
        anchors.left: sliderLayout.left
        anchors.right: sliderLayout.right
    }

    ColumnLayout {
        id: sliderLayout

        visible: sliderHider.containsMouse

        Slider {
            id: seedSlider
            value: Values.terrainSeed
            from: 0
            to: 1000
            stepSize: 1

            onValueChanged: {
                Values.terrainSeed = value
            }
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
            value: Values.terrainHeightFactor
            from: 0.01
            to: 2
            stepSize: 0.01

            onValueChanged: {
                Values.terrainHeightFactor = value
            }
        }
        Slider {
            id: coldnessSlider
            value: 0.5
            from: 0
            to: 1
            stepSize: 0.01

            onValueChanged: {
//                Values.terrainHeightFactor = value
            }
        }
        Slider {
            id: e0Slider
            value: Values.terrainE0

            onValueChanged: {
                Values.terrainE0 = value
            }
        }
        Slider {
            id: e1Slider
            value: Values.terrainE1

            onValueChanged: {
                Values.terrainE1 = value
            }
        }
        Slider {
            id: e2Slider
            value: Values.terrainE2

            onValueChanged: {
                Values.terrainE2 = value
            }
        }
        Slider {
            id: expSlider
            value: Values.terrainExp
            from: 0.001
            to: 4

            onValueChanged: {
                Values.terrainExp = value
            }
        }
        Switch {
            id: heightMapSwitch
        }
    }
}
