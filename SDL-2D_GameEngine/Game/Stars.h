#pragma once
#include "../Actor.h"

class CircleComponent;
class Stars : public Actor
{
public:
	Stars(class Game* game);
	~Stars();

	CircleComponent* GetCircle() { return mCircle; }

private:
	CircleComponent* mCircle;

};

