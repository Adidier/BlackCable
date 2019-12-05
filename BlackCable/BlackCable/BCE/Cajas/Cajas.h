#ifndef CAJAS_H
#define CAJAS_HA
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
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
public:
	Transform transform;
	Cajas(glm::vec3 position);
	~Cajas();
	void Init();
	void Draw();
};

#endif // !CAJAS_H

