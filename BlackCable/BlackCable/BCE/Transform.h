#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
class Transform
{
public: 
	void setScale(float x, float y, float z);
	void setTranslate(float x, float y, float z);
	void setRotate(float x, float y, float z);
	glm::mat4 setTransformMat4();
	Transform();
	~Transform();

private:
	glm::mat4 model;
	glm::vec3 translate;
	glm::vec3 rotate;
	glm::vec3 scale;
	


};

