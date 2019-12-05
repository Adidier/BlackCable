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
	delete building;
}

void Game::Init()
{
	std::cout << " Menu Init" << std::endl;
	this->platform = Platform::GetPtr();
	this->manager = GameStateManager::getPtr();
	shaderManager = ShaderManager::getPtr();
	shaderManager->LoadShaders("phong", "Assets/Shaders/Default/phong-shader.vert", "Assets/Shaders/Default/phong-shader.frag");
	shaderManager->LoadShaders("gouraud", "Assets/Shaders/Default/gouraud-shader.vert", "Assets/Shaders/Default/gouraud-shader.frag");

#pragma region Carga de Modelos
	player = new Player(glm::vec3(0, 0, 0));
	player->Init();
	cube = new CubeModel();
	cube->Init();
	plane = new PlaneModel();
	plane->Init();

	building = new Building();
	building->Init();

	cajas = new Cajas(vec3(0, 0, 0));
	cajas->Init();
#pragma endregion
	
#pragma region SkyBox
		std::vector<std::string> skyboxFaces;
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_rt.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_lf.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_up.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_dn.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_bk.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_ft.tga");
		skybox = Skybox(skyboxFaces);
#pragma endregion

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


	//shaderManager->Activate("phong");
	shaderManager->draw();
	player->Draw();
	building->Draw();
	cajas->Draw();

	for(auto enemy : enemyPool)
	{
		enemy->Draw();
	}

	//for(auto caja : cajasPool)
	//{
	//	cajas->Draw();
	//}

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
	player->Update();
	//glm::vec3 tvec3(0, 0, 0);
	//auto caja = new Cajas(tvec3);
	//caja->Init();
	//cajasPool.push_back(caja);

	if(enemyPool.size() < 10)
	{
		if(rand() % 100 < 1)
		{
			int dir = -1;
			if(rand() % 100 > 50)
				dir = 1;
			auto enemy = new EnemyT4(glm::vec3(rand() % 100 * dir, 0, rand() % 100 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}

		if(rand() % 100 < 1)
		{
			int dir = -1;
			if(rand() % 100 > 50)
				dir = 1;
			auto enemy = new EnemyT5(glm::vec3(rand() % 100 * dir, 0, rand() % 100 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}

	}
	
	for(auto enemy : enemyPool)
	{
		//enemy->FollowPlayer(*enemy, player->GetPlayerPosition());
		glm::vec3 playerVec = player->GetPlayerPosition();
		glm::vec3 enemyVec = enemy->GetPosition();
		glm::vec3 distance = playerVec - enemyVec;

		float hyp = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
		distance.x = distance.x / hyp;
		distance.y = distance.y / hyp;
		distance.z = distance.z / hyp;

		glm::vec3 newDistance = enemyVec;
		float y = player->GetPlayerPosition().y;
	
		if(player->GetPlayerPosition().y >  y)
		{
			distance = distance / vec3(50, 50, 50);
			newDistance.x += distance.x;
			newDistance.y += distance.y;
			newDistance.z += distance.z;
		} else
		{
			distance = distance / vec3(50, 0, 50);
			newDistance.x += distance.x;
			newDistance.z += distance.z;
		}


		enemy->transform.SetTranslation(newDistance);
		enemy->Update();
	}

}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}