#version 300 es
precision mediump float;

in vec4 vertexColor;
in vec3 fragPos;
in vec3 worldPosition;
in vec3 worldNormal;
in vec4 worldTangent;

uniform float planetScale;
uniform float heightScale;
uniform float diameter;
uniform float e0;
uniform float e1;
uniform float e2;
uniform float coldness;
uniform float seed;
uniform bool displayHeight;
uniform vec3 eyePosition;

out vec4 fragColor;

void main() {

	vec3 tNormal = worldTangent.xyz;
	vec3 worldView = normalize(eyePosition - worldPosition);

	vec4 outputColor = vec4(0.0, 1.0, 0.0, 1.0);

	fragColor = vec4(outputColor.xyz, 1.0);
}

