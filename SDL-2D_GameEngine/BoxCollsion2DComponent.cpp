#include "BoxCollsion2DComponent.h"
#include "Actor.h"


BoxCollsion2DComponent::BoxCollsion2DComponent(Actor* owner, Vector2 boxSize):
	SpriteComponent(owner, 10)
{
	size = boxSize;
	bHiddenInGame = true;
}

void BoxCollsion2DComponent::Draw(SDL_Renderer* renderer)
{
	if (bHiddenInGame == true) { return; }

	SDL_Rect collsionBox;
	collsionBox.w = static_cast<int>(size.x * mOwner->GetScale());
	collsionBox.h = static_cast<int>(size.y * mOwner->GetScale());
	collsionBox.x = static_cast<int>(mOwner->GetPosition().x - collsionBox.w / 2);
	collsionBox.y = static_cast<int>(mOwner->GetPosition().y - collsionBox.h / 2);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(renderer, &collsionBox);
}
