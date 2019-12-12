#include "Enemy.h"

glm::vec3 Enemy::GetPosition()
{
	return spCollider->GetTranslation();
}
float Enemy::GetRadius()
{
	return spCollider->GetRadius();
}