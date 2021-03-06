import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

ColumnLayout {
    id: sliderLayout

    visible: sliderHider.containsMouse

    Slider {
        id: seedSlider
        value: Values.terrainSeed
        from: 0
        to: 1000
        stepSize: 1

        onValueChanged: {
            Values.terrainSeed = value
        }
    }
    Slider {
        id: scaleSlider
        value: 0.08
        from: 0
        to: 1
        stepSize: 0.001
    }
    Slider {
        id: heightSlider
        value: Values.terrainHeightFactor
        from: 0.01
        to: 2
        stepSize: 0.01

        onValueChanged: {
            Values.terrainHeightFactor = value
        }
    }
    Slider {
        id: coldnessSlider
        value: 0.5
        from: 0
        to: 1
        stepSize: 0.01

        onValueChanged: {
//                Values.terrainHeightFactor = value
        }
    }
    Slider {
        id: e0Slider
        value: Values.terrainE0

        onValueChanged: {
            Values.terrainE0 = value
        }
    }
    Slider {
        id: e1Slider
        value: Values.terrainE1

        onValueChanged: {
            Values.terrainE1 = value
        }
    }
    Slider {
        id: e2Slider
        value: Values.terrainE2

        onValueChanged: {
            Values.terrainE2 = value
        }
    }
    Slider {
        id: expSlider
        value: Values.terrainExp
        from: 0.001
        to: 4

        onValueChanged: {
            Values.terrainExp = value
        }
    }
    Switch {
        id: heightMapSwitch
    }
}
