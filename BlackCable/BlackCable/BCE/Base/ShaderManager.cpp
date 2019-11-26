#include "ShaderManager.h"
#include "Platform.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

namespace BCE
{
	namespace Base
	{
		ShaderManager* ShaderManager::ptr;

		ShaderManager::ShaderManager(): currentShader(nullptr)
		{
			LoadShaders("default", vShaderDefault, fShaderDefault);
		}

		void ShaderManager::LoadShaders(const std::string & name, const std::string & pathV, const std::string & pathF)
		{
			Shader* shader1 = new Shader();
			shader1->CreateFromFiles(pathV.c_str(), pathF.c_str());
			shaderList[name]=(*shader1);
			Activate(name);
		}

		ShaderManager* ShaderManager::getPtr()
		{
			if (ptr == nullptr)
			{
				ptr = new ShaderManager();
			}
			return ptr;
		}
		
		GLint ShaderManager::GetViewLocation()
		{
			return uniformView;
		}

		GLint ShaderManager::GetProjectionLocation()
		{
			return uniformProjection;
		}

		GLint ShaderManager::GetModelLocation()
		{
			return uniformModel;
		}

		GLint ShaderManager::GetSpecularIntensityLocation()
		{
			return uniformSpecularIntensity;
		}
		glm::mat4 ShaderManager::GetViewMatrix()
		{
			return camera->calculateViewMatrix();
		}

		glm::mat4 ShaderManager::GetProjectionMatrix()
		{
			return projection;
		}

		GLint ShaderManager::GetShininessLocation()
		{
			return uniformShininess;
		}
		void ShaderManager::draw()
		{
			if (currentShader != nullptr)
			{
				currentShader->UseShader();
				glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
				glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->calculateViewMatrix()));
				glUniform3f(uniformEyePosition, camera->getCameraPosition().x, camera->getCameraPosition().y, camera->getCameraPosition().z);

				mainLight = DirectionalLight(0.5f, 0.5f, 0.5f,
					.3f, .3f,
					0.0f, 0.0f, -1.0f);

				unsigned int pointLightCount = 0;
				pointLights[0] = PointLight(0.0f, 1.0f, 0.0f,
					10.2f, 10.2f,
					30.0f, 3.0f, 0.0f,
					0.3f, 0.2f, 0.1f);
				pointLightCount++;
				pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,
					.7f, .7f,
					-1.0f, 0.0f, 0.0f,
					0.3f, 0.2f, 0.1f);
				pointLightCount++;

				currentShader->SetDirectionalLight(&mainLight);
				currentShader->SetPointLights(pointLights, pointLightCount);
			}
		}
		void ShaderManager::initShader(Camera* camera)
		{
			if (currentShader != nullptr)
			{
				this->camera = camera;
				projection = glm::perspective(45.0f, (float)Platform::GetPtr()->GetWidth() / Platform::GetPtr()->GetHeight(), 0.1f, 1000.0f);
				

			}

		}

		void ShaderManager::Activate(const std::string & name)
		{
			if (shaderList.find(name) != shaderList.end())
			{
				currentShader = &shaderList[name];
				uniformModel = currentShader->GetModelLocation();
				uniformProjection = currentShader->GetProjectionLocation();
				uniformView = currentShader->GetViewLocation();

				uniformAmbientColour = currentShader->GetAmbientColourLocation();
				uniformAmbientIntensity = currentShader->GetAmbientIntensityLocation();
				uniformDirection = currentShader->GetDirectionLocation();
				uniformDiffuseIntensity = currentShader->GetDiffuseIntensityLocation();
				uniformEyePosition = currentShader->GetEyePositionLocation();
				uniformSpecularIntensity = currentShader->GetSpecularIntensityLocation();
				uniformShininess = currentShader->GetShininessLocation();
			}
		}
	}
}