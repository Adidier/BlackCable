#include "Camera.h"
namespace BCE
{
	namespace Graphics
	{


		Camera::Camera() {}

		Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
		{
			firstMove = true;
			position = startPosition;
			worldUp = startUp;
			yaw = startYaw;
			pitch = startPitch;
			front = glm::vec3(0.0f, 0.0f, -1.0f);

			moveSpeed = startMoveSpeed;
			turnSpeed = startTurnSpeed;

			update();
		}

		void Camera::keyControl(std::map<int, bool> keys, GLfloat deltaTime)
		{
			GLfloat velocity = moveSpeed * deltaTime;

			if (keys[GLFW_KEY_W])
			{
				position += front * velocity;
			}

			if (keys[GLFW_KEY_S])
			{
				position -= front * velocity;
			}

			if (keys[GLFW_KEY_A])
			{
				position -= right * velocity;
			}

			if (keys[GLFW_KEY_D])
			{
				position += right * velocity;
			}
		}

		glm::vec3 Camera::getCameraPosition()
		{
			return position;
		}

		void Camera::mouseControl(GLfloat xChange, GLfloat yChange)
		{
			if (firstMove) {
				prevXPos = xChange;
				prevYPos = yChange;
				firstMove = false;
			}

			float xoffset = xChange - prevXPos;
			float yoffset = yChange - prevYPos;

			prevXPos = xChange;
			prevYPos = yChange;

			xoffset *= turnSpeed;
			yoffset *= turnSpeed;

			yaw += xoffset;
			pitch -= yoffset;

			if (pitch > 89.0f)
			{
				pitch = 89.0f;
			}

			if (pitch < -89.0f)
			{
				pitch = -89.0f;
			}

			update();
		}

		glm::mat4 Camera::calculateViewMatrix()
		{
			return glm::lookAt(position, position + front, up);
		}

		void Camera::update()
		{
			front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			front.y = sin(glm::radians(pitch));
			front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			front = glm::normalize(front);

			right = glm::normalize(glm::cross(front, worldUp));
			up = glm::normalize(glm::cross(right, front));
		}


		Camera::~Camera()
		{
		}
	}
}