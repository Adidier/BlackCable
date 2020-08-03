#include "EnemyT5.h"
namespace Game {
	EnemyT5::EnemyT5(glm::vec3 position, Player *player)
	{
		this->player = player;
		this->platform = Platform::GetPtr();
		transform.SetTranslation(position.x, position.y, position.z);
	}

	void EnemyT5::Update()
	{
		spCollider->SetTranslation(transform.GetTranslation());
	}

	void EnemyT5::Init()
	{
		weapon = new Model();
		weapon->LoadModel("Assets/Models/Enemy2.obj");
		weapon->AddTexture("Weapon_UV.png");
		spCollider = new SphereCollider(10, transform.GetTranslation());
	}

	void EnemyT5::Draw()
	{
		transform.SetScale(1.1f, 1.1f, 1.11f);
		transform.SetRotation(0, 0, 0);
		weapon->SetTransform(&transform);
		weapon->Draw();
	}
	void EnemyT5::Shoot()
	{

	}
}