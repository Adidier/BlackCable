#include "Skybox.h"
#include "stb_image.h"
namespace BCE
{
	namespace Graphics
	{


		Skybox::Skybox()
		{
		}

		Skybox::Skybox(std::vector<std::string> faceLocations)
		{
			// Shader Setup
			shaderManager = ShaderManager::getPtr();
			shaderManager->LoadShaders("skybox", "Assets/Shaders/Default/skybox.vert", "Assets/Shaders/Default/skybox.frag");


			uniformProjection = shaderManager->GetProjectionLocation();
			uniformView = shaderManager->GetViewLocation();


			// Texture Setup
			glGenTextures(1, &textureId);
			glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);

			int width, height, bitDepth;

			for (size_t i = 0; i < 6; i++)
			{
				unsigned char* texData = stbi_load(faceLocations[i].c_str(), &width, &height, &bitDepth, 0);
				if (!texData)
				{
					printf("Failed to find: %s\n", faceLocations[i].c_str());
					return;
				}

				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
				stbi_image_free(texData);
			}

			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glBindTexture(GL_TEXTURE_2D, 0);

			// Mesh Setup
			unsigned int skyboxIndices[] = {
				// front
				0, 1, 2,
				2, 1, 3,
				// right
				2, 3, 5,
				5, 3, 7,
				// back
				5, 7, 4,
				4, 7, 6,
				// left
				4, 6, 0,
				0, 6, 1,
				// top
				4, 0, 5,
				5, 0, 2,
				// bottom
				1, 6, 3,
				3, 6, 7
			};

			float skyboxVertices[] = {
				-1.0f, 1.0f, -1.0f,		
				-1.0f, -1.0f, -1.0f,	
				1.0f, 1.0f, -1.0f,		
				1.0f, -1.0f, -1.0f,		

				-1.0f, 1.0f, 1.0f,	
				1.0f, 1.0f, 1.0f,	
				-1.0f, -1.0f, 1.0f,	
				1.0f, -1.0f, 1.0f,	
			};

			skyMesh = new Mesh();
			skyMesh->CreateMesh(skyboxVertices, skyboxIndices, 24, 36,3);
		}

		void Skybox::Draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
		{
			shaderManager->Activate("skybox");
			shaderManager->draw();
			viewMatrix = glm::mat4(glm::mat3(viewMatrix));
			glDepthMask(GL_FALSE);
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(viewMatrix));
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
			skyMesh->RenderMesh();
			glDepthMask(GL_TRUE);
		}

		Skybox::~Skybox()
		{
		}

	}
}