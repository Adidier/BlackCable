#include "CubeModel.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "ShaderManager.h"

CubeModel::CubeModel()
{
}


CubeModel::~CubeModel()
{
}

void CubeModel::Init()
{
	LoadMesh();
	ShaderManager::getPtr()->LoadShaders();
	texture = new Texture("Assets/Textures/brick.png");
	texture->LoadTexture();
	material = new Material(1, 1);
}

void CubeModel::Draw()
{
	GLuint uniformModel = 0;
	uniformModel = ShaderManager::getPtr()->GetModelLocation();
	transform.SetRotate(glm::vec3(1.0f, 1.0f, 0.0f), angle);
	////glm::mat4 model(1);
	////model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
	////model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
	////model = glm::rotate(model, angle, );
	angle += 0.001f;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(transform.GetModel()));
	texture->UseTexture();

	material->UseMaterial();
	meshList[0]->RenderMesh();
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
		-1.0, -1.0,  1.0, 0.0f, 0.0f,		0.4f, 0.0f, 0.8f,//0
		1.0, -1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//1
		1.0,  1.0,  1.0,0.0f, 1.0f,		0.0f, 0.0f, 0.0f,//2
		-1.0,  1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//3
		// back
		-1.0, -1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,//4
		1.0, -1.0, -1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,//5
		1.0,  1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,//6
		-1.0,  1.0, -1.0,0.0f, 1.0f,		0.7f, -0.7f, 0.0f,//7
	};
	calcAverageNormals(indices, 18, vertices, 64, 8, 5);

	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 64, 18);
	meshList.push_back(obj1);
}
