import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import QtQuick 2.0 as QQ2

Entity {
    id: root

    property real rotX: 0
    property real rotY: 0
    property real rotZ: 0
    property real radius: 10
    property real scale: 1.0

    SceneLoader {
        id: sceneLoader
        source: Math.random() > 0.5 ? "qrc:/models/tree1.dae" : "qrc:/models/tree0.dae"
        onStatusChanged: {
            console.log("SceneLoader status: " + status);
            if (status === SceneLoader.Ready) {
                console.log("Scene is ready");
                console.log(sceneLoader.entityNames())
            }
        }

        Transform {
            id: treeTransform
            matrix: {
                var m = Qt.matrix4x4();
                m.rotate(rotX, Qt.vector3d(1, 0, 0));
                m.rotate(rotY, Qt.vector3d(0, 1, 0));
                m.rotate(rotZ, Qt.vector3d(0, 0, 1));
                m.translate(Qt.vector3d(0.0, root.radius, 0.0));
                m.scale(root.scale);
                return m;
            }
        }
    }

    components: [sceneLoader, treeTransform]
}
