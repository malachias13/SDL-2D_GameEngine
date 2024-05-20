#pragma once
#include "../Game.h"

class Star;

class AsteroidGame : public Game
{
protected:

	void BeginPlay() override;

public:
	void AddStar(Star* star);
	void RemoveStar(Star* star);


public:
	std::vector<Star*>& GetStars() { return mStars; }

private:
	
	std::vector<Star*> mStars;

	
};

