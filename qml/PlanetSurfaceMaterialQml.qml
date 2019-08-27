import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Saggat 1.0

PlanetSurfaceMaterial {
    id: root

    property real diameter: 1.0

    property color maincolor: Qt.rgba(0.0, 0.0, 0.0, 1.0)
    property Sun sun

    QmlValues {
        id: values
    }

    parameters: [
        Parameter {
            name: "planetScale"
            value: values.terrainPlanetScale
        },
        Parameter {
            name: "heightScale"
            value: values.terrainHeightFactor
        },
        Parameter {
            name: "e0"
            value: values.terrainE0
        },
        Parameter {
            name: "e1"
            value: values.terrainE1
        },
        Parameter {
            name: "e2"
            value: values.terrainE2
        },
        Parameter {
            name: "displayHeight"
            value: values.terrainDisplayHeight
        },
        Parameter {
            name: "diameter"
            value: root.diameter
        },
        Parameter {
            name: "coldness"
            value: values.terrainColdness
        },
        Parameter {
            name: "seed"
            value: values.terrainSeed
        },
        Parameter {
            name: "seaLevel"
            value: values.terrainSeaLevel
        }

    ]
}


