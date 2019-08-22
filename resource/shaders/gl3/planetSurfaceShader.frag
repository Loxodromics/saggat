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

//	Classic Perlin 3D Noise
//	by Stefan Gustavson
//	https://gist.github.com/patriciogonzalezvivo/670c22f3966e662d2f83
//
vec4 permute(vec4 x){return mod(((x*34.0)+1.0)*x, seed);}
vec4 taylorInvSqrt(vec4 r){return 1.79284291400159 - 0.85373472095314 * r;}
vec3 fade(vec3 t) {return t*t*t*(t*(t*6.0-15.0)+10.0);}

float cnoise(vec3 P) {
	vec3 Pi0 = floor(P); // Integer part for indexing
	vec3 Pi1 = Pi0 + vec3(1.0); // Integer part + 1
	Pi0 = mod(Pi0, seed);
	Pi1 = mod(Pi1, seed);
	vec3 Pf0 = fract(P); // Fractional part for interpolation
	vec3 Pf1 = Pf0 - vec3(1.0); // Fractional part - 1.0
	vec4 ix = vec4(Pi0.x, Pi1.x, Pi0.x, Pi1.x);
	vec4 iy = vec4(Pi0.yy, Pi1.yy);
	vec4 iz0 = vec4(Pi0.zz, Pi0.zz);
	vec4 iz1 = vec4(Pi1.zz, Pi1.zz);

	vec4 ixy = permute(permute(ix) + iy);
	vec4 ixy0 = permute(ixy + iz0);
	vec4 ixy1 = permute(ixy + iz1);

	vec4 gx0 = ixy0 / 7.0;
	vec4 gy0 = fract(floor(gx0) / 7.0) - 0.5;
	gx0 = fract(gx0);
	vec4 gz0 = vec4(0.5) - abs(gx0) - abs(gy0);
	vec4 sz0 = step(gz0, vec4(0.0));
	gx0 -= sz0 * (step(0.0, gx0) - 0.5);
	gy0 -= sz0 * (step(0.0, gy0) - 0.5);

	vec4 gx1 = ixy1 / 7.0;
	vec4 gy1 = fract(floor(gx1) / 7.0) - 0.5;
	gx1 = fract(gx1);
	vec4 gz1 = vec4(0.5) - abs(gx1) - abs(gy1);
	vec4 sz1 = step(gz1, vec4(0.0));
	gx1 -= sz1 * (step(0.0, gx1) - 0.5);
	gy1 -= sz1 * (step(0.0, gy1) - 0.5);

	vec3 g000 = vec3(gx0.x,gy0.x,gz0.x);
	vec3 g100 = vec3(gx0.y,gy0.y,gz0.y);
	vec3 g010 = vec3(gx0.z,gy0.z,gz0.z);
	vec3 g110 = vec3(gx0.w,gy0.w,gz0.w);
	vec3 g001 = vec3(gx1.x,gy1.x,gz1.x);
	vec3 g101 = vec3(gx1.y,gy1.y,gz1.y);
	vec3 g011 = vec3(gx1.z,gy1.z,gz1.z);
	vec3 g111 = vec3(gx1.w,gy1.w,gz1.w);

	vec4 norm0 = taylorInvSqrt(vec4(dot(g000, g000), dot(g010, g010), dot(g100, g100), dot(g110, g110)));
	g000 *= norm0.x;
	g010 *= norm0.y;
	g100 *= norm0.z;
	g110 *= norm0.w;
	vec4 norm1 = taylorInvSqrt(vec4(dot(g001, g001), dot(g011, g011), dot(g101, g101), dot(g111, g111)));
	g001 *= norm1.x;
	g011 *= norm1.y;
	g101 *= norm1.z;
	g111 *= norm1.w;

	float n000 = dot(g000, Pf0);
	float n100 = dot(g100, vec3(Pf1.x, Pf0.yz));
	float n010 = dot(g010, vec3(Pf0.x, Pf1.y, Pf0.z));
	float n110 = dot(g110, vec3(Pf1.xy, Pf0.z));
	float n001 = dot(g001, vec3(Pf0.xy, Pf1.z));
	float n101 = dot(g101, vec3(Pf1.x, Pf0.y, Pf1.z));
	float n011 = dot(g011, vec3(Pf0.x, Pf1.yz));
	float n111 = dot(g111, Pf1);

	vec3 fade_xyz = fade(Pf0);
	vec4 n_z = mix(vec4(n000, n100, n010, n110), vec4(n001, n101, n011, n111), fade_xyz.z);
	vec2 n_yz = mix(n_z.xy, n_z.zw, fade_xyz.y);
	float n_xyz = mix(n_yz.x, n_yz.y, fade_xyz.x);
	return 2.2 * n_xyz;
}

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

void main() {
	float e = e0 * cnoise(fragPos * planetScale * 1.0);
	e += e1 * cnoise(fragPos * planetScale * 2.0);
	e += e2 * cnoise(fragPos * planetScale * 4.0);
	float eSum = e / (e0 + e1 + e2);
	eSum *= heightScale;
	float coldnessVariation = abs(fragPos.y / diameter) * abs(fragPos.y / diameter) * coldness;

	vec4 specColor = vec4(0.0, 0.0, 0.0, 1.0);
	vec4 outputColor = vec4(1.0, 0.0, 0.0, 1.0);
	float specVal = 0.0;
	if (displayHeight) {
		outputColor = vec4(eSum, eSum, eSum, 1.0);
	}
	else {
		vec4 tcol = terrainColor(eSum + coldnessVariation);
		outputColor = vec4(tcol.xyz, 1.0);
		if ((tcol.w < 0.51) && (tcol.w > 0.49)) {
			specColor = vec4(outputColor.xyz, 1.0) * 1.8;
			specVal = 8.0 + 2.0 * eSum + cnoise(fragPos * planetScale * 32.0);
		}
		else if (tcol.w < 0.2) {
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
