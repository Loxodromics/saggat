import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: ring

    property real ringWidth: 4.0
    property real rockSize: 0.333
    property real orbitalDistance: 23
    property int numberOfRocks: 150
    property real ringAngle: 10
    property real ringAxis: 0.3
    property color color: Qt.hsla( Math.random(), 0.8, 0.6, 1.0 )
    property real rotationDuration: 10000

    property variant rockComponent: Qt.createComponent("Rock.qml");
    property var rocks: []

    onRotationDurationChanged: {
        ringTransform.duration = rotationDuration
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
        duration: rotationDuration
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
                "size": Generator.rockSize(),
                "orbitalDistance:": 1234, /// not working
                "angle": Math.random() * 360,
                "height": Generator.rockHeight(),
                "rockColor": Qt.lighter(color, Generator.rockColor(0.5))
            });

            rockmodel.orbitalDistance = Generator.rockOrbitalDistance(orbitalDistance)

            rocks.push(rockmodel)
        }
    }

    function clearRocks() {
        for (var rock in rocks) {
            rocks[rock].destroy()
        }
        rocks = []
    }

    function printValues() {
        console.log( "ringWidth: " + ringWidth +
                     " rockSize: " + rockSize +
                     " orbitalDistance: " + orbitalDistance +
                     " numberOfRocks: " + numberOfRocks +
                     " ringAngle: " + ringAngle +
                     " ringAxis: " + ringAxis +
                     " color: " + color)
    }
}
