#version 330 core

in vec3 vertexPosition;
uniform mat4 modelMatrix;
uniform mat4 mvp;

out vec4 vertexColor;
out vec3 fragPos;

void main()
{
	// Transform position, normal, and tangent to world coords
	vec3 worldPosition = vec3(modelMatrix * vec4(vertexPosition, 1.0));
	float noiseF = 0.9;
	vertexColor = vec4(vertexPosition, 1.0);

	// Calculate vertex position in clip coordinates
	gl_Position = mvp * vec4(worldPosition, 1.0);
	fragPos = vec3(modelMatrix * vec4(vertexPosition, 1.0));
}

