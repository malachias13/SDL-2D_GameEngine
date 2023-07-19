#include "BoxCollsion2DComponent.h"
#include "Actor.h"
#include "Mouse.h"

BoxCollsion2DComponent::BoxCollsion2DComponent(Actor* owner, Vector2 boxSize):
	SpriteComponent(owner, 10)
{
	size = boxSize;
	bHiddenInGame = true;
}

void BoxCollsion2DComponent::Draw(SDL_Renderer* renderer)
{
	if (bHiddenInGame == true) { return; }


	m_collsionBox.w = static_cast<int>(size.x * mOwner->GetScale());
	m_collsionBox.h = static_cast<int>(size.y * mOwner->GetScale());
	m_collsionBox.x = static_cast<int>(mOwner->GetPosition().x - m_collsionBox.w / 2);
	m_collsionBox.y = static_cast<int>(mOwner->GetPosition().y - m_collsionBox.h / 2);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(renderer, &m_collsionBox);
}

bool BoxCollsion2DComponent::hasClicked(Mouse* cusor)
{
	if (SDL_HasIntersection(&(cusor->cursor->r), &m_collsionBox)) {
		SDL_Log("Card Click!!!!!");
		return true;
	}

	return false;
}
