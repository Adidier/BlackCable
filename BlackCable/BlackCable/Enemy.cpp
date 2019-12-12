#include "Enemy.h"

glm::vec3 Enemy::GetPosition()
{
	return spCollider->GetPosition();

}
float Enemy::GetRadius()
{
	return spCollider->GetRadius();
}