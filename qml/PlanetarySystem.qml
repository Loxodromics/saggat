import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    property Sun sun

    QQ2.Component.onCompleted: {
        generate()
    }

    Planet {
        id: planet

        radius: 9
        rotationDuration: 24000
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
        sun: sun
    }

    Ring {
        id: ring
        sun: sun
    }

    Ring {
        id: ring2
        sun: sun
    }

    Moons {
        id: moons
        sun: sun
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
            ring.ringWidth = Generator.ringWidth()
            ring.orbitalDistance = Generator.ringOrbitalDistance(planet.radius)
            ring.numberOfRocks = Generator.ringNumberOfRocks(ring.ringWidth, ring.orbitalDistance)
            ring.ringAxis = Generator.ringAxis()
            ring.ringAngle = Generator.ringAngle()
            ring.color = Generator.ringColor()
            ring.printValues()
        }
        else {
            ring.numberOfRocks = 0
        }
        ring.generate()

        if ( 0.25 > Math.random() ) {
            /// random chance to have a second ring
            ring2.ringWidth = Generator.ringWidth()
            ring2.orbitalDistance = Generator.ringOrbitalDistance(planet.radius)
            ring2.numberOfRocks = Generator.ringNumberOfRocks(ring.ringWidth, ring.orbitalDistance)
            ring2.ringAxis = Generator.ringAxis()
            ring2.ringAngle = Generator.ringAngle()
            ring2.color = Generator.ringColor()
            ring2.printValues()
        }
        else {
            ring2.numberOfRocks = 0
        }
        ring2.generate()

        sizeAnimation.restart()

        moons.planetSize = planet.radius
        moons.generate()
    }
}
