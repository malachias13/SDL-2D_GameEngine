#include "Deck.h"

Deck::Deck(int size, Actor* owner, int updateOrder):
	Component(owner, updateOrder)
{
	mDeckSize = size;
}

bool Deck::AddCard(Card* newCard)
{
	if (mPlayingCards.size() < mDeckSize) {
		mPlayingCards.push_back(newCard);
		return true;
	}
	return false;
}

bool Deck::RemoveCard(Card* card)
{
	for (auto iter = mPlayingCards.begin(); iter != mPlayingCards.end(); ++iter) {
		if (card == *iter) {
			mPlayingCards.erase(iter);
			return true;
		}
	}
	return false;
}
