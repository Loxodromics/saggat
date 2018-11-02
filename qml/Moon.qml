import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    property real radius: 5
    property alias rotationDuration: moonTransformAnimation.duration
    property real orbitalDistance: 15
    property real angleOffset: 0
    property real moonAngle: 10
    property real moonAxis: 0.3
    property vector3d upVector: Qt.vector3d(0, 1, 0)
    property real rotationTarget: 360
    property Sun sun

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
        id: moonMesh

        generateTangents: true
        radius: root.radius
    }

    Transform {
        id: moonTransform
        property real userAngle: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.rotate(moonAngle, Qt.vector3d(moonAxis, 0, 1.0 - moonAxis));
            m.rotate(userAngle + angleOffset, upVector)
            m.translate(Qt.vector3d(orbitalDistance, 0, 0));
            return m;
        }
    }

    QQ2.NumberAnimation {
        id: moonTransformAnimation
        target: moonTransform
        property: "userAngle"
        duration: 50000
        from: 0
        to: 360

        loops: QQ2.Animation.Infinite
        running: true
    }

    Entity {
        id: moonEntity
        components: [ moonMesh, moonMaterial, moonTransform ]
    }

}
