#version 300 es

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec4 vertexTangent;

uniform mat4 modelMatrix;
uniform mat3 modelNormalMatrix;
uniform mat4 modelViewProjection;

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

out vec4 vertexColor;
out vec3 fragPos;
out vec3 worldPosition;
out vec3 worldNormal;
out vec4 worldTangent;

#pragma include :/shaders/common/perlinnoise.inc

void main()
{
	float e = e0 * cnoise(vertexPosition * planetScale * 1.0);
	e += e1 * cnoise(vertexPosition * planetScale * 2.0);
	e += e2 * cnoise(vertexPosition * planetScale * 4.0);
	float eSum = e / (e0 + e1 + e2);
	eSum *= heightScale;
	if (eSum < 0.1) {
		eSum = 0.1;
	}

	// Transform position, normal, and tangent to world coords
	worldNormal = normalize( modelNormalMatrix * vertexNormal );
	worldPosition = vec3(modelMatrix * vec4(vertexPosition, 1.0));
	vertexColor = vec4(vertexPosition, 1.0);

	worldTangent.xyz = normalize(vec3(modelMatrix * vec4(vertexTangent.xyz, 0.0)));
	worldTangent.w = vertexTangent.w;

	vec3 vertexNormalNorm = normalize(vertexNormal);

	vec4 vvpos = vec4(vertexPosition, 1.0);
	if (false) { /// turn of elevation for the moment
		vec4(vertexNormalNorm * (1.0 + eSum) * 10.0 , 1.0);
	}
	// Calculate vertex position in clip coordinates
	gl_Position = modelViewProjection * vvpos;
	fragPos = vertexPosition;
}

