#include "Platform.h"
#include <iostream>

namespace BCE
{
	namespace Base
	{

		Platform* Platform::ptr;
		GameState* Platform::obj;
		bool (GameState::* Platform::keyboard)(std::map<int, bool>);
		bool (GameState::* Platform::mouse)(int, int, bool);
		std::map<int, bool> Platform::keys;
		bool Platform::leftButtonMouse;

		Platform::Platform(std::string name, int wWindow, int hWindow)
		{
			width = wWindow;
			height = hWindow;
			this->name = name;
			init();
			for (size_t i = 0; i < 1024; i++)
			{
				keys[i] = 0;
			}
		}

		void Platform::init()
		{
			if (!glfwInit())
			{
				std::cout << "Error Initialising GLFW";
				glfwTerminate();
				return;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

			mainWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
			if (!mainWindow)
			{
				printf("Error creating GLFW window!");
				glfwTerminate();
				return;
			}

			// Get buffer size information
			glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

			// Set the current context
			glfwMakeContextCurrent(mainWindow);
			glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			// Allow modern extension access
			glewExperimental = GL_TRUE;

			GLenum error = glewInit();
			if (error != GLEW_OK)
			{
				printf("Error: %s", glewGetErrorString(error));
				glfwDestroyWindow(mainWindow);
				glfwTerminate();
				return;
			}

			glEnable(GL_DEPTH_TEST);

			// Create Viewport
			glViewport(0, 0, bufferWidth, bufferHeight);
		}
		Platform::~Platform()
		{
			glfwDestroyWindow(mainWindow);
			glfwTerminate();
		}

		void Platform::RenderClear()
		{
			// Clear the window
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Platform::RenderPresent()
		{
			glfwSwapBuffers(mainWindow);
		}

		float Platform::GetDeltaTime()
		{
			return deltaTime;
		}

		void Platform::CheckEvent(GameState* obj, bool (GameState::* keyboard)(std::map<int, bool>), bool (GameState::* mouse)(int, int, bool))
		{
			GLfloat now = glfwGetTime();
			deltaTime = now - lastTime;
			lastTime = now;
			glfwPollEvents();
			this->obj = obj;
			this->keyboard = keyboard;
			this->mouse = mouse;
			glfwSetKeyCallback(mainWindow, HandleKeys);
			glfwSetCursorPosCallback(mainWindow, HandleMousePosition);
			glfwSetMouseButtonCallback(mainWindow, HandleMouseButton);
		}
		int Platform::GetWidth()
		{
			return width;
		}

		int Platform::GetHeight()
		{
			return height;
		}

		Platform* Platform::GetPtr()
		{
			if (ptr == nullptr)
			{
				ptr = new Platform("GAME", 640, 480);
			}
			else
			{
				return ptr;
			}
		}

		void  Platform::HandleKeys(GLFWwindow* window, int key, int code, int action, int mode)
		{
			if (key >= 0 && key < 1024)
			{
				if (action == GLFW_PRESS)
				{
					Platform::keys[key] = true;
				}
				else if (action == GLFW_RELEASE)
				{
					Platform::keys[key] = false;
				}
			}
			if (keys[GLFW_KEY_ESCAPE])
				glfwSetWindowShouldClose(window, 1);
			(Platform::obj->*Platform::keyboard)(keys);
		}


		void Platform::HandleMousePosition(GLFWwindow* window, double x, double y)
		{
			(Platform::obj->*Platform::mouse)(x, y, leftButtonMouse);
		}

		void Platform::HandleMouseButton(GLFWwindow* window, int button, int action, int mod)
		{
			(Platform::obj->*Platform::mouse)(-1, -1, action);

		}

		bool Platform::shouldWindowClose() {
			return glfwWindowShouldClose(mainWindow);
		}
	}
}