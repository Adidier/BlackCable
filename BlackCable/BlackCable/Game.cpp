#include "Game.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>


namespace Game {
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
		player->Init(&enemyPool);
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

		//text = Text();
		text.LoadFont("Assets/Fonts/arial.ttf");

		CreateEnemies();
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


		shaderManager->Activate("phong");
		shaderManager->draw();
		player->Draw();

		//text.RenderText("This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));

		for (auto enemy : enemyPool)
		{
			enemy->Draw();
		}
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


		for (auto enemy : enemyPool)
		{
			enemy->Update();
		}
		player->Update();
	}

	void Game::CreateEnemies()
	{

		while (enemyPool.size() < 10)
		{
			if (rand() % 100 < 1)
			{
				int dir = -1;
				if (rand() % 100 > 50)
					dir = 1;
				auto enemy = new EnemyT4(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
				enemy->Init();
				enemyPool.push_back(enemy);
			}

			if (rand() % 100 < 1)
			{
				int dir = -1;
				if (rand() % 100 > 50)
					dir = 1;
				auto enemy = new EnemyT5(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
				enemy->Init();
				enemyPool.push_back(enemy);
			}
		}
	}

	void Game::Close()
	{
		std::cout << " Close Init" << std::endl;
	}
}