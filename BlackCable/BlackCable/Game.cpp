#include "Game.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>



Game::Game()
{

}

Game::~Game()
{
	delete player;
	delete cube;
	delete plane;
	delete enemy;
}

void Game::Init()
{
	std::cout << " Menu Init" << std::endl;
	this->platform = Platform::GetPtr();
	this->manager = GameStateManager::getPtr();
	shaderManager = ShaderManager::getPtr();
	shaderManager->LoadShaders("phong", "Assets/Shaders/Default/phong-shader.vert", "Assets/Shaders/Default/phong-shader.frag");
	shaderManager->LoadShaders("gouraud", "Assets/Shaders/Default/gouraud-shader.vert", "Assets/Shaders/Default/gouraud-shader.frag");
	player = new Player(glm::vec3(0, 0, 0));
	player->Init();
	cube = new CubeModel();
	cube->Init();
	plane = new PlaneModel();
	plane->Init();
	enemy = new Model();
	enemy->LoadModel("Assets/Models/Weapon.obj");
	enemy->AddTexture("Weapon_UV.png");
	enemy->AddTexture("Weapon_Normal.png");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_ft.tga");
	skybox = Skybox(skyboxFaces);
}

void Game::Draw()
{
	platform->RenderClear();
	skybox.Draw(shaderManager->GetViewMatrix(), shaderManager->GetProjectionMatrix());
	
	shaderManager->Activate("gouraud");
	shaderManager->draw();
	cube->Draw();
	
	shaderManager->Activate("phong");
	shaderManager->draw();
	plane->Draw();
	//enemy->Draw();
	player->Draw();
	platform->RenderPresent();
}

bool Game::MouseInput(int x, int y, bool leftbutton)
{
	player->MouseInput(x, y, leftbutton);

	return false;
}

bool Game::Input(std::map<int, bool> keys)
{
	player->Input(keys);
	return false;
}

void Game::Update()
{

}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}