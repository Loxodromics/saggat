import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {

    property real diameter: 10
    property real rotationDuration: 30000
    property vector3d upVector: Qt.vector3d(0, 1, 0)

    onRotationDurationChanged: {
        console.log("rotationDuration: " + rotationDuration)
        sphereTransformAnimation.duration = rotationDuration
        sphereTransformAnimation.restart()
    }

    TextureMaterial {
        id: planetMaterial

        texture: Texture2D {
            id: planetTexture
            minificationFilter: Texture.LinearMipMapLinear
            magnificationFilter: Texture.Linear
            wrapMode {
                x: WrapMode.Repeat
                y: WrapMode.Repeat
            }
            generateMipMaps: true
            maximumAnisotropy: 16.0
            TextureImage {
                id: planetTextureImage
                source: "qrc:/textures/planet.jpg"
            }
        }
    }

    SphereMesh {
        id: sphereMesh

        generateTangents: true
        radius: diameter

    }

    Transform {
        id: sphereTransform
        property real userAngle: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.rotate(userAngle, upVector)
            return m;
        }
    }

    QQ2.NumberAnimation {
        id: sphereTransformAnimation
        target: sphereTransform
        property: "userAngle"
        duration: rotationDuration
        from: 0
        to: 360

        loops: QQ2.Animation.Infinite
        running: true

        onDurationChanged: {
            console.log("duration: " + duration)
        }
    }

    Entity {
        id: sphereEntity
        components: [ sphereMesh, planetMaterial, sphereTransform ]
    }

}
