#pragma once
#include "Game.h"
#include "Card.h"

class Deck;
class Player;

class CardGame : public Game
{

private:
	Card* card;

public:

	std::string GetCardImagPath(const Ranks rank, const Suits suit);

	// Add or Remove card to select vector if it has been fliped over or not.
	void UpdateCardSelection(Card* selected);

private:
	Player* mPlayer1;
	std::vector<Card*> mSelectedCards;
	
protected:

	virtual void LoadData() override;
	virtual void ProcessInput() override;
	virtual void UpdateGame() override;

private:
	void FillDeck(Deck* deck);
	void DisplayDeck(Deck* deck, int x = 0, int y = 0);
	// Call hasClicked delegate on all clickable objects.
	void NotifyClicked(class Mouse* Cursor);
	void CompareSelectedCards();
	void HandleCorrectSelection();
	void HandleIncorrectSelection();

};

