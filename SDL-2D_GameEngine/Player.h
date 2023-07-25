#pragma once
#include "Actor.h"

class Deck;

class Player : public Actor
{
public:
	Player(int deckSize, class Game* game);
	void AddPoints(int _point) { mPoints += _point; }

private:
	Deck* mDeck;
	int mPoints;

public:
	Deck* GetDeck() { return mDeck; }
	int GetPoints() const { return mPoints; }
};

