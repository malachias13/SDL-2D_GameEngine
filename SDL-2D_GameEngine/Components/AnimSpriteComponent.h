#pragma once
#include "SpriteComponent.h"
#include <vector>

#include "SDL2/SDL.h"

class Texture;

class AnimSpriteComponent : public SpriteComponent
{
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	// Update animation every frame (overriden from component)

	void Update(float deltaTime) override;
	void SetAnimTextures(const std::vector<Texture*>& textures);
	float GetAnimFPS()const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }

private:
	std::vector<Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrentFrame;
	// Animation frame frate
	float mAnimFPS;
};

