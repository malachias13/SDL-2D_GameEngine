#pragma once
#include "SpriteComponent.h"
#include "GameMath.h"
#include "Actor.h"
#include "Card.h"
#include <functional>

class BoxCollsion2DComponent : public SpriteComponent
{
public:
	BoxCollsion2DComponent(Actor* owner, Vector2 boxSize);

	virtual void Draw(SDL_Renderer* renderer) override;
private:
	SDL_Rect m_collsionBox;

public:
	Vector2 size;
	bool bHiddenInGame = false;

public:
	// Click function pointer;
	std::function<void(Actor)> onClicked;

	bool hasClicked(class Mouse* cusor);

};

