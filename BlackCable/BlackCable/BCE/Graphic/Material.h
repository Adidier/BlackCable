#pragma once

#include <GL\glew.h>

namespace BCE
{
	namespace Graphics
	{
		class Material
		{
		public:
			Material();
			Material(GLfloat sIntensity, GLfloat shine);

			void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

			~Material();

		private:
			GLfloat specularIntensity;
			GLfloat shininess;
		};

	}
}