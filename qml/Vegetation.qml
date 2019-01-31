import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import QtQuick 2.11 as QQ2

Entity {
    id: rootV

    property int numberOfTrees: 90
    property real planetSize: 30

    property var trees: []
    property variant tree0Component: Qt.createComponent("Tree.qml");
    property Sun sun

    function generate() {
        clearTrees()

        for (var i = 0; i < numberOfTrees; i++) {

            var tree0Model = tree0Component.createObject(rootV, {
                "rotX": Math.random() * 180 - 90,
                "rotY": Math.random() * 180 - 90,
                "rotZ": Math.random() * 180 - 90,
                "radius": planetSize,
                "scale": Math.random() * 0.5 + 0.75
            });

            tree0Model.radius = planetSize
            trees.push(tree0Model)
        }
    }

    function clearTrees() {
        for (var tree in trees) {
            trees[tree].destroy()
        }
        trees = []
    }
}
