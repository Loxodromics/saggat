import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    property real radius: 5
    property real rotationDuration: 30000
    property real orbitalDistance: 15
    property real angleOffset: 0
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
        id: moonMaterial

        texture: Texture2D {
            id: moonTexture
            minificationFilter: Texture.LinearMipMapLinear
            magnificationFilter: Texture.Linear
            wrapMode {
                x: WrapMode.Repeat
                y: WrapMode.Repeat
            }
            generateMipMaps: true
            maximumAnisotropy: 16.0
            TextureImage {
                id: moonTextureImage
                source: "qrc:/textures/moon.jpg"
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
            m.rotate(userAngle + angleOffset, upVector)
            m.translate(Qt.vector3d(orbitalDistance, 0, 0));
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
        components: [ sphereMesh, moonMaterial, sphereTransform ]
    }

}
