#version 300 es

in vec3 vertexPosition;
//in vec3 worldPosition;
uniform mat4 modelMatrix;
uniform mat4 mvp;

out vec4 vertexColor;

void main()
{
	// Transform position, normal, and tangent to world coords
	vec3 worldPosition = vec3(modelMatrix * vec4(vertexPosition, 1.0));
	vertexColor = vec4(vertexPosition, 1.0);

	// Calculate vertex position in clip coordinates
	gl_Position = mvp * vec4(worldPosition, 1.0);
}
