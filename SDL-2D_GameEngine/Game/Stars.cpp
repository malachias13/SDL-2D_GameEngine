#include "Stars.h"
#include "../GameMath.h"
#include "../Random.h"
#include "../Components/SpriteComponent.h"
#include "../Components/MoveComponent.h"
#include "../Components/CircleComponent.h"
#include "../Game.h"

Stars::Stars(Game* game)
	:Actor(game)
{
	// Initialize to random position.
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	// Create a sprite comp, and set texture
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Purple Star Icon 2.png"));

	// Create a move component, and set a forward speed;
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddStar(this);

}

Stars::~Stars()
{
	GetGame()->RemoveStar(this);
}
