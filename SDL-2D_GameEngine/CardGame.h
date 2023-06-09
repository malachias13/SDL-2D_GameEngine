#pragma once
#include "Game.h"
#include "Card.h"

class CardGame : public Game
{

private:
	Card* card;
protected:
	virtual void LoadData() override;
};

