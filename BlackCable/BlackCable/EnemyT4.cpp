#include "EnemyT4.h"


EnemyT4::EnemyT4(glm::vec3 position, Player* player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y, position.z);
}

void EnemyT4::Update()
{
	spCollider->SetTranslation(transform.GetTranslation());
}

void EnemyT4::Init()
{
	weapon = new Model();

	weapon->LoadModel("Assets/Models/Enemigo.obj", 0);
	weapon->AddTexture("EnemigoUV.png");

	spCollider = new SphereCollider(10, transform.GetTranslation());
}

void EnemyT4::Draw()
{
	transform.SetScale(1.1f, 1.1f, 1.11f);
	transform.SetRotation(0, 0, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}
void EnemyT4::Shoot()
{

}