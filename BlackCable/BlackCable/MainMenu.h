#pragma once
#include "BCE/Base/GameState.h"
#include "BCE/Base/GameStateManager.h"
#include "BCE/Graphic/Mesh.h"
#include "BCE/Graphic/Shader.h"
#include "BCE/Base/MenuPlane.h"
#include "BCE/Base/ShaderManager.h"
#include "Player.h"
#include "Game.h"

#include<vector>
using namespace BCE::Base;
using namespace BCE::Lights;
using namespace BCE::Graphics;
using glm::vec3; using std::cout;
class MainMenu : public GameState
{
private:
	Platform* platform;

	GameStateManager* manager;
	ShaderManager* shaderManager;
	Player* player;
	CubeModel* cube;
	MenuPlane* menu;
	PlaneModel* plane;


public:
	MainMenu();
	virtual ~MainMenu();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y, bool leftbutton);
	void Update() override;
	void CreateEnemies();
	void Close() override;

}; 
