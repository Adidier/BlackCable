#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
namespace BCE
{
	namespace Base
	{
		class Transform
		{
		public:
			void SetTranslation(float x, float y, float z);
			void SetRotation(float x, float y, float z);
			void SetScale(float x, float y, float z);
			glm::mat4 GetTransform();
			Transform();
		private:
			glm::vec3 _translation;
			glm::vec3 _rotation;
			glm::vec3 _scale;
			glm::mat4 _model;
		};
	}
}