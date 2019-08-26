import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Saggat 1.0

PlanetSurfaceMaterial {
    id: root

    property real diameter: 1.0
    property real planetScale: Values.terrainPlanetScale
    property real heightScale: Values.terrainHeightFactor
    property real e0: Values.terrainE0
    property real e1: Values.terrainE1
    property real e2: Values.terrainE2
    property real coldness: Values.terrainColdness
    property int seed: Values.terrainSeed
    property bool displayHeight: Values.displayHeight

    property color maincolor: Qt.rgba(0.0, 0.0, 0.0, 1.0)
    property Sun sun

    parameters: [
        Parameter {
            name: "planetScale"
            value: Values.terrainPlanetScale
        },
        Parameter {
            name: "heightScale"
            value: Values.terrainHeightFactor
        },
        Parameter {
            name: "e0"
            value: Values.terrainE0
        },
        Parameter {
            name: "e1"
            value: Values.terrainE1
        },
        Parameter {
            name: "e2"
            value: Values.terrainE2
        },
        Parameter {
            name: "displayHeight"
            value: Values.terrainDisplayHeight
        },
        Parameter {
            name: "diameter"
            value: root.diameter
        },
        Parameter {
            name: "coldness"
            value: Values.terrainColdness
        },
        Parameter {
            name: "seed"
            value: Values.terrainSeed
        }
    ]
}


