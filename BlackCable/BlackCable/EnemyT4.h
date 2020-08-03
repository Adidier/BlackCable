#ifndef ENEMYT4_H 
#define ENEMYT4_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "Player.h"
#include "Enemy.h"

namespace Game {
	using namespace BCE::Base;
	using namespace BCE::Graphics;

	class EnemyT4 : public Enemy
	{
	public:
		EnemyT4(glm::vec3 position, Player *player);
		void Init();
		void Update();
		void Draw();
	private:
		void Shoot();
	};
}
#endif // ! 

