#pragma once
#include "SpriteComponent.h"
#include <vector>
#include "../GameMath.h"


class BGSpriteComponent : public SpriteComponent
{
public:
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

	/* Set the texture used for the background */
	void SetBGTextures(const std::vector<SDL_Texture*>& textures);
	/* Get/Set screen size and scroll speed */
	void SetScreenSize(const Vector2& size) { mScreenSize = size; }
	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	float GetScrollSpeed() const { return mScrollSpeed; }
private:
	// Struct to encapsulate each bg image and its offset
	struct BGTexture
	{
		SDL_Texture* mTexture;
		Vector2 mOffset;
	};
	std::vector<BGTexture> mBGTextures;
	Vector2 mScreenSize;
	float mScrollSpeed;
};

