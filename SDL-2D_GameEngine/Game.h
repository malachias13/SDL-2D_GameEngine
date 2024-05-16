#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <string>
#include <unordered_map>

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
	SDL_Texture* GetTexture(const std::string& fileName);
	void BeginPlay();
	void EndPlay();

private:

	// Window create by SDL
	SDL_Window* mWindow;
	// renderer
	SDL_Renderer* mRenderer;
	// Game should continue to run
	bool mIsRunning;
	bool mIsFullscreen = true;

	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	int flags = 0;

	// Window size
	int mWindowSize[2] = { 1920,1080 };

	// for delta time
	Uint32 mTicksCount;

private:
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;
	
	bool mUpdatingActors;

private:

	void FullScreenToggle();

public:
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
};

