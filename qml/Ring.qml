import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: ring

    property real beltWidth: 4.0
    property real rockSize: 0.333
    property real orbitalDistance: 23
    property int numberOfRocks: 150

    property variant rockComponent: Qt.createComponent("Rock.qml");
    property var rocks: []

    QQ2.Component.onCompleted: {
        generate()
    }

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
