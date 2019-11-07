#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

class Transform
{
private:
	glm::mat4 model;
	glm::vec3 rotate;
	glm::vec3 scale;
	glm::vec3 translate;
public:
	Transform();
	glm::mat4 getMatTransform();
	void setRotate(float x, float y, float z);
	void setTranslate(float x, float y, float z);
	void setScale(float x, float y, float z);
	~Transform();
};

