#include "EnemyT4.h"


EnemyT4::EnemyT4(glm::vec3 position, Player* player)

{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y, position.z);
}

void EnemyT4::Update()
{

}

void EnemyT4::Init()
{
	weapon = new Model();

	weapon->LoadModel("Assets/Models/Enemigo.obj", 0);
	weapon->AddTexture("EnemigoUV.png");

	weapon->LoadModel("Assets/Models/Enemy1.obj");
	weapon->AddTexture("Weapon_UV.png");

}

void EnemyT4::Draw()
{
	transform.SetScale(1.1f, 1.1f, 1.11f);
	transform.SetRotation(0, 0, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}

glm::vec3 EnemyT4::GetPosition()
{
	return transform.GetTranslation();
}
void EnemyT4::FollowPlayer(Enemy& enemy, glm::vec3 playerVector)
{
	glm::vec3 distance = playerVector - enemy.GetPosition();
	float hyp = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
	distance = distance / hyp;

	glm::vec3 d = enemy.GetPosition();
	d += distance / glm::vec3(100, 0, 100);
	transform.SetTranslation(d);

	
}

void EnemyT4::Shoot()
{

}