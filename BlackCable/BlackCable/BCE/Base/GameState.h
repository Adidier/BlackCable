#pragma once
#include "Platform.h"
#include <map>

namespace BCE
{
	namespace Base
	{

		class Platform;
		class GameStateManager;

		class GameState
		{
		public:
			virtual void Init() = 0;
			virtual void Draw() = 0;
			virtual bool Input(std::map<int, bool> keys) = 0;
			virtual bool MouseInput(int x, int y, bool leftbutton) = 0;
			virtual void Update() = 0;
			virtual void Close() = 0;
		};
	}
}