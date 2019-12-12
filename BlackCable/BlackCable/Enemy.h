#ifndef ENEMY_H 
#define ENEMY_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "BCE/Physics/SphereCollider.h"


using namespace BCE::Base;
using namespace BCE::Graphics;

class Player;

class Enemy
{
protected:
	int life;
	int ammo;
	float speed;
	Model* weapon;
	Platform* platform;
	Player* player;
	SphereCollider* spCollider;
public:
	Transform transform;
	glm::vec3 GetPosition();
	float GetRadius();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
private:
	virtual void Shoot() = 0;
};


#endif // ! 

