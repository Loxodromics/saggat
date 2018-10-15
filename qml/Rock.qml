import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: root

    property real orbitalDistance: 20
    property real size: 0.4
    property real angle: 20
    property color rockColor: Qt.hsla( Math.random(), 0.8, 0.6, 1.0)


    PhongMaterial {
        id: rockMaterial
        ambient: Qt.rgba( 0.2, 0.2, 0.2, 1.0 )
        diffuse: rockColor
        specular: Qt.rgba( 0.9, 0.9, 0.9, 1.0 )
        shininess: 0.9
    }

    SphereMesh {
        id: rockMesh

        generateTangents: true
        radius: size
        slices: 5
        rings: 5
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
