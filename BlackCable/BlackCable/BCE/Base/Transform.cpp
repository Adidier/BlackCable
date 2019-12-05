#include "Transform.h"
namespace BCE
{
	namespace Base
	{
		Transform::Transform() : _model(1)
		{

		}

		void Transform::SetTranslation(float x, float y, float z)
		{
			_translation.x = x;
			_translation.y = y;
			_translation.z = z;
		}

		void Transform::SetTranslation(glm::vec3 vector)
		{
			_translation = vector;
		}

		void Transform::SetRotation(float x, float y, float z)
		{
			_rotation.x = x;
			_rotation.y = y;
			_rotation.z = z;
		}

		void Transform::SetRotation(glm::vec3 setRotation)
		{
			_rotation = setRotation;
		}

		void Transform::SetScale(float x, float y, float z)
		{
			_scale.x = x;
			_scale.y = y;
			_scale.z = z;
		}

		void Transform::SetScale(glm::vec3 vectorScale)
		{
			_scale = vectorScale;
		}

		glm::mat4 Transform::GetTransform()
		{
			_model = glm::mat4(1.0);
			_model = glm::translate(_model, _translation);
			_model = glm::scale(_model, _scale);
			_model = glm::rotate(_model, _rotation.x, glm::vec3(1, 0, 0));
			_model = glm::rotate(_model, _rotation.y, glm::vec3(0, 1, 0));
			_model = glm::rotate(_model, _rotation.z, glm::vec3(0, 0, 1));
			return _model;
		}
	}
}