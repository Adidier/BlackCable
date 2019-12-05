#include "EnemyT5.h"

EnemyT5::EnemyT5(glm::vec3 position, Player *player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y, position.z);
}

void EnemyT5::Update()
{

}

void EnemyT5::Init()
{
	weapon = new Model();

	weapon->LoadModel("Assets/Models/Enemigo_2.obj", 0);
	weapon->AddTexture("Enemigo_2_UV.png");

	weapon->LoadModel("Assets/Models/Enemy2.obj");
	weapon->AddTexture("Weapon_UV.png");

}

void EnemyT5::Draw()
{

	transform.SetScale(1.0f, 1.1f, 1.11f);

	transform.SetScale(1.1f, 1.1f, 1.11f);

	transform.SetRotation(0, 0, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}

glm::vec3 EnemyT5::GetPosition()
{
	return transform.GetTranslation();

}
void EnemyT5::FollowPlayer(Enemy& enemy, glm::vec3 playerPosition)
{
	glm::vec3 distance = playerPosition - enemy.GetPosition();
	float hyp = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
	distance = distance / hyp;

	glm::vec3 d = enemy.GetPosition();
	d += distance / glm::vec3(100, 0, 100);
	transform.SetTranslation(d);
}


void EnemyT5::Shoot()
{

}