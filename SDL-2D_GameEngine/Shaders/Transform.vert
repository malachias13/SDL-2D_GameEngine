#version 330

// Uniforms for world transform and view-proj

uniform mat4 uWorldTransform;
uniform mat4 uViewProj;

// Vertex attributes
in vec3 inPosition;

void main()
{
	vec4 pos = vec4(inPosition, 1.0);
	gl_Position = pos * uWorldTransform * uViewProj;
}