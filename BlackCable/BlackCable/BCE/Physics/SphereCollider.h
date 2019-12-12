#pragma once
#include "../Base/Transform.h"
class SphereCollider
{
	protected:
		float radius;
		glm::vec3 _translation;
	public:
		SphereCollider(float radius, glm::vec3 translation);
		void SetTranslation(glm::vec3 translation);
		glm::vec3 GetTranslation();
		float GetRadius();

		bool CheckCollision(float radius, glm::vec3 translation);
};

