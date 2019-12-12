#include "SphereCollider.h"

SphereCollider::SphereCollider(float radius, glm::vec3 translation)
{
	this->radius = radius;
	this->_translation = translation;
}

void SphereCollider::SetTranslation(glm::vec3 translation)
{
	this->_translation = translation;
}

bool SphereCollider::CheckCollision(float radius, glm::vec3 translation)
{
	float dist = glm::distance(translation, _translation);
	return dist < (radius + this->radius) ? true : false;
}

glm::vec3 SphereCollider::GetTranslation()
{
	return this->_translation;
}

float SphereCollider::GetRadius()
{
	return radius;
}