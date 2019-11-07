#include "Transform.h"
Transform::Transform() {
	angle = 0;
	rotate = glm::vec3(0);
	translate = glm::vec3(0);
	scale = glm::vec3(1);
}
Transform::~Transform() {

}
void Transform::SetRotate(float x, float y, float z, float angle) {
	this->angle = angle;
	rotate = glm::vec3(x, y, z);
}
void Transform::SetTranslate(float x, float y, float z) {
	translate = glm::vec3(x, y, z);
}
void Transform::SetScale(float x, float y, float z) {
	scale = glm::vec3(x, y, z);
}
void Transform::SetRotate(glm::vec3 rotate, float angle) {
	this->rotate = rotate;
	this->angle = angle;
}
void Transform::SetTranslate(glm::vec3 translate) {
	this->translate = translate;
}
void Transform::SetScale(glm::vec3 scale) {
	this->scale = scale;
}
glm::mat4 Transform::GetModel() {
	model = glm::mat4(1);
	model = glm::translate(model, translate);
	model = glm::scale(model, scale);
	model = glm::rotate(model, angle, rotate);
	return model;
}