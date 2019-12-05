#include "Player.h"

Player::Player(glm::vec3 position)
{
	this->platform = Platform::GetPtr();
	camera = Camera(glm::vec3(-120.0f, 10.0f, -120.0f),glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
	ShaderManager *shaderManager = ShaderManager::getPtr();
	shaderManager->initShader(&camera);

	glm::vec3 offset = glm::vec3(3, -1, 0);
	distanceOffset = glm::length(glm::vec3(offset.x, 0, offset.y));
	offsetY = offset.y;

}

void Player::Init()
{
	weapon = new Model();

	weapon->LoadModel("Assets/Models/Arma_Jugador.obj", 0);
	weapon->AddTexture("ArmaUV.png");
	weapon->AddTexture("Arma_Normal.png");
	
}

void Player::Update()
{

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
	glm::vec3 position = camera.getCameraPosition();
	transform.SetTranslation(position.x +.12, position.y - 0.1, position.z +.1);
	transform.SetScale(0.1f, 0.1f, 0.1f);
	transform.SetRotation(0,0,0);
	
	weapon->SetTransform(&transform);
	weapon->Draw();

	//glm::vec3 position = camera.getCameraPosition();
	//glm::vec3 rotation = camera.GetCameraRotation();

	//float angleOffset = glm::atan(rotation.x, rotation.z);
	//transform.SetScale(1.0f, 1.0f, 1.0f);
	//transform.SetRotation(0, angleOffset- 1.6, 0);
	//transform.SetTranslation(position.x + (rotation.x), position.y + offsetY, (position.z + 0.6) + ( rotation.z));
	//weapon->SetTransform(&transform);
	//weapon->Draw();
}

void Player::Shoot(int x, int y)
{

}