#ifndef CAJAS_H
#define CAJAS_H
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "../Physics/SphereCollider.h"
#include "../Graphic/Camera.h"
#include "../Graphic/Model.h"
#include "../Base/Platform.h"
#include "../Base/ShaderManager.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class Cajas
{
private:
	Model* cajas;
	Platform* platform;
	SphereCollider* sphere;
public:
	Transform transform;
	float GetRadiuas()
	{
		return sphere->GetRadius();
	}

	glm::vec3 GetPosition()
	{
		return sphere->GetPosition();
	}
	Cajas(glm::vec3 position);
	~Cajas();
	void Init();
	void Draw();
};

#endif // !CAJAS_H

