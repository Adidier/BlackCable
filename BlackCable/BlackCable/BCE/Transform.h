#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
class Transform
{	
public:
	void rotate(float x, float y, float z);
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	//glm::mat4 getModel() { return m; }
	glm::mat4 setModel() { 
		m = glm::mat4(1);
		m = glm::translate(m, mtranslate);
		m = glm::scale(m, mscale);
		m = glm::rotate(m, mrotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
		m = glm::rotate(m, mrotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
		m = glm::rotate(m, mrotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
		return m;
	}
private:
	glm::mat4 m;
	glm::vec3 mtranslate;
	glm::vec3 mrotate;
	glm::vec3 mscale;
};

