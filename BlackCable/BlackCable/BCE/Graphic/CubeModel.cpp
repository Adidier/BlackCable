#include "CubeModel.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "../Base/ShaderManager.h"
namespace BCE
{
	namespace Graphics
	{

		CubeModel::CubeModel()
		{
		}


		CubeModel::~CubeModel()
		{
		}

		void CubeModel::Init()
		{
			LoadMesh();
			texture = new Texture("Assets/Textures/brick.png");
			texture->LoadTexture();
			textureNormal = new Texture("Assets/Textures/bricknormal.png");
			textureNormal->LoadTexture();
			material = new Material(0.5, 0.5);
		}

		void CubeModel::Draw()
		{
			GLuint uniformModel = 0;
			uniformModel = ShaderManager::getPtr()->GetModelLocation();
			angle += 0.0001f;
			if (transform != nullptr)
			{
				transform->SetTranslation(0.0f, 0.0f, -2.5f);
				transform->SetScale(1.0f, 1.0f, 1.0f);
				transform->SetRotation(0, angle, 0);
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(transform->GetTransform()));
			}
			material->UseMaterial(ShaderManager::getPtr()->GetSpecularIntensityLocation(),
				ShaderManager::getPtr()->GetShininessLocation());
			texture->UseTexture(GL_TEXTURE1);
			textureNormal->UseTexture(GL_TEXTURE2);
			 
		//	meshList[0]->RenderMesh();
		}

		void CubeModel::LoadMesh()
		{
			unsigned int indices[] = {
				// front
				0,1,2,
				2,3,0,
				0,4,3,
				4,7,3,
				3,7,6,
				6,3,2

			};

			GLfloat vertices[] = {
				// front
				-1.0, -1.0,  1.0, 0.0f, 0.0f,		0.0f, 0.0f, 0.8f,1.0f, 0.0f, 0.0f,//0
				1.0, -1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//1
				1.0,  1.0,  1.0,0.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//2
				-1.0,  1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//3
				// back
				-1.0, -1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//4
				1.0, -1.0, -1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//5
				1.0,  1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//6
				-1.0,  1.0, -1.0,0.0f, 1.0f,		0.7f, -0.7f, 0.0f,1.0f, 0.0f, 0.0f,//7
			};
			calcAverageNormals(indices, 18, vertices, 88, 11, 5);

			Mesh* obj1 = new Mesh();
			obj1->CreateMesh(vertices, indices, 88, 18, 11);
			meshList.push_back(obj1);
		}
	}
}