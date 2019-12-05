#ifndef ENEMY_H 
#define ENEMY_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "Player.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class Enemy
{
protected:
	int life;
	int ammo;
	float speed;

  	Model* weapon;
	Platform* platform;
	Player* player;
public:
	Transform transform;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual glm::vec3 GetPosition() = 0;
	virtual void FollowPlayer(Enemy&, glm::vec3 playerVector) = 0;
  
  
	Model *weapon;
	Platform* platform;
	Transform transform;
	Player* player;
public:
	virtual void Init() = 0;
	virtual void Update()=0;
	virtual void Draw() = 0;

private:
	virtual void Shoot() = 0;
};


#endif // ! 

