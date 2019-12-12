#include "MenuPlane.h"
#include "../Base/ShaderManager.h"

BCE::Graphics::MenuPlane::MenuPlane()
{
}

BCE::Graphics::MenuPlane::~MenuPlane()
{
}

void BCE::Graphics::MenuPlane::Init()
{
	LoadMesh();
	texture = new Texture("Assets/Textures/MainMenu.png");
	texture->LoadTexture();
	//textureNormal = new Texture("Assets/Textures/bricknormal.png");
	//textureNormal->LoadTexture();

	material = new Material(1, 1);
	transform = new Transform(); //Adidier regresa y arregla esto
}

void BCE::Graphics::MenuPlane::Draw()
{
	GLuint uniformModel = 0;
	uniformModel = ShaderManager::getPtr()->GetModelLocation();

	glm::mat4 model(1);
	if(transform != nullptr)
	{
		transform->SetTranslation(1.0f, 7, -3.f);
		transform->SetScale(2.0f, 5.0f, 4.0f);
		transform->SetRotation(1.1f,5.0f, 1.2f);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(transform->GetTransform()));
	}
	material->UseMaterial(ShaderManager::getPtr()->GetSpecularIntensityLocation(),
						  ShaderManager::getPtr()->GetShininessLocation());
	texture->UseTexture(GL_TEXTURE0);
	//textureNormal->UseTexture(GL_TEXTURE1);
	meshList[0]->RenderMesh();

}

void BCE::Graphics::MenuPlane::LoadMesh()
{
	unsigned int indices[] = {
		// front
		0,1,2,
		2,3,0,
	};

	GLfloat vertices[] = {
		-1.0, 1,  -0.0, 0.0f, 0.0f,		0.4f, 0.0f, 0.8f,1.0f, 0.0f, 0.0f,//0
		1.0, 1,  -0.0,  1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//1
		1.0, -1,  0.0,  0.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//2
		-1.0,  -1, 0.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//3
	};
	calcAverageNormals(indices, 6, vertices, 44, 11, 5);

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 44, 6, 11);
	meshList.push_back(obj1);
}

