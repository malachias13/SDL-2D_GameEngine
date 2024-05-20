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

protected:
	// Helper functions
	virtual void ProcessInput();
	virtual void UpdateGame();
	virtual void GenerateOutput();
	virtual void CreateSpriteVerts();
	virtual bool LoadShaders();
	virtual void BeginPlay();
	virtual void EndPlay();

protected:
	// Window create by SDL
	SDL_Window* mWindow;
	SDL_GLContext mContext;

	// Game should continue to run
	bool mIsRunning;
	bool mIsFullscreen = true;

	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// Window size
	int mWindowSize[2] = { 1080,720 };

	Uint32 mTicksCount;
	float mDeltaTime;
	int flags = 0;

protected:
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;
	class VertexArray* mSpriteVerts;
	class Shader* mSpriteShader;
	
	bool mUpdatingActors;

private:

	void FullScreenToggle();

public:
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	SDL_Texture* GetTexture(const std::string& fileName);

	// Getters
	void GetWindowSize(int* x, int* y) { *x = mWindowSize[0]; *y = mWindowSize[1]; }
	float DeltaTime() const {return mDeltaTime; }
};

