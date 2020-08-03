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

namespace Game {
	using namespace BCE::Base;
	using namespace BCE::Graphics;

	class Player
	{
	private:
		int life;
		int ammo;
		float speed;
		Camera camera;
		Model *weapon;
		Platform* platform;
		Transform transform;
		float distanceOffset;
		float offsetY;
		SphereCollider *spCollider;
		std::list<Enemy*> *enemyPool;
	public:
		Player(glm::vec3 position);
		void Init(std::list<Enemy*> *enemyPool);
		void Input(const std::map<int, bool> &keys);
		void MouseInput(int x, int y, bool leftbutton);
		void Draw();
		void Update();
	private:
		void Shoot(int x, int y);
	};
}
#endif // ! 


