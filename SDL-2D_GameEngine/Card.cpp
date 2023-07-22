#include "Card.h"
#include "SpriteComponent.h"
#include "BoxCollsion2DComponent.h"
#include "CardGame.h"
#include <functional>

Card::Card(class Game* game):Actor(game)
{
	mCardImage = new SpriteComponent(this);

	//SDL_Texture* box = SDL_CreateTexture(game->GetRenderer(),
	//	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 150);

	mFront = game->GetTexture("Assets/PNG-cards/7_of_hearts.png");
	mCardImage->SetTexture(mFront);

}

Card::Card(Ranks rank, Suits suit, Game* game) 
	:Actor(game),
	mSuit(suit),
	mRank(rank)
{
	mCardImage = new SpriteComponent(this, 4);
	boxCollsion = new BoxCollsion2DComponent(this, Vector2(500, 720));
	boxCollsion->bHiddenInGame = false;
	boxCollsion->onClicked = std::bind(&Card::Click, this);

	

	CardGame* cardGame = static_cast<CardGame*>(game);

	if (cardGame) {
		mFront = game->GetTexture(cardGame->GetCardImagPath(mRank, mSuit));
		mBack = game->GetTexture("Assets/PNG-cards/Card_back.png");
		mCardImage->SetTexture(mFront);
	}

	SetScale(0.2f);

}

void Card::flipCard()
{
	if (bisFacingUp) {
		bisFacingUp = false;

		mCardImage->SetTexture(mBack);

	}
	else {
		bisFacingUp = true;
		mCardImage->SetTexture(mFront);
	}
}

void Card::Click()
{
	std::string rank = RankToString();
	std::string suit = SuitsToString();

	SDL_Log("Clicked card class %s of %s", suit.c_str(), rank.c_str());
	flipCard();


}

const char* Card::RankToString()
{
	switch (mRank)
	{
	case Ranks::CLUB:
		return "club";
	case Ranks::DIAMONDS:
		return "diamonds";
	case Ranks::HEART:
		return "heart";
	case Ranks::SPADES:
		return "spades";
	}
}

const char* Card::SuitsToString()
{
	switch (mSuit)
	{
	case Suits::ACE:
		return "ace";
	case Suits::TWO:
		return "two";
	case Suits::THREE:
		return "three";
	case Suits::FOUR:
		return "four";
	case Suits::FIVE:
		return "five";
	case Suits::SIX:
		return "six";
	case Suits::SEVEN:
		return "seven";
	case Suits::EIGHT:
		return "eight";
	case Suits::NINE:
		return "nine";
	case Suits::TEN:
		return "ten";
	case Suits::JACK:
		return "jack";
	case Suits::QUEEN:
		return "queen";
	case Suits::KING:
		return "king";
	}
}
