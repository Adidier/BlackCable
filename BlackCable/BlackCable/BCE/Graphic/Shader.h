#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>
#include "../Lights/DirectionalLight.h"
#include "../Lights/PointLight.h"


const int MAX_POINT_LIGHTS = 3;

using namespace BCE::Lights;

namespace BCE
{
	namespace Graphics
	{

		class Shader
		{
		public:
			Shader();

			void CreateFromString(const char* vertexCode, const char* fragmentCode);
			void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

			std::string ReadFile(const char* fileLocation);

			GLuint GetProjectionLocation();
			GLuint GetModelLocation();
			GLuint GetViewLocation();
			////Material
			GLuint GetAmbientIntensityLocation();
			GLuint GetAmbientColourLocation();
			GLuint GetDiffuseIntensityLocation();
			GLuint GetDirectionLocation();
			GLuint GetSpecularIntensityLocation();
			GLuint GetShininessLocation();
			GLuint GetEyePositionLocation();

			void UseShader();
			void ClearShader();
			~Shader();
			void SetDirectionalLight(DirectionalLight* dLight);
			void SetPointLights(PointLight* pLight, unsigned int lightCount);
		private:
			GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition;
			GLint uniformSpecularIntensity, uniformShininess;
			//GLuint uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection,
			//	   uniformSpecularIntensity, uniformShininess,
			//	   myMaterialAmbient, myLightAmbient;

			void CompileShader(const char* vertexCode, const char* fragmentCode);
			void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);


			GLuint uniformPointLightCount;
			struct {
				GLuint uniformColour;
				GLuint uniformAmbientIntensity;
				GLuint uniformDiffuseIntensity;

				GLuint uniformPosition;
				GLuint uniformConstant;
				GLuint uniformLinear;
				GLuint uniformExponent;
			} uniformPointLight[MAX_POINT_LIGHTS];
			struct {
				GLuint uniformColour;
				GLuint uniformAmbientIntensity;
				GLuint uniformDiffuseIntensity;

				GLuint uniformDirection;
			} uniformDirectionalLight;
		};

	}
}