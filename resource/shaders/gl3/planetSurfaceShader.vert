#version 330 core

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec4 vertexTangent;

uniform mat4 modelMatrix;
uniform mat3 modelNormalMatrix;
uniform mat4 modelViewProjection;

out vec4 vertexColor;
out vec3 fragPos;
out vec3 worldPosition;
out vec3 worldNormal;
out vec4 worldTangent;

void main()
{
	// Transform position, normal, and tangent to world coords
	worldNormal = normalize( modelNormalMatrix * vertexNormal );
	worldPosition = vec3(modelMatrix * vec4(vertexPosition, 1.0));
	float noiseF = 0.9;
	vertexColor = vec4(vertexPosition, 1.0);

	worldTangent.xyz = normalize(vec3(modelMatrix * vec4(vertexTangent.xyz, 0.0)));
	worldTangent.w = vertexTangent.w;

	// Calculate vertex position in clip coordinates
	gl_Position = modelViewProjection * vec4(worldPosition, 1.0);
	fragPos = vec3(modelMatrix * vec4(vertexPosition, 1.0));
}

