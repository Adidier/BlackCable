#pragma once
#include "GameState.h"
#include "Platform.h"
#include <stack>

namespace BCE
{
	namespace Base
	{
		class GameState;

		class GameStateManager
		{
		private:
			std::stack<GameState*> states;
			Platform* platform;
			GameStateManager();
			~GameStateManager();
			static GameStateManager* ptr;
		public:
			static GameStateManager* getPtr();
			void GameLoop();
			void SetState(GameState* state);
			void RealaseState();
		};
	}
}