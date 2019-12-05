#include "Building.h"

Building::Building()
{
	building = nullptr;
	this->platform = Platform::GetPtr();

}

Building::~Building()
{
}

void Building::Init()
{
	
	building = new Model();
	building->LoadModel("Assets/Models/Edificio.obj", 0);
	building->AddTexture("Edificio.png");


}

void Building::Draw()
{
	transform.SetTranslation(glm::vec3(0.0f,00.0f, 0.0f));
	transform.SetScale(glm::vec3(0.1f, 0.1f, 0.1f));
	transform.SetRotation(glm::vec3(0, 0, 0));
	building->SetTransform(&transform);
	building->Draw();
}
