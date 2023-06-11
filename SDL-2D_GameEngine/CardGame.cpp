#include "CardGame.h"


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
	
	card = new Card(Ranks::HEART, Suits::QUEEN, this);
	card->SetPosition(Vector2(100, 100));
	card->SetScale(0.2f);
}
