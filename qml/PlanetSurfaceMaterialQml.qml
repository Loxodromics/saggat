import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Saggat 1.0


PlanetSurfaceMaterial {
    id: root

    property real diameter: 1.0
    property real planetScale: scaleSlider.value
    property real heightScale: heightSlider.value
    property real e0: e0Slider.value
    property real e1: e1Slider.value
    property real e2: e2Slider.value
    property real coldness: coldnessSlider.value
    property real seed: seedSlider.value
    property bool displayHeight: heightMapSwitch.position

    property color maincolor: Qt.rgba(0.0, 0.0, 0.0, 1.0)
    property Sun sun

    parameters: [
        Parameter {
            name: "planetScale"
            value: root.planetScale
        },
        Parameter {
            name: "heightScale"
            value: root.heightScale
        },
        Parameter {
            name: "e0"
            value: root.e0
        },
        Parameter {
            name: "e1"
            value: root.e1
        },
        Parameter {
            name: "e2"
            value: root.e2
        },
        Parameter {
            name: "displayHeight"
            value: root.displayHeight
        },
        Parameter {
            name: "diameter"
            value: root.diameter
        },
        Parameter {
            name: "coldness"
            value: root.coldness
        },
        Parameter {
            name: "seed"
            value: root.seed
        }
    ]
}


