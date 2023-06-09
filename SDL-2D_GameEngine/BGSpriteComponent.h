#pragma once
#include "SpriteComponent.h"
#include "GameMath.h"
#include <vector>

class BGSpriteComponent : public SpriteComponent {

public:
	// Set draw order to default to lower (so it's in the background)

	BGSpriteComponent(class Actor* owner, int drawOrder = 10);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

	// Set the textures used for the background
	void SetBGTextures(const std::vector<SDL_Texture*>& textures);
	void SetScreenSize(const Vector2& size) { mScreenSize = size; }
	void SetScrollSpeed(const float scrollSpeed) { mScrollSpeed = scrollSpeed; }
	float GetScrollSpeed() const { return mScrollSpeed; }

private:
	struct BGTexture {
		SDL_Texture* mTexture;
		Vector2 mOffset;
	};

	std::vector<BGTexture> mBGTextures;
	Vector2 mScreenSize;
	float mScrollSpeed;

};

