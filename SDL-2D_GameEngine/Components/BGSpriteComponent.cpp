#include "BGSpriteComponent.h"
#include "../Actor.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Texture.h"

BGSpriteComponent::BGSpriteComponent(class Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder), mScrollSpeed(0.0f)
{
}

void BGSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	for (auto& bg : mBGTextures)
	{
		// Update the x offset
		bg.mOffset.x += mScrollSpeed * deltaTime;
		/* If this is completely off the screen, reset offset to the right of the last bg texture */
		if (bg.mOffset.x < -mScreenSize.x)
		{
			bg.mOffset.x = (mBGTextures.size() - 1) * mScreenSize.x - 1;
		}
	}
}

void BGSpriteComponent::Draw(Shader* shader)
{
	/* Draw each background texture */
	for (auto& bg : mBGTextures)
	{
		if (bg.mTexture)
		{
			// Scale the quad by the width/height of texture
			Matrix4 scaleMat = Matrix4::CreateScale(static_cast<float>(bg.mOffset.x), static_cast<float>(bg.mOffset.y), 1.0f);
			Matrix4 world = scaleMat * mOwner->GetWorldTransform();

			// Set world transform
			shader->SetMatrixUniform("uWorldTransform", world);
			bg.mTexture->SetActive();

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		}
	}
}

void BGSpriteComponent::SetBGTextures(const std::vector<Texture*>& textures)
{
	int count = 0;
	for (auto tex : textures)
	{
		BGTexture temp;
		temp.mTexture = tex;
		// Each texture is screen width in offset
		temp.mOffset.x = tex->GetWidth();
		temp.mOffset.y = tex->GetHeight();
		mBGTextures.emplace_back(temp);
		count++;
	}
}
