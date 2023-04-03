#include "SDL2/SDL.h"
#undef main
#include <iostream>
#include "Game.h"

int main() {
	Game game;
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
