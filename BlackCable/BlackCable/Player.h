#ifndef PLAYER_H 
#define PLAYER_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h" 
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "BCE/Physics/SphereCollider.h"
#include <list>
#include "Enemy.h"
#include "BCE/Cajas/Cajas.h"


using namespace BCE::Base;
using namespace BCE::Graphics;



class Player
{
private:
	int life;
	int ammo;
	float speed;
	Camera camera;
	Model* weapon;
	Model* bullet;
	Platform* platform;
	Transform transform;
	float distanceOffset;
	float offsetY;
	SphereCollider* spCollider;
	std::list<Enemy*>* enemyPool;
	std::list<Cajas*>* boxPool;
public:
	glm::vec3 GetPlayerPosition()
	{
		return camera.getCameraPosition();
	}
	int getAmmo()
	{
		return ammo;
	}
	void setAmmo()
	{
		ammo--;
	}
	bool killed;
	Player(glm::vec3 position);
	void Init(std::list<Enemy*>* enemyPool, std::list<Cajas*>* boxPool);
	void Input(const std::map<int, bool>& keys);
	void MouseInput(int x, int y, bool leftbutton);
	void Draw();
	void Update();
	bool Shoot();
private:
	bool Detection();
};

#endif // ! 

