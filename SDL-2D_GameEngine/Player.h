#pragma once
#include "Actor.h"

class Deck;

class Player : public Actor
{
public:
	Player(int deckSize, class Game* game);

private:
	Deck* mDeck;

public:
	Deck* GetDeck() { return mDeck; }
};

