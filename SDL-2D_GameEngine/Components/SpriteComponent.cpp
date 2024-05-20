#include "SpriteComponent.h"
#include "GL/glew.h"
#include "../Actor.h"
#include "../Game.h"
#include "../Renderer/Shader.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner),
	mTexture(nullptr),
	mDrawOrder(drawOrder),
	mTexWidth(0),
	mTexHeight(0)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

// deprecated sprite comp code.
void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture) {
		SDL_Rect r;
		// Scale the width and height by owner's scale
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());

		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

		SDL_RenderCopyEx(renderer, mTexture, nullptr, &r,
			-Math::ToDegrees(mOwner->GetRotation()), nullptr, SDL_FLIP_NONE);
	}
}

void SpriteComponent::Draw(Shader* shader)
{
	// Scale the quad by the width/height of texture
	Matrix4 scaleMat = Matrix4::CreateScale(static_cast<float>(24), static_cast<float>(24), 1.0f);
	Matrix4 world = scaleMat * mOwner->GetWorldTransform();

	// Set world transform
	shader->SetMatrixUniform("uWorldTransform", world);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;

	// Get width and height of texture
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);

}
