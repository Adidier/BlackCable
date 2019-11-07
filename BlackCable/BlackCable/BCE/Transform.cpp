#include "Transform.h"

Transform::Transform()
{
}

void Transform::setRotate(float x, float y, float z) {
	rotate = glm::vec3(x, y, z);
}

void Transform::setTranslate(float x, float y, float z) {
	translate = glm::vec3(x, y, z);
}

void Transform::setScale(float x, float y, float z) {
	scale = glm::vec3(x, y, z);
}

glm::mat4 Transform::getMatTransform() {
	glm::mat4 model(1);
	model = glm::translate(model, translate);
	model = glm::scale(model, rotate);
	model = glm::rotate(model, 0.0f, scale);

	return model;
}


Transform::~Transform()
{
}
