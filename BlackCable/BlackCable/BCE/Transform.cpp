#include "Transform.h"


void Transform::setScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

void Transform::setTranslate(float x, float y, float z)
{
	translate.x = x;
	translate.y = y;
	translate.z = z;

}

void Transform::setRotate(float x, float y, float z)
{
	rotate = glm::vec3(x, y, z);
}

glm::mat4 Transform::setTransformMat4()
{	

	model = glm::mat4(1.0);	model = glm::translate(model, translate);
	
	model = glm::scale(model,scale);
	
	model = glm::rotate(model, rotate.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, rotate.y, glm::vec3(0, 1, 0));
	model = glm::rotate(model, rotate.z, glm::vec3(0,0,1));

	return model;
}


Transform::Transform() : model(1)
{
	translate = scale = rotate = glm::vec3(0,0,0);
}

Transform::~Transform()
{
}
