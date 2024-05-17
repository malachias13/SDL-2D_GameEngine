#pragma once
#include "../Actor.h"

class Ship : public Actor
{
public:
	Ship(Game* game);

	void UpdateActor(float deltaTime) override;
};

