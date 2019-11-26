#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 FragPos;
in mat3 TBN;	
in vec3 Normal1;
out vec4 colour;

const int MAX_POINT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];

uniform sampler2D theTexture;
uniform sampler2D normalMap;  
uniform Material material;

uniform vec3 eyePosition;

void main()
{

	colour = vCol;
}