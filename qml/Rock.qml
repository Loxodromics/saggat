import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: root

    property real orbitalDistance: 20
    property real size: 0.4
    property real angle: 20

    PhongMaterial {
        id: material
    }

    TextureMaterial {
        id: rockMaterial

        texture: Texture2D {
            id: rockTexture
            minificationFilter: Texture.LinearMipMapLinear
            magnificationFilter: Texture.Linear
            wrapMode {
                x: WrapMode.Repeat
                y: WrapMode.Repeat
            }
            generateMipMaps: true
            maximumAnisotropy: 16.0
            TextureImage {
                id: rockTextureImage
                source: "qrc:/textures/rock.jpg"
            }
        }
    }

    SphereMesh {
        id: rockMesh

        generateTangents: true
        radius: size

    }

    Transform {
        id: rockTransform
        property real userAngle: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.rotate(userAngle + angle, Qt.vector3d(0, 1, 0));
            m.translate(Qt.vector3d(orbitalDistance, 0, 0));
            return m;
        }
    }

    Entity {
        id: rockEntity
        components: [ rockMesh, rockMaterial, rockTransform ]
    }
}
