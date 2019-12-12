//#include "Menu.h"
//#include<iostream>
//#include <glm.hpp>
//#include <gtc\matrix_transform.hpp>
//#include <gtc\type_ptr.hpp>
//
//
//
//Menu::Menu()
//{
//
//}
//
//Menu::~Menu()
//{
//}
//
//void Menu::Init()
//{
//	std::cout << " Menu Init" << std::endl;
//	this->platform = Platform::GetPtr();
//	this->manager = GameStateManager::getPtr();
//	shaderManager = ShaderManager::getPtr();
//	camera = Camera(glm::vec3(-12.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
//	shaderManager->initShader(&camera);
//	cube = new CubeModel();
//	cube->Init();
//	plane = new PlaneModel();
//	plane->Init();
//
//}
//
//void Menu::Draw()
//{
//	platform->RenderClear();
//	shaderManager->draw();
//	cube->Draw();
//	plane->Draw();
//	platform->RenderPresent();
//}
//
//bool Menu::MouseInput(int x, int y)
//{
//
//	camera.mouseControl(x, y);
//
//	return false;
//}
//
//bool Menu::Input(std::map<int, bool> keys)
//{
//	camera.keyControl(keys, platform->GetDeltaTime());
//	///camera.mouseControl(0, 0);
//	return false;
//}
//
//void Menu::Update()
//{
//
//}
//
//void Menu::Close()
//{
//	std::cout << " Close Init" << std::endl;
//}