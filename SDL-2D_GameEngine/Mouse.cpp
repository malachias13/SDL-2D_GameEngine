#include "Mouse.h"
#include "Game.h"

Mouse::Mouse(Game* game): Actor(game)
{
	cursor = new SpriteComponent(this);
	SDL_Texture* cursorTexture = game->GetTexture("Assets/cursor.png");
	cursor->SetTexture(cursorTexture);
	tip = { 0, 0, 1, 1 };
}
