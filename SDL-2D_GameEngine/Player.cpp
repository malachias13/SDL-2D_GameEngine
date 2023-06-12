#include "Player.h"
#include "Deck.h"

Player::Player(int deckSize, class Game* game):Actor(game)
{
	mDeck = new Deck(deckSize, this);

}
