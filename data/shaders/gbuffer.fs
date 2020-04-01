#version 330 core

layout (location = 0) out vec4 GBuffer0;
layout (location = 1) out vec4 GBuffer1;
layout (location = 2) out vec4 GBuffer2;
layout (location = 3) out vec4 GBuffer3;

// layout
//      x   y   z   w
// 0    [albedo]  roughness
// 1    [normal]  metalness
// 2    [ pos  ]    0
// 3    0   0   0   0

in VS_OUT {
    vec3 WorldPos;
    vec2 TexCoords;
    mat3 TBN;
} vs_out;

uniform vec3 albedo_factor;
//uniform sampler2D albedo_texture;
uniform float roughness_factor;
//uniform sampler2D roughness_texture;
uniform float metalness_factor;
//uniform sampler2D metalness_texture;
//uniform sampler2D normal_texture;

void main()
{
	vec3 albedo = albedo_factor;// * texture(albedo_texture, vs_out.TexCoords).rgb;
	float roughness = roughness_factor;// * texture(roughness_texture, vs_out.TexCoords).r;
	float metalness = metalness_factor;// * texture(metalness_texture, vs_out.TexCoords).r;
	vec3 normal = vec3(0,0,1);//texture(normal_texture, vs_out.TexCoords).xyz;
	normal = 2 * normal - 1;
	normal = vs_out.TBN * normal;
	
	GBuffer0 = vec4(albedo, roughness);
	GBuffer1 = vec4(normal, metalness);
	GBuffer2 = vec4(vs_out.WorldPos, 0);
	GBuffer3 = vec4(0, 0, 0, 0);
}