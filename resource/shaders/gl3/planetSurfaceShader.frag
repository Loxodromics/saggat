#version 330 core
//precision highp float;

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

#pragma include phong.inc.frag
#pragma include coordinatesystems.inc
#pragma include :/shaders/common/perlinnoise.inc

vec4 terrainColor(float height) {
	if (height < 0.1) {
		return vec4(0.2, 0.286, 0.769, 0.8);
	}
	else if (height < 0.6) {
		return vec4(0.286, 0.494, 0.141, 0.1);
	}
	else if (height < 0.75) {
		return vec4(0.586, 0.594, 0.541, 0.1);
	}
	else {
		return vec4(0.986, 0.994, 0.941, 0.5);
	}
}

vec4 heightColor(float height) {
	if (height < 0.1) {
		return vec4(0.999, 0.0, 0.999, 1.0);
	}
	else if (height < 0.2) {
		return vec4(0.0, 0.1, 0.0, 0.1);
	}
	else if (height < 0.3) {
		return vec4(0.0, 0.0, 0.1, 0.1);
	}
	else if (height < 0.4) {
		return vec4(0.3, 0.0, 0.0, 0.1);
	}
	else if (height < 0.5) {
		return vec4(0.0, 0.3, 0.0, 0.1);
	}
	else if (height < 0.6) {
		return vec4(0.0, 0.0, 0.3, 0.1);
	}
	else if (height < 0.7) {
		return vec4(0.6, 0.0, 0.0, 0.1);
	}
	else if (height < 0.8) {
		return vec4(0.0, 0.6, 0.0, 0.1);
	}
	else if (height < 0.9) {
		return vec4(0.0, 0.0, 0.6, 0.1);
	}
	else {
		return vec4(0.986, 0.994, 0.941, 0.5);
	}
}

void main() {
	float eSum = (length(fragPos) - diameter) / (diameter * heightScale);
	float coldnessVariation = abs(fragPos.y / diameter) * abs(fragPos.y / diameter) * coldness;

	vec4 specColor = vec4(0.0, 0.0, 0.0, 1.0);
	vec4 outputColor = vec4(1.0, 0.0, 0.0, 1.0);
	float specVal = 0.0;
	if (displayHeight) {
		outputColor = vec4(eSum, eSum, eSum, 1.0);
		outputColor = heightColor(eSum);
	}
	else {
		vec4 tcol = terrainColor(eSum + coldnessVariation);
		outputColor = vec4(tcol.xyz, 1.0);
		if ((tcol.w < 0.51) && (tcol.w > 0.49)) {
			specColor = vec4(outputColor.xyz, 1.0) * 1.8;
			specVal = 8.0 + 2.0 * eSum + cnoise(fragPos * planetScale * 32.0);
		}
		else if (tcol.w <= 0.2) {
			specColor = vec4(outputColor.xyz, 1.0) * 0.5;
			specVal = 1.0 + eSum + cnoise(fragPos * planetScale * 8.0);
		}
		else {
			specColor = vec4(outputColor.xyz, 1.0) * 0.5;
			specVal = 8.0 + 3.0 * cnoise(fragPos * planetScale * 32.0);
		}
	}

	vec3 tNormal = worldTangent.xyz;
	mat3 tangentMatrix = calcWorldSpaceToTangentSpaceMatrix(worldNormal, worldTangent);
	mat3 invertTangentMatrix = transpose(tangentMatrix);
	vec3 wNormal = normalize(invertTangentMatrix * tNormal);
	vec3 worldView = normalize(eyePosition - worldPosition);

	outputColor = phongFunction(outputColor * 0.2, outputColor, specColor, specVal, worldPosition, worldView, worldNormal);

	fragColor = vec4(outputColor.xyz, 1.0);
}
