#ifndef SKYBOX_H
#define SKYBOX_H

#include <vector>
#include <string>
#include <GL\glew.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "Mesh.h"
#include "Shader.h"
#include "../Base/ShaderManager.h"

namespace BCE
{
	namespace Graphics
	{
		using namespace Base;

		class Skybox
		{
		public:
			Skybox();

			Skybox(std::vector<std::string> faceLocations);

			void Draw(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

			~Skybox();

		private:
			Mesh* skyMesh;
			GLuint textureId;
			GLuint uniformProjection, uniformView;
			ShaderManager *shaderManager;
		};

	}
}

#endif