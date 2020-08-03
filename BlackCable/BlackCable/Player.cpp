#include "Player.h"
namespace Game {
	Player::Player(glm::vec3 position)
	{
		this->platform = Platform::GetPtr();
		camera = Camera(glm::vec3(-1.4f, 10.0f, -1.6f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
		ShaderManager* shaderManager = ShaderManager::getPtr();
		shaderManager->initShader(&camera);
		glm::vec3 offset = glm::vec3(3, -1, 0);
		distanceOffset = glm::length(glm::vec3(offset.x, 0, offset.y));
		offsetY = offset.y;
	}

	void Player::Init(std::list<Enemy*> *enemyPool)
	{
		this->enemyPool = enemyPool;
		weapon = new Model();
		weapon->LoadModel("Assets/Models/Weapon.obj");
		weapon->AddTexture("Weapon_UV.png");
		spCollider = new SphereCollider(10, camera.getCameraPosition());
	}

	void Player::MouseInput(int x, int y, bool leftbutton)
	{
		if (x != -1 || y != -1)
			camera.mouseControl(x, y);
	}

	void Player::Input(const std::map<int, bool>& keys)
	{
		camera.keyControl(keys, platform->GetDeltaTime());
	}

	void Player::Update()
	{
		spCollider->SetTranslation(camera.getCameraPosition());

		for (auto ene : *enemyPool)
		{
			if (spCollider->CheckCollision(ene->GetRadius(), ene->GetTranslation()))
			{
				//TRABAJAR
			}
		}

	}

	void Player::Draw()
	{
		glm::vec3 position = camera.getCameraPosition();
		glm::vec3 rotation = camera.getCameraRotation();

		float angleOffset = glm::atan(rotation.x, rotation.z);

		transform.SetTranslation(0, 0, 0);
		transform.SetScale(1.1f, 1.1f, 1.11f);
		transform.SetRotation(0, angleOffset - 1.57f, 0);
		transform.SetTranslation(position.x + (distanceOffset * rotation.x), position.y + offsetY, position.z + (distanceOffset * rotation.z));
		weapon->SetTransform(&transform);
		weapon->Draw();
	}
	void Player::Shoot(int x, int y)
	{

	}
}
