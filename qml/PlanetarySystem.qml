import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    Planet {
        id: planet

        radius: 9
        rotationDuration: 24000
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
    }

    Ring {
        id: ring
    }

    Transform {
        id: sizeTransform
        property real size: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.scale(size)
            return m;
        }
    }

    QQ2.NumberAnimation {
        id: sizeAnimation
        target: sizeTransform
        property: "size"
        duration: 1600

        from: 0.0001
        to: 1.0

        easing.type: Easing.OutElastic

        running: true
        loops: 1
    }

    components: [ sizeTransform ]

    function generate() {
        planet.radius = 2 + Math.random() * 6
        planet.rotationDuration = 5000 + Math.random() * 40000
        planet.generate()

        ring.orbitalDistance = Math.random() * 20 + planet.radius
        ring.numberOfRocks = ring.orbitalDistance * 50 // Math.random() * 200 + 100
        ring.ringAxis = Math.random()
        ring.ringAngle = Math.random() * 180 - 90

        ring.generate()

        sizeAnimation.restart()
    }
}
