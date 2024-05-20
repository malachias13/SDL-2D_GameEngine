#include "SDL2/SDL.h"
#undef main
#include <iostream>
#include "Game/AsteroidGame.h"

int main() {
	AsteroidGame game;
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
