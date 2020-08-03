#include "Enemy.h"
namespace Game {
	glm::vec3 Enemy::GetTranslation()
	{
		return spCollider->GetTranslation();
	}
	float Enemy::GetRadius()
	{
		return spCollider->GetRadius();
	}
}