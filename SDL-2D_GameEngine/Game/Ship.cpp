#include "Ship.h"
#include "../Components/SpriteComponent.h"
#include "../Components/InputComponent.h"
#include "../Game.h"

Ship::Ship(Game* game): Actor(game)
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

}
