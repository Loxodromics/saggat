
import Qt3D.Core 2.0
import Qt3D.Render 2.0

Material {
    id: root

    property real diameter: 1.0
    property real planetScale: scaleSlider.value
    property real heightScale: heightSlider.value
    property real e0: e0Slider.value
    property real e1: e1Slider.value
    property real e2: e2Slider.value
    property real coldness: coldnessSlider.value
    property real seed: seedSlider.value
    property bool displayHeight: heightMapSwitch.position

    property color maincolor: Qt.rgba(0.0, 0.0, 0.0, 1.0)
    property Sun sun

    parameters: [
        Parameter {
            name: "maincolor"
            value: Qt.vector3d(root.maincolor.r, root.maincolor.g, root.maincolor.b)
        },
        Parameter {
            name: "planetScale"
            value: root.planetScale
        },
        Parameter {
            name: "heightScale"
            value: root.heightScale
        },
        Parameter {
            name: "e0"
            value: root.e0
        },
        Parameter {
            name: "e1"
            value: root.e1
        },
        Parameter {
            name: "e2"
            value: root.e2
        },
        Parameter {
            name: "displayHeight"
            value: root.displayHeight
        },
        Parameter {
            name: "diameter"
            value: root.diameter
        },
        Parameter {
            name: "coldness"
            value: root.coldness
        },
        Parameter {
            name: "seed"
            value: root.seed
        }
    ]

    effect: Effect {
        property string vertex: "qrc:/shaders/gl3/planetSurfaceShader.vert"
        property string fragment: "qrc:/shaders/gl3/planetSurfaceShader.frag"
        property string vertexES: "qrc:/shaders/es2/planetSurfaceShader.vert"
        property string fragmentES: "qrc:/shaders/es2/planetSurfaceShader.frag"
        property string vertexES3: "qrc:/shaders/es3/planetSurfaceShader.vert"
        property string fragmentES3: "qrc:/shaders/es3/planetSurfaceShader.frag"


        FilterKey {
            id: forward
            name: "renderingStyle"
            value: "forward"
        }

        ShaderProgram {
            id: gl3Shader
            vertexShaderCode: loadSource(parent.vertex)
            fragmentShaderCode: loadSource(parent.fragment)
        }
        ShaderProgram {
            id: es2Shader
            vertexShaderCode: loadSource(parent.vertexES)
            fragmentShaderCode: loadSource(parent.fragmentES)
        }
        ShaderProgram {
            id: es3Shader
            vertexShaderCode: loadSource(parent.vertexES3)
            fragmentShaderCode: loadSource(parent.fragmentES3)
        }

        techniques: [
            // OpenGL 3.1
            Technique {
                filterKeys: [forward]
                graphicsApiFilter {
                    api: GraphicsApiFilter.OpenGL
                    profile: GraphicsApiFilter.CoreProfile
                    majorVersion: 3
                    minorVersion: 1
                }
                renderPasses: RenderPass {
                    shaderProgram: gl3Shader
                }
            },
            // OpenGL 2.0
            Technique {
                filterKeys: [forward]
                graphicsApiFilter {
                    api: GraphicsApiFilter.OpenGL
                    profile: GraphicsApiFilter.NoProfile
                    majorVersion: 2
                    minorVersion: 0
                }
                renderPasses: RenderPass {
                    shaderProgram: es2Shader
                }
            },
            // ES 2.0
            Technique {
                filterKeys: [forward]
                graphicsApiFilter {
                    api: GraphicsApiFilter.OpenGLES
                    profile: GraphicsApiFilter.CoreProfile
                    majorVersion: 2
                    minorVersion: 0
                }
                renderPasses: RenderPass {
                    shaderProgram: es2Shader
                }
            },
            // ES 3.0
            Technique {
                filterKeys: [forward]
                graphicsApiFilter {
                    api: GraphicsApiFilter.OpenGLES
                    profile: GraphicsApiFilter.CoreProfile
                    majorVersion: 3
                    minorVersion: 0
                }
                renderPasses: RenderPass {
                    shaderProgram: es3Shader
                }
            }
        ]
    }
}


