import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: ring

    property real beltWidth: 4.0
    property real rockSize: 0.333
    property real orbitalDistance: 23
    property int numberOfRocks: 150
    property real ringAngle: 10
    property real ringAxis: 0.3

    property variant rockComponent: Qt.createComponent("Rock.qml");
    property var rocks: []

    QQ2.Component.onCompleted: {
        generate()
    }

    Transform {
        id: ringTransform
        property real rotationAngle: 0.0
        matrix: {
            var m = Qt.matrix4x4();
            m.rotate(ringAngle, Qt.vector3d(ringAxis, 0, 1.0 - ringAxis));
            m.rotate(rotationAngle, Qt.vector3d(0, 1, 0));
            return m;
        }
    }

    QQ2.NumberAnimation {
        target: ringTransform
        property: "rotationAngle"
        duration: 5000 + Math.random() * 1000
        from: 0
        to: 360

        loops: QQ2.Animation.Infinite
        running: true
    }

    components: [ ringTransform ]

    function generate() {

        clearRocks()

        for (var i = 0; i < numberOfRocks; i++) {

            var rockmodel = rockComponent.createObject(ring, {
                "size": Math.random() * rockSize,
                "orbitalDistance:": orbitalDistance + Math.random() * beltWidth, /// not working
                "angle": Math.random() * 360
            });

            rockmodel.orbitalDistance = orbitalDistance + Math.random() * beltWidth

            rocks.push(rockmodel)
        }
    }

    function clearRocks() {
        for (var rock in rocks) {
            rocks[rock].destroy()
        }
        rocks = []
    }
}
