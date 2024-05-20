#include "Ship.h"
#include "../Components/SpriteComponent.h"
#include "../Components/InputComponent.h"
#include "../Game.h"
#include "Bullet.h"

Ship::Ship(Game* game): Actor(game),
	mBulletCooldown(0.5f)
{
	SpriteComponent* sc= new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));
	SetScale(3);

	InputComponent* inputComp = new InputComponent(this);

	inputComp->SetForwardKey(SDL_SCANCODE_W);
	inputComp->SetBackKey(SDL_SCANCODE_S);
	inputComp->SetClockwiseKey(SDL_SCANCODE_A);
	inputComp->SetCounterClockwiseKey(SDL_SCANCODE_D);

	inputComp->SetMaxForwardSpeed(300.0f);
	inputComp->SetMaxAngularSpeed(Math::TwoPi * 2);
}

void Ship::UpdateActor(float deltaTime)
{
	mBulletCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && mBulletCooldown <= 0.0f)
	{
		Bullet* bullet = new Bullet(GetGame());
		bullet->SetPosition(GetPosition());
		bullet->SetRotation(GetRotation());

		mBulletCooldown = 0.5f;
	}
}
