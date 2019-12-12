#include "Game.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "MainMenu.h"

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
	//Se añaden los shaders
	shaderManager->LoadShaders("phong", "Assets/Shaders/Default/phong-shader.vert", "Assets/Shaders/Default/phong-shader.frag");
	shaderManager->LoadShaders("gouraud", "Assets/Shaders/Default/gouraud-shader.vert", "Assets/Shaders/Default/gouraud-shader.frag");

#pragma region Carga de Modelos
	//Jugador
	player = new Player(glm::vec3(-130, 10, -130));
	player->Init(&enemyPool, &cajasPool);
	
	//Cubo
	cube = new CubeModel();
	cube->Init();
	
	//Plano
	plane = new PlaneModel();
	plane->Init();

	//Edificio
	building = new Building();
	building->Init();
	
	auto caja = new Cajas(vec3(0, 10, 130));
	auto caja2 = new Cajas(vec3(0, 10, -130));
	auto caja3 = new Cajas(vec3(130, 10, 0));
	auto caja4 = new Cajas(vec3(-130, 10, 0));

	cajasPool.push_back(caja);
	cajasPool.push_back(caja2);
	cajasPool.push_back(caja3);
	cajasPool.push_back(caja4);


	//Carga de modelos de las cajas, aquí inician
	std::list<Cajas*>::iterator it = cajasPool.begin();
	while(it != cajasPool.end())
	{
		(*it)->Init();
		it++;
	}
	

	//Modelo de cajas
	cajas = new Cajas(vec3(0, 0, -130));
	cajas->Init();
#pragma endregion	Carga de todos los modelos

	
#pragma region SkyBox
		std::vector<std::string> skyboxFaces;
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_rt.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_lf.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_up.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_dn.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_bk.tga");
		skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_ft.tga");
		skybox = Skybox(skyboxFaces);
#pragma endregion Carga de la SkyBox

}

void Game::Draw()
{
	//Se dibujan todos los modelos, activando y desactivando diferentes tipos de shaders
	platform->RenderClear();
	skybox.Draw(shaderManager->GetViewMatrix(), shaderManager->GetProjectionMatrix());

	shaderManager->Activate("gouraud");
	shaderManager->draw();
	cube->Draw();

	shaderManager->Activate("phong");
	shaderManager->draw();
	plane->Draw();

	shaderManager->draw();
	player->Draw();
	building->Draw();
	cajas->Draw();

	for(auto enemy : enemyPool)
	{
		enemy->Draw();
	}

	//Etapa de dibujado de las cajas
	std::list<Cajas*>::iterator it = cajasPool.begin();
	while(it != cajasPool.end())
	{
		(*it)->Draw();
		it++;
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
	int random = rand() % 2 + 1;

	if(enemyPool.size() < 10)
	{
		if(random == 2)
		{
			int dir = -1;
			if(random == 2)
				dir = 1;
			auto enemy = new EnemyT4(glm::vec3(rand() % 100 * dir, 0, rand() % 100 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}

		if(random == 1)
		{
			int dir = -1;
			if(random == 1)
				dir = 1;
			auto enemy = new EnemyT5(glm::vec3(rand() % 100 * dir, 0, rand() % 100 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}

	}
	
	for(auto enemy : enemyPool)
	{
		//enemy->FollowPlayer(*enemy, player->GetPlayerPosition());
		glm::vec3 playerVec = player->GetPlayerPosition();	//Guarda la posición del jugador
		glm::vec3 enemyVec = enemy->GetPosition();			//Guarda la posición del enemigo
		glm::vec3 distance = playerVec - enemyVec;			//Resta las dos distancias anterior

		float hyp = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));	//Consigue el valor de la hipotenusa
		distance.x = distance.x / hyp;	//Divide la distancia entre la hipotenusa
		distance.y = distance.y / hyp;	//Divide la distancia entre la hipotenusa
		distance.z = distance.z / hyp;	//Divide la distancia entre la hipotenusa

		distance = distance / vec3(50, 0, 50);	//Dividir el resultado de la distancia entre 20
		enemyVec.x += distance.x;//Sumar la nueva distancia a la distancia original
		enemyVec.z += distance.z;//Sumar la nueva distancia a la distancia original


		enemy->transform.SetTranslation(enemyVec.x, enemyVec.y, enemyVec.z);
		enemy->Update();
	}
	player->Update();

	if(player->killed)
		GameStateManager::getPtr()->SetState(new MainMenu());


}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}