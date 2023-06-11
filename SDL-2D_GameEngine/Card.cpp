#include "Card.h"
#include "SpriteComponent.h"
#include "CardGame.h"

Card::Card(class Game* game):Actor(game)
{
	SpriteComponent* CardImage = new SpriteComponent(this);

	//SDL_Texture* box = SDL_CreateTexture(game->GetRenderer(),
	//	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 150);

	SDL_Texture* img = game->GetTexture("Assets/PNG-cards/7_of_hearts.png");
	CardImage->SetTexture(img);

}

Card::Card(Ranks rank, Suits suit, Game* game) 
	:Actor(game),
	mSuit(suit),
	mRank(rank)
{
	SpriteComponent* CardImage = new SpriteComponent(this);
	CardGame* cardGame = static_cast<CardGame*>(game);

	if (cardGame) {
		SDL_Texture* img = game->GetTexture(cardGame->GetCardImagPath(mRank, mSuit));
		CardImage->SetTexture(img);
	}

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
