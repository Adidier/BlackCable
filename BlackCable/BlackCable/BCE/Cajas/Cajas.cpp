#include "Cajas.h"

Cajas::Cajas(glm::vec3 position)
{
	this->platform = Platform::GetPtr();
	cajas = nullptr;
	transform.SetTranslation(position.x, 0, position.z);
	sphere = new SphereCollider(5, transform.GetTranslation());
}

Cajas::~Cajas()
{
	delete cajas;

}

void Cajas::Init()
{
	cajas = new Model();
	cajas->LoadModel("Assets/Models/CajasMunicion.obj",0);
	cajas->AddTexture("Cajas.png");
}

void Cajas::Draw()
{

	transform.SetScale(0.5f,0.5f, 0.5f);
	transform.SetRotation(0,0,0);
	cajas->SetTransform(&transform);
	cajas->Draw();
}
