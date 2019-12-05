#include "BCE/Base/GameStateManager.h"
#include "Game.h"
#include <time.h>

int main(int argc, char* argv[])
{
	srand(time(0));
	auto gameStateManager = GameStateManager::getPtr();
	gameStateManager->SetState(new Game());
	gameStateManager->GameLoop();
	return 0;
}

// Menu 
// Carga de imagenes o Texto
// Game Shooter
// 1 arma 3d (carga de modelos) (tarea)
// 2 enemigos low poly (tarea)
// mostrar daño
// 1 arena props (tarea)
// cajas de municiones
// gameplay TB