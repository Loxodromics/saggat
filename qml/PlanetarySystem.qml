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

    Ring {
        id: ring2
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
        planet.radius = Generator.planetRadius()
        planet.rotationDuration = Generator.planetRotationDuration()
        console.log("planet.radius: " + planet.radius + " planet.rotationDuration: " + planet.rotationDuration)
        planet.generate()

        if ( 0.25 < Math.random() ) {
            /// random chance to have a first ring
            ring.ringWidth = Math.random() * 5.0 + 1.0
            ring.orbitalDistance = Math.random() * 14 + planet.radius
            ring.numberOfRocks = ring.orbitalDistance * 10 * ring.ringWidth // Math.random() * 200 + 100
            ring.ringAxis = Math.random()
            ring.ringAngle = Math.random() * 180 - 90
            ring.color = Qt.hsla( Math.random(), 0.8, 0.6, 1.0 )
        }
        else {
            ring.numberOfRocks = 0
        }
        ring.generate()

        if ( 0.25 > Math.random() ) {
            /// random chance to have a second ring
            ring2.ringWidth = Math.random() * 5.0 + 1.0
            ring2.orbitalDistance = Math.random() * 18 + planet.radius
            ring2.numberOfRocks = ring.orbitalDistance * 10 * ring2.ringWidth// Math.random() * 200 + 100
            ring2.ringAxis = Math.random()
            ring2.ringAngle = Math.random() * 180 - 90
            ring2.color = Qt.hsla( Math.random(), 0.8, 0.6, 1.0 )
        }
        else {
            ring2.numberOfRocks = 0
        }
        ring2.generate()

        sizeAnimation.restart()
    }
}
