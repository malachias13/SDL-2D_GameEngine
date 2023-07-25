#include "SDL2/SDL.h"
#undef main
#include <iostream>
#include "Game.h"
#include "CardGame.h"

int main() {
	CardGame game;
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();

	}
	for (int i = 0; i < game.GetTimeManager()->Threads.size(); i++) {
		game.GetTimeManager()->Threads[i].join();
	}
	game.Shutdown();
	return 0;
}
