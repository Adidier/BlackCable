#pragma once

#include <map>
#include <GL\glew.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <GLFW\glfw3.h>

namespace BCE
{
	namespace Graphics
	{

		class Camera
		{
		public:
			Camera();
			Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

			void keyControl(std::map<int, bool> keys, GLfloat deltaTime);
			void mouseControl(GLfloat xChange, GLfloat yChange);

			glm::mat4 calculateViewMatrix();
			glm::vec3 getCameraPosition();
			glm::vec3 getCameraRotation();
			~Camera();

		private:
			glm::vec3 position;
			glm::vec3 front;
			glm::vec3 up;
			glm::vec3 right;
			glm::vec3 worldUp;

			GLfloat yaw;
			GLfloat pitch;

			GLfloat moveSpeed;
			GLfloat turnSpeed;
			GLfloat prevXPos, prevYPos;
			float firstMove;

			void update();
		};

	}
}