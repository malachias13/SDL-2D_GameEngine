#version 330

precision mediump float;

out vec4 outColor;

varying vec2 vPos;

uniform float deltaTime;

vec3 palette( float t)
{
	vec3 a = vec3(0.363, 0.134, 0.640);
	vec3 b = vec3(0.098, 0.979, 0.719);
	vec3 c = vec3(0.082, 1.566, 0.347);
	vec3 d = vec3(5.902, 0.098, 4.993);

	return a + b * cos(6.28318*(c*t+d));
}

void main()
{
	vec3 circle = vec3(0.5, 0.5, 0.2);
	vec3 finalColor = vec3(0.0);
	float d = length(vPos - circle.xy) - circle.z;

//	vec3 col = palette(length(vPos - circle.xy));

//	d = sin(d * 100 + deltaTime)/8;
//	d = abs(d);
//	d = 0.02 / d;
    d = smoothstep(0.0,0.01, d);

	finalColor += d;
	outColor = vec4(finalColor, 1.0);

//	vec4 tl = vec4(0.5, 0.1, 0.9, 1.0);
//	vec4 tr = vec4(0.3, 1.0, 0.8, 1.0);
//
//	vec4 bl = vec4(0.8, 0.6, 0.1, 1.0);
//	vec4 br = vec4(0.7, 0.1, 0.2, 1.0);
//
//	vec4 top = mix(tl, tr, vPos.x);
//	vec4 bottom = mix(bl, br, vPos.x);
//
//	vec4 c = mix(bottom, top, vPos.y);
//	outColor = c;
	
}