#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <unordered_map>
#include <string>
#include "Mouse.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	SDL_Texture* GetTexture(const std::string& fileName);
protected:
	// Helper functions
	virtual void ProcessInput();
	virtual void UpdateGame();
	virtual void GenerateOutput();
	virtual void LoadData();
	virtual void UnloadData();

protected:
	// Game should continue to run
	bool mIsRunning;
	Mouse* mCursor;

private:
	// Window create by SDL
	SDL_Window* mWindow;
	// renderer
	SDL_Renderer* mRenderer;

	int flags = 0;

	// for delta time
	Uint32 mTicksCount;

private:

	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;
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

public:
	// Getters
	SDL_Renderer* GetRenderer() { return mRenderer; }

};

