import QtQuick 2.0

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
//    Slider {
//        id: scaleSlider
//        value: 0.08
//        from: 0
//        to: 1
//        stepSize: 0.001


//        onValueChanged: {
//            Values.terrainScale = value
//        }
//    }
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
                Values.terrainColdness = value
        }
    }
    Slider {
        id: octavesSlider
        value: Values.terrainOctaves

        from: 0
        to: 10
        stepSize: 1

        onValueChanged: {
            Values.terrainOctaves = value
        }
    }
//    Slider {
//        id: expSlider
//        value: Values.terrainExp
//        from: 0.001
//        to: 4

//        onValueChanged: {
//            Values.terrainExp = value
//        }
//    }
    Slider {
        id: seaLevelSlider
        value: Values.terrainSeaLevel
        from: 0
        to: 0.99
        stepSize: 0.01

        onValueChanged: {
            Values.terrainSeaLevel = value
        }
    }
    Switch {
        id: heightMapSwitch

        onPositionChanged: {
            Values.displayHeight = position
        }
    }
}

