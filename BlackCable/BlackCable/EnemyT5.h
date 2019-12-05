#ifndef ENEMYT5_H 
#define ENEMYT5_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "Player.h"
#include "Enemy.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class EnemyT5 : public Enemy
{
public:
	EnemyT5(glm::vec3 position, Player *player);
	void Init();
	void Update();
	void Draw();
	glm::vec3 GetPosition();
	void FollowPlayer(Enemy& enemy, glm::vec3 playerPosition);
private:
	void Shoot();
};

#endif // ! 

