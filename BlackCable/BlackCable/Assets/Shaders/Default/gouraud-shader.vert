#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;
out vec4 vCol;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;


vec3 ADSLightModel( in vec3 myNormal, in vec3 myPosition )
{
	const vec3 myLightPosition = vec3( 0.0 , 0.5, 0.0 );
	const vec3 myLightAmbient = vec3( 0.2, 0.2, 0.2 );
	const vec3 myLightDiffuse = vec3( 1.0 , 1.0 , 1.0 );
	const vec3 myLightSpecular = vec3( 1.0 , 1.0 , 1.0 );
	const vec3 myMaterialAmbient = vec3( 1.0 , 0.5, 0.0 );
	const vec3 myMaterialDiffuse = vec3( 1.0 , 0.5, 0.0 );
	const vec3 myMaterialSpecular = vec3( 0.6, 0.6, 0.6 );
	const float myMaterialShininess = 10.0;
	//normal, light, view, and light reflection vectors
	vec3 norm = normalize( myNormal );
	vec3 lightv = normalize( myLightPosition - myPosition);
	vec3 viewv = normalize( vec3(0.,0.,0.) - myPosition );
	vec3 refl = reflect( vec3(0.,0.,0.) - lightv, norm );
	//ambient light computation
	vec3 ambient = myMaterialAmbient*myLightAmbient;
	//diffuse light computation
	vec3 diffuse = max(0.0, dot(lightv, norm)) * myMaterialDiffuse *myLightDiffuse;
	//Optionally you can add a diffuse attenuation term at this
	//point
	//specular light computation
	vec3 specular = vec3( 0.0, 0.0, 0.0 );
	if( dot(lightv, viewv) > 0.0)
	{
	 specular = pow(max(0.0, dot(viewv,refl)), myMaterialShininess)*myMaterialSpecular*	myLightSpecular;
	}
	return clamp( ambient + diffuse + specular, 0.0, 1.0);
}

void main( )
{
	vec3 transNorm = normalize(  norm );
	vec3 ECpos = ( model * vec4(pos, 1.0) ).xyz;
	vCol = vec4(ADSLightModel( transNorm, ECpos ), 1.0);
	gl_Position = projection * view * model * vec4(pos, 1.0);
	TexCoord = tex;
}
