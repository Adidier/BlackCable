#include "Player.h"

Player::Player(glm::vec3 position)
{
	this->platform = Platform::GetPtr();
	camera = Camera(glm::vec3(-1.4f, 10.0f, -1.6f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
	ShaderManager *shaderManager = ShaderManager::getPtr();
	shaderManager->initShader(&camera);

}

void Player::Init()
{
	weapon = new Model();
	weapon->LoadModel("Assets/Models/pina_pose.obj");
	weapon->AddTexture("pina.png");
	weapon->AddTexture("pina_normal.png");
}

void Player::MouseInput(int x, int y, bool leftbutton)
{
	if (x != -1 || y != -1)
		camera.mouseControl(x, y);
}

void Player::Input(const std::map<int, bool> &keys)
{
	camera.keyControl(keys, platform->GetDeltaTime());
}
void Player::Draw()
{
	auto position = camera.getCameraPosition();
	//transform.SetTranslation(position.x, position.y, position.z+0.1);
	transform.SetScale(1.1f, 1.1f, 1.11f);
	//transform.SetRotation(0, 1, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}
void Player::Shoot(int x, int y)
{

}