#pragma once
#include "Component.h"
#include <vector>
class Deck : public Component
{
public:
	Deck(int size, class Actor* owner, int updateOrder = 100);

private:
	std::vector<class Card*> mPlayingCards;
	int mDeckSize;

public:
	std::vector<Card*> GetPlayingCards() { return mPlayingCards; }
	int GetMaxDeckSize() { return mDeckSize; }

public:
	bool AddCard(Card* newCard);
	bool RemoveCard(Card* card);
};

