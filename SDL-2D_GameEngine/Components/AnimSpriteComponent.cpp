#include "AnimSpriteComponent.h"
#include "Component.h"
#include "../GameMath.h"
#include "../Actor.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder) 
	:SpriteComponent(owner, drawOrder),
	mCurrentFrame(0.0f),
	mAnimFPS(24.0f)
{

}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	if (mAnimTextures.size() > 0) {
		// Update the current frame based on frame rate and delta time
		mCurrentFrame += mAnimFPS * deltaTime;

		// Wrap current frame if needed
		while (mCurrentFrame >= mAnimTextures.size()) {
			mCurrentFrame -= mAnimTextures.size();
		}
		// Set the current texture
		SetTexture(mAnimTextures[static_cast<int>(mCurrentFrame)]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0) {
		// Set the active texture to first frame
		mCurrentFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}
