import Qt3D.Core 2.0
import Qt3D.Render 2.0

Entity {
    id: root

    property vector3d lightPosition: Qt.vector3d(10000.0, 10000.0, 1000.0)
    property vector3d lightIntensity: Qt.vector3d(1.0, 1.0, 1.0)

}
