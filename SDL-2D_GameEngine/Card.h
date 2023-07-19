#pragma once
#include "Actor.h"
#include <string>

enum class Ranks {
	
	CLUB = 0,
	DIAMONDS,
	HEART,
	SPADES,
};

enum class Suits {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
};

class Card : public Actor
{
public:
	Card(class Game* game);
	Card(Ranks rank, Suits suit , class Game* game);

private:
	Ranks mRank;
	Suits mSuit;
public:
	class BoxCollsion2DComponent* boxCollsion;

private:
	void Click();

public:
	const char* RankToString();
	const char* SuitsToString();

	Ranks GetRank() const { return mRank; }
	Suits GetSuit() const { return mSuit; }
};

