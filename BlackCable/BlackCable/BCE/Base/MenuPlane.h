#pragma once
#include "../../BCE/Graphic/Mesh.h"
#include "../../BCE/Graphic/Shader.h"
#include "../../BCE/Graphic/Camera.h"
#include"../../BCE/Graphic/BaseModel.h"
#include"../../BCE/Graphic/Texture.h"
#include "../../BCE/Graphic/Material.h"
#include "../Lights/Light.h"
#include<vector>

namespace BCE
{
	namespace Graphics
	{

		class MenuPlane : BaseModel
		{
		public:
			MenuPlane();
			~MenuPlane();
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