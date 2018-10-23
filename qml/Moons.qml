import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: root

    property int numberOfMoons: 3
    property real planetSize: 10

    property var moons: []
    property variant moonComponent: Qt.createComponent("Moon.qml");


    function generate() {
        clearMoons()

        numberOfMoons = Generator.moonCount(planetSize)

        for (var i = 0; i < numberOfMoons; i++) {

            var moonModel = moonComponent.createObject(root, {
                "radius": Generator.moonSize(planetSize),
                "angleOffset": Math.random() * 360
            });

            moonModel.orbitalDistance = Generator.moonOrbitalDistance(planetSize, moonModel.radius)
            moonModel.rotationDuration =  Generator.moonRotationDuration(planetSize, moonModel.radius, moonModel.orbitalDistance)
//            console.log("time: " + Generator.moonRotationDuration(planetSize, moonModel.radius, moonModel.orbitalDistance))

            moons.push(moonModel)
        }
    }

    function clearMoons() {
        for (var rock in moons) {
            moons[rock].destroy()
        }
        moons = []
    }
}
