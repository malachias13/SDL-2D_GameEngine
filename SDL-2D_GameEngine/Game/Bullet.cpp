#include "Bullet.h"
#include "../Components/SpriteComponent.h"
#include "../Components/MoveComponent.h"
#include "../Components/CircleComponent.h"
#include "../Game.h"
#include "Stars.h"


Bullet::Bullet(Game* game) : Actor(game)
	,mDeathTimer(1.0f)
{
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/bullet.png"));

	// Set a forward speed.
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(800.0f);

	// Create circle component for collsion
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);
}

void Bullet::UpdateActor(float deltaTime)
{
	// Bullet Timer.
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		for (auto s : GetGame()->GetStars())
		{
			if (Intersect(*s->GetCircle(), *mCircle))
			{
				SetState(EDead);
				s->SetState(EDead);
				break;
			}
		}
	}
}
