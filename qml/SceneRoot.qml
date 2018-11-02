import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0
import Qt3D.Input 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: sceneRoot

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        nearPlane : 0.1
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 40.0, 60.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, -3.0, 0.0 )
    }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: camera
                clearColor: "transparent"
            }
        },
        InputSettings { }
    ]

    Entity {
        DirectionalLight {
            id: directional
            worldDirection: Qt.vector3d(-0.3, -0.1, -0.5).normalized();
            color: "#fff2a3"
            intensity: 0.79
        }
        Transform {
            id: lightpostransform
            translation: Qt.vector3d(4000.0, 1000.0, 6000.0)
        }
        components: [lightpostransform, directional]
    }

    PlanetarySystem {
        id: planetarySystem
        sun: sun
    }

    Sun {
        id: sun
    }

    function generate() {
        planetarySystem.generate()
    }
}
