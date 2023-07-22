#include "CardGame.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include "BoxCollsion2DComponent.h"
#include "SpriteComponent.h"

std::string CardGame::GetCardImagPath(const Ranks rank, const Suits suit)
{
	std::string path;
	switch (suit)
	{
	case Suits::ACE:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/ace_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/ace_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/ace_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/ace_of_spades.png";
			break;
		}
		break;
	case Suits::TWO:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/2_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/2_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/2_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/2_of_spades.png";
			break;
		}
		break;
	case Suits::THREE:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/3_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/3_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/3_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/3_of_spades.png";
			break;
		}
		break;
	case Suits::FOUR:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/4_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/4_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/4_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/4_of_spades.png";
			break;
		}
		break;
	case Suits::FIVE:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/5_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/5_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/5_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/5_of_spades.png";
			break;
		}
		break;
	case Suits::SIX:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/6_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/6_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/6_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/6_of_spades.png";
			break;
		}
		break;
	case Suits::SEVEN:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/7_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/7_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/7_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/7_of_spades.png";
			break;
		}
		break;
	case Suits::EIGHT:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/8_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/8_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/8_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/8_of_spades.png";
			break;
		}
		break;
	case Suits::NINE:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/9_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/9_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/9_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/9_of_spades.png";
			break;
		}
		break;
	case Suits::TEN:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/10_of_clubs.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/10_of_diamonds.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/10_of_hearts.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/10_of_spades.png";
			break;
		}
		break;
	case Suits::JACK:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/jack_of_clubs2.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/jack_of_diamonds2.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/jack_of_hearts2.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/jack_of_spades2.png";
			break;
		}
		break;
	case Suits::QUEEN:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/queen_of_clubs2.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/queen_of_diamonds2.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/queen_of_hearts2.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/queen_of_spades2.png";
			break;
		}
		break;
	case Suits::KING:
		switch (rank)
		{
		case Ranks::CLUB:
			path = "Assets/PNG-cards/king_of_clubs2.png";
			break;
		case Ranks::DIAMONDS:
			path = "Assets/PNG-cards/king_of_diamonds2.png";
			break;
		case Ranks::HEART:
			path = "Assets/PNG-cards/king_of_hearts2.png";
			break;
		case Ranks::SPADES:
			path = "Assets/PNG-cards/king_of_spades2.png";
			break;
		}
		break;
	}
	return path;
}

void CardGame::LoadData()
{
	
	//card = new Card(Ranks::HEART, Suits::QUEEN, this);
	//card->SetPosition(Vector2(100, 100));
	//card->SetScale(0.2f);

	mCursor = new Mouse(this);
	mPlayer1 = new Player(52, this);
	FillDeck(mPlayer1->GetDeck());
	DisplayDeck(mPlayer1->GetDeck(), 100, 100);

	SDL_ShowCursor(false);
}

void CardGame::ProcessInput()
{
	SDL_Event event;
	// While there are still events in the queue
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
			// click
		case SDL_MOUSEBUTTONUP:

			if (SDL_BUTTON_LEFT == event.button.button) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				SDL_Log("Clicked %i , %i", x, y);

				NotifyClicked(mCursor);
			}
		case SDL_KEYDOWN:

			if (SDLK_q == event.key.keysym.sym) {
			}
			break;
		}
	}
}

void CardGame::FillDeck(Deck* deck)
{
	for (int r = 0; r < 4; r++) {
		for (int s = 1; s < 14; s++) {

			Card* newCard = new Card((Ranks)r, (Suits)s, this);
			deck->AddCard(newCard);
		}
	}
}

void CardGame::DisplayDeck(Deck* deck, int x, int y)
{
	for (int i = 0; i < deck->GetPlayingCards().size(); ++i) {
		int xPos = x + ((i % 13) * 120);
		int yPos = y +((i / 13) * 150);
		deck->GetPlayingCards()[i]->SetPosition(Vector2((float)xPos, (float)yPos));
		
		// Remove this code this is just for testing!
		//deck->GetPlayingCards()[i]->boxCollsion->onClicked(this);
	}

}

void CardGame::NotifyClicked(Mouse* Cursor)
{
	for (int i = 0; i < GetAllSpritesComp().size(); i++) {
		// 2D boxCollsions component are the only class that handles clicks
		BoxCollsion2DComponent* Box2DComponent = reinterpret_cast<BoxCollsion2DComponent*>(GetAllSpritesComp()[i]);
		if (Box2DComponent) {
			Box2DComponent->hasClicked(Cursor);
		}
	}
}


