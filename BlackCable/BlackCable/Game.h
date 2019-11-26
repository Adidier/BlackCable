#pragma once
#include "BCE/Base/GameState.h"
#include "BCE/Base/GameStateManager.h"
#include "BCE/Graphic/Mesh.h"
#include "BCE/Graphic/Shader.h"
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/CubeModel.h"
#include "BCE/Graphic/PlaneModel.h"
#include "BCE/Base/ShaderManager.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Graphic/Skybox.h"
#include "Player.h"

#include<vector>
using namespace BCE::Base;
using namespace BCE::Lights;
using namespace BCE::Graphics;
class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	ShaderManager* shaderManager;
	Player* player;
	CubeModel *cube;
	PlaneModel* plane;
	Model *enemy;
	Skybox skybox;


public:
	Game();
	virtual ~Game();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y, bool leftbutton);
	void Update() override;
	void Close() override;

};