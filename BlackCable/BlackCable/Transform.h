#pragma once
#include <gtc\matrix_transform.hpp>

class Transform
{
public:
	Transform();
	~Transform();
	void SetRotate(float, float, float, float);
	void SetTranslate(float, float, float);
	void SetScale(float, float, float);
	void SetRotate(glm::vec3, float);
	void SetTranslate(glm::vec3);
	void SetScale(glm::vec3);
	glm::mat4 GetModel();
private:
	bool hasChanged = false;
	glm::vec3 rotate, translate, scale;
	float angle;
	glm::mat4 model;
};


