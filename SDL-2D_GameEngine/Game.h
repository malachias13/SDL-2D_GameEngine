#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>

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

	int flags = 0;

	// for delta time
	Uint32 mTicksCount;

private:
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;
	
	bool mUpdatingActors;

public:
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
};

