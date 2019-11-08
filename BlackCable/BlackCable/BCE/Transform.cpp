#include "Transform.h"

void Transform::rotate(float x, float y, float z)
{
	mrotate = glm::vec3(x, y, z);
}

void Transform::translate(float x, float y, float z) 
{
	mtranslate = glm::vec3(x, y, z);
}

void Transform::scale(float x, float y, float z) 
{
	mscale = glm::vec3(x, y, z);
}
