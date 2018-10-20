import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    property real radius: 10
    property real rotationDuration: 30000
    property vector3d upVector: Qt.vector3d(0, 1, 0)
    property real rotationTarget: 360

    onRotationDurationChanged: {
        sphereTransformAnimation.duration = rotationDuration
        sphereTransformAnimation.restart()
    }

    onRotationTargetChanged: {
        sphereTransformAnimation.to = rotationTarget
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
        radius: root.radius
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
        to: rotationTarget

        loops: QQ2.Animation.Infinite
        running: true
    }

    Entity {
        id: sphereEntity
        components: [ sphereMesh, planetMaterial, sphereTransform ]
    }

    function generate() {
        /// randomly change rotation direction
        if (Math.random() < 0.5) {
            rotationTarget *= -1
        }
    }

}
