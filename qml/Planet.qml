import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

import LFD 1.0

Entity {
    id: root

    property real radius: 10
    property real rotationDuration: 30000
    property vector3d upVector: Qt.vector3d(0, 1, 0)
    property real rotationTarget: 360
    property Sun sun

    onRotationDurationChanged: {
        planetTransformAnimation.duration = rotationDuration
        planetTransformAnimation.restart()
    }

    onRotationTargetChanged: {
        planetTransformAnimation.to = rotationTarget
        planetTransformAnimation.restart()
    }

    PlanetSurfaceMaterialQml {
        id: planetMaterial
        diameter: radius
        sun: sun
    }

    PhongMaterial {
        id: planetMaterial_
        ambient: "#FFAABB00"
        diffuse: "#FFAABB00"
        specular: "#FFFFFFFF"
        shininess: 1.0
    }

//    SphereMesh {
//        id: planetMesh

//        generateTangents: true
//        radius: root.radius
//        slices: 100
//        rings: 100
//    }

    GeosphereMesh {
        id: planetMesh

        radius: root.radius
        subdivisions: 3
    }

    Transform {
        id: planetTransform
        property real userAngle: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.rotate(userAngle, upVector)
            return m;
        }
    }

    QQ2.NumberAnimation {
        id: planetTransformAnimation
        target: planetTransform
        property: "userAngle"
        duration: rotationDuration
        from: 0
        to: rotationTarget

        loops: QQ2.Animation.Infinite
        running: true
    }

    Entity {
        id: planetEntity
        components: [ planetMesh, planetMaterial, planetTransform ]
    }

    function generate() {
        /// randomly change rotation direction
        if (Math.random() < 0.5) {
            rotationTarget *= -1
        }
    }

}
