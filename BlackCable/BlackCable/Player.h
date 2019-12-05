#ifndef PLAYER_H 
#define PLAYER_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class Player
{
private:
	int life;
	int ammo;
	float distanceOffset;
	float offsetY;
	float speed;
	Camera camera;
	Model *weapon;
	Platform* platform;
	Transform transform;
	float distanceOffset;
	float offsetY;

public:
	Player(glm::vec3 position);
	glm::vec3 GetPlayerPosition()
	{
		return camera.getCameraPosition();
	}

	void Init();
	void Update();
	void Input(const std::map<int, bool> &keys);
	void MouseInput(int x, int y, bool leftbutton);
	void Draw();
private:
	void Shoot(int x,int y);
};

#endif // ! 

