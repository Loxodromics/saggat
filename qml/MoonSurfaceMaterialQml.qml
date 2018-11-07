import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Saggat 1.0


MoonSurfaceMaterial {
    id: root

    property real diameter: 1.0
    property real moonScale: 0.5
    property real heightScale: 1.0
    property real e0: 1.0
    property real e1: 0.7
    property real e2: 0.5
    property real seed: 123

    property Sun sun

    parameters: [
        Parameter {
            name: "moonScale"
            value: root.moonScale
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
            name: "diameter"
            value: root.diameter
        },
        Parameter {
            name: "seed"
            value: root.seed
        }
    ]
}


