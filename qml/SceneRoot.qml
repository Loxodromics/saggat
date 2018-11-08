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
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: camera
                clearColor: "transparent"
            }
        },
        InputSettings {

        }
    ]

    OrbitCameraController {
            id: orbitCameraController

            camera: camera
            linearSpeed: 0.0
        }

    MouseDevice {
        id: mouseDevice
    }

    MouseHandler {
        id: mouseHander

        sourceDevice: mouseDevice

        onWheel: {
            if (wheel.angleDelta.y < 0) {
                camera.position.y += 2
                camera.position.z += 3
            }
            else {
                camera.position.y -= 2
                camera.position.z -= 3
            }
        }
    }

    Entity {
        DirectionalLight {
            id: directional
            worldDirection: Qt.vector3d(-0.3, -0.1, -0.3).normalized();
            color: "#FFFFFFFF"
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
