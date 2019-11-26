#pragma once
#include<map>
#include "../Graphic/Shader.h"
#include "../Graphic/Camera.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "../Graphic/Material.h"
#include "../Lights/Light.h"

namespace BCE
{
	namespace Base
	{
		using namespace BCE::Graphics;

		class ShaderManager
		{
		public:

			void LoadShaders(const std::string & name, const std::string & pathV, const std::string & pathF);
			const char* vShaderDefault = "Assets/Shaders/Default/default.vert";
			const char* fShaderDefault = "Assets/Shaders/Default/default.frag";
			static ShaderManager* getPtr();
			void initShader(Camera* camera);
			void draw();
			GLint GetModelLocation();
			GLint GetViewLocation();
			GLint GetProjectionLocation();
			GLint GetSpecularIntensityLocation();
			GLint GetShininessLocation();
			glm::mat4 GetViewMatrix();
			glm::mat4 GetProjectionMatrix();
			void Activate(const std::string & path);
		private:
			ShaderManager();
			std::map<std::string,Shader> shaderList;
			Shader *currentShader;
			static ShaderManager* ptr;
			Camera* camera;
			glm::mat4 projection;
			GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;

			GLuint  uniformEyePosition = 0,
				uniformAmbientIntensity = 0, uniformAmbientColour = 0, uniformDirection = 0, uniformDiffuseIntensity = 0,
				uniformSpecularIntensity = 0, uniformShininess = 0,
				myMaterialAmbient = 0, myLightAmbient = 0;


			DirectionalLight mainLight;
			PointLight pointLights[MAX_POINT_LIGHTS];
		};

	}
}