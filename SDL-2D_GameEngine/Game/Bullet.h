#pragma once
#include "../Actor.h"

class CircleComponent;
class Bullet : public Actor
{
public:
	Bullet(class Game* game);

	void UpdateActor(float deltaTime) override;

private:
	CircleComponent* mCircle;
	float mDeathTimer;


};

