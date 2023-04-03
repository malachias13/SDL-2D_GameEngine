#pragma once

#include "SDL2/SDL.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	// Helper functions
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// Window create by SDL
	SDL_Window* mWindow;
	// renderer
	SDL_Renderer* mRenderer;
	// Game should continue to run
	bool mIsRunning;

	int flag = 0;

	// for delta time
	Uint32 mTicksCount;

};

