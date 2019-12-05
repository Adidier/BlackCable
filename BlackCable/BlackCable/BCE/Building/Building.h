#ifndef BUILDING_H
#define BUILDING_H
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "../Graphic/Camera.h"
#include "../Graphic/Model.h"
#include "../Base/Platform.h"
#include "../Base/ShaderManager.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class Building
{
private:
	Model* building;
	Transform transform;
	Platform* platform;

public:
	Building();
	~Building();
	
	void Init();
	void Draw();

};


#endif // !BUILDING_H