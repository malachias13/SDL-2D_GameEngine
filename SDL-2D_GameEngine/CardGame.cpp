#include "CardGame.h"

void CardGame::LoadData()
{
	card = new Card(this);
	card->SetPosition(Vector2(100, 100));
	card->SetScale(0.2f);
}
