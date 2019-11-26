#pragma once

#include <GL\glew.h>
#include <glm.hpp>
namespace BCE
{
	namespace Lights
	{

		class Light
		{
		public:
			Light();
			Light(GLfloat red, GLfloat green, GLfloat blue,
				GLfloat aIntensity, GLfloat dIntensity);
			~Light();
		protected:
			glm::vec3 colour;
			GLfloat ambientIntensity;
			GLfloat diffuseIntensity;
		};

	}
}