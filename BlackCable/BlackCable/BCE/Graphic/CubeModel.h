#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include<vector>
#include"BaseModel.h"
#include"Texture.h"
#include "Material.h"
#include "../Lights/Light.h"
namespace BCE
{
	namespace Graphics
	{

		class CubeModel : BaseModel
		{
		public:
			CubeModel();
			~CubeModel();
			void Init() override;
			void Draw() override;
		private:
			void LoadMesh() override;
			float angle{ 0 };
			Texture* texture;
			Texture* textureNormal;
			Material* material;
		};

	}
}