#include "AsteroidGame.h"
#include "../Random.h"
#include "../Actor.h"
#include "Ship.h"
#include "Star.h"
#include "../Components/BGSpriteComponent.h"
#include "../Components/SpriteComponent.h"

void AsteroidGame::BeginPlay()
{
	Random::Init();

    Actor* background = new Actor(this);
    BGSpriteComponent* bgSpriteComp = new BGSpriteComponent(background);
    bgSpriteComp->SetScreenSize(Vector2(mWindowSize[0], mWindowSize[1]));
    std::vector<Texture*> bgtexs = {
        GetTexture("Assets/Space-Background.jpg")
    };
    bgSpriteComp->SetBGTextures(bgtexs);

    Ship* ship = new Ship(this);
    ship->SetRotation(Math::PiOver2);

    const int numStars = 20;
    for (int i = 0; i < numStars; i++)
    {
        new Star(this);
    }

}

void AsteroidGame::AddStar(Star* star)
{
	mStars.emplace_back(star);
}

void AsteroidGame::RemoveStar(Star* star)
{
	auto iter = std::find(mStars.begin(), mStars.end(), star);
	if (iter != mStars.end())
	{
		mStars.erase(iter);
	}
}
