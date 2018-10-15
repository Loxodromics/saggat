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

    function generate() {
        planet.radius = 7 + Math.random() * 6
        planet.rotationDuration = 10000 + Math.random() * 30000
        planet.generate()

        ring.numberOfRocks = Math.random() * 200 + 100
        ring.orbitalDistance = Math.random() * 20 + 10
        ring.generate()
    }
}
