#pragma once
#include "BCE/GameState.h"
#include "BCE/GameStateManager.h"
#include "BCE/Mesh.h"
#include "BCE/Shader.h"
#include "BCE/Camera.h"
#include "BCE/Light.h"
#include<vector>
class Menu : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;

	std::vector<Mesh*> meshList;
	std::vector<Shader> shaderList;

	const char* vShader = "Assets/Shaders/Menu/shader.vert";

	// Fragment Shader
	const char* fShader = "Assets/Shaders/Menu/shader.frag";
	Camera camera;
	float angle{ 0 };
	Light mainLight;
public:
	Menu();
	~Menu();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y);
	void Update() override;
	void Close() override;
	void LoadShaders();
	void LoadModels();

};