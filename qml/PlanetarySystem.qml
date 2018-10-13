import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    Planet {
        id: planet

        diameter: 9
        rotationDuration: 24000
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
    }

    function generate() {
        planet.diameter = 7 + Math.random() * 6
        planet.rotationDuration = 10000 + Math.random() * 30000
    }
}
