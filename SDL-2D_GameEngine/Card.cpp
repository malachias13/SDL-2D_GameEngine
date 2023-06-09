#include "Card.h"
#include "SpriteComponent.h"
#include "Game.h"

Card::Card(class Game* game):Actor(game)
{
	// Use smart pointers.
	SpriteComponent* CardImage = new SpriteComponent(this);

	SDL_Texture* box = SDL_CreateTexture(game->GetRenderer(),
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 150);

	SDL_Texture* img = game->GetTexture("Assets/PNG-cards/7_of_hearts.png");
	CardImage->SetTexture(img);

}
