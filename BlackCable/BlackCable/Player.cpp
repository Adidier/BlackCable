#include "Player.h"
#include <irrKlang.h>
using namespace irrklang;
ISoundEngine* SoundEngine = createIrrKlangDevice();

/*Obtenido de http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/ */

//Detecci�n del enemigo por medio del ray cast
class ray
{
public:
	ray() {}
	ray(const glm::vec3& a, const glm::vec3& b) { A = a; B = b; }
	glm::vec3 orgin() const { return A; }
	glm::vec3 direction() const { return B; }
	glm::vec3 point_at_parameter(float t) const { return A + t * B; }

	glm::vec3 A;
	glm::vec3 B;
};

bool hit_sphere(const glm::vec3& center, float radius, const ray& r)
{
	glm::vec3 oc = r.orgin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}


Player::Player(glm::vec3 position)
{
	killed = false;
	this->platform = Platform::GetPtr();
	camera = Camera(position, glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
	ShaderManager* shaderManager = ShaderManager::getPtr();
	shaderManager->initShader(&camera);
	glm::vec3 offset = glm::vec3(3, -1, 0);
	distanceOffset = glm::length(glm::vec3(offset.x, 0, offset.y));
	offsetY = offset.y;
}


void Player::Init(std::list<Enemy*>* enemyPool, std::list<Cajas*>* boxPool)
{
	ammo = 10;
	this->enemyPool = enemyPool;
	weapon = new Model();
	weapon->LoadModel("Assets/Models/Arma_Jugador.obj",0);
	weapon->AddTexture("ArmaUV.png");
	spCollider = new SphereCollider(10, camera.getCameraPosition());
	this->boxPool = boxPool;

}

void Player::MouseInput(int x, int y, bool leftbutton)
{
	if(x != -1 || y != -1)
		camera.mouseControl(x, y);

	
}

void Player::Input(const std::map<int, bool>& keys)
{
	camera.keyControl(keys, platform->GetDeltaTime());
}

void Player::Update()
{
	spCollider->SetTranslation(camera.getCameraPosition());

	for(auto ene : *enemyPool)
	{
		if(spCollider->CheckCollision(ene->GetRadius(), ene->GetPosition()))
		{
			printf("Muerto\n");
			killed = true;

		}

	}
	
	for(auto caja : *boxPool)
	{
		if(spCollider->CheckCollision(caja->GetRadiuas(), caja->GetPosition()))
		{
			if(ammo < 10)
				ammo = 10;
			std::cout << ammo << std::endl;
		}
	}

	if(glfwGetMouseButton(platform->GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		if(ammo > 0)
			if(Shoot())
			{
				std::cout << ammo << std::endl;
				ammo--;
				std::cout << ammo << std::endl;

			}
	}

	/*int state = glfwGetMouseButton(platform->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	if(state == GLFW_PRESS)
	{
		if(ammo > 0)
			if(Shoot())
			{
				std::cout << ammo << std::endl;
				ammo--;
				std::cout << ammo << std::endl;
			
			}

	}*/


}

bool Player::Shoot()
{	
     SoundEngine->play2D("Assets/SFX/Shotgun.mp3", GL_FALSE);
	
	Detection();
	return true;
}

bool Player::Detection()
{
	glm::vec3 position = camera.getCameraPosition();
	glm::vec3 rotation = camera.getCameraRotation();

	float angleOffset = glm::atan(rotation.x, rotation.z);
	glm::vec3 offset = glm::vec3(-1, -1, 0);

	distanceOffset = glm::length(glm::vec3(offset.x, 0, offset.y));

	glm::vec3 origin = glm::normalize(glm::vec3(position.x + ((distanceOffset)*rotation.x),
												position.y, position.z + ((distanceOffset)*rotation.z)));
	ray ray1 = ray(glm::vec3(0, 0, 0), origin);

	for(auto ene : *enemyPool)
	{
		if(hit_sphere(ene->GetPosition(), ene->GetRadius(), ray1))
		{
			printf("Choco!\n");
			enemyPool->remove(ene);
			delete ene;
			return true;
		}
	}
	return false;

}




void Player::Draw()
{
	glm::vec3 position = camera.getCameraPosition();
	glm::vec3 rotation = camera.getCameraRotation();

	float angleOffset = glm::atan(rotation.x, rotation.z);

	transform.SetTranslation(0, 0, 0);
	transform.SetScale(1.1f, 1.1f, 1.11f);
	transform.SetRotation(0, angleOffset - 1.57f, 0);
	transform.SetTranslation(position.x + (distanceOffset * rotation.x), position.y + offsetY, position.z + (distanceOffset * rotation.z));
	weapon->SetTransform(&transform);
	weapon->Draw();
}

