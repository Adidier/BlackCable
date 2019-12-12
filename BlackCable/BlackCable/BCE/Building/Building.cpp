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
	transform.SetTranslation(0,0,0);
	transform.SetScale(.1f,.1f,.1f);
	transform.SetRotation(0,0,0);
	building->SetTransform(&transform);
	building->Draw();
}
