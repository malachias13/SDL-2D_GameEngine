#pragma once
#include "SpriteComponent.h"
#include "GameMath.h"
#include "Actor.h"

class BoxCollsion2DComponent : public SpriteComponent
{
public:
	BoxCollsion2DComponent(Actor* owner, Vector2 boxSize);

	virtual void Draw(SDL_Renderer* renderer) override;
public:
	Vector2 size;
	bool bHiddenInGame = false;

};

