#pragma once
#include "Game.h"
#include "Card.h"


class CardGame : public Game
{

private:
	Card* card;

public:

	std::string GetCardImagPath(const Ranks rank, const Suits suit);
	
protected:

	virtual void LoadData() override;

};

