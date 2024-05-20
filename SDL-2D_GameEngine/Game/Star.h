#pragma once
#include "../Actor.h"

class CircleComponent;
class Star : public Actor
{
public:
	Star(class Game* game);
	~Star();

	CircleComponent* GetCircle() { return mCircle; }

private:
	CircleComponent* mCircle;

};

