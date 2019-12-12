#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
	cout << "Main Menu\n";
	
	/*Se cargan los singleton del juego*/
	this->platform = Platform::GetPtr();
	manager = GameStateManager::getPtr();
	shaderManager = ShaderManager::getPtr();
	//Se añaden 
	shaderManager->LoadShaders("phong", "Assets/Shaders/Default/phong-shader.vert", "Assets/Shaders/Default/phong-shader.frag");
	shaderManager->LoadShaders("gouraud", "Assets/Shaders/Default/gouraud-shader.vert", "Assets/Shaders/Default/gouraud-shader.frag");
	player = new Player(glm::vec3(0, 0, 0));
	menu = new MenuPlane();
	menu->Init();

}

void MainMenu::Draw()
{
	platform->RenderClear();

	//player->Draw();	
	shaderManager->Activate("phong");
	shaderManager->draw();
	menu->Draw();

	platform->RenderPresent();

}

bool MainMenu::Input(std::map<int, bool> keys)
{
	return false;
}

bool MainMenu::MouseInput(int x, int y, bool leftbutton)
{
	return false;
}

void MainMenu::Update()
{
	if(glfwGetKey(Platform::GetPtr()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)	//Camina hacia la izquierda
		GameStateManager::getPtr()->SetState(new Game());
}

void MainMenu::Close()
{
	std::cout << " Close Init" << std::endl;

}
