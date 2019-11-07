#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>
#include"Model.h"
#include"Texture.h"
#include "Material.h"
#include "Light.h"

class CubeModel : Model
{
public:
	CubeModel();
	~CubeModel();
	void Init() override;
	void Draw() override;
private:
	void LoadMesh() override;
	float ex;
	float angle{ 0 };
	Texture *texture;
	Material* material;
};

