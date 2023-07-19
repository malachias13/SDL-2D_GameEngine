#pragma once
#include "Actor.h"
#include "SpriteComponent.h"

class Mouse : public Actor
{
public:
	Mouse(class Game* game);

public:
	SpriteComponent* cursor;
	SDL_Rect tip;

};

