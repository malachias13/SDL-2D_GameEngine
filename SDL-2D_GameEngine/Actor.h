#pragma once

#include "GameMath.h"
#include <vector>

class Actor
{
public:

	// track state of actor
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	virtual ~Actor();


	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);

	virtual void UpdateActor(float deltaTime);

	// Getters/Setters
	State GetState() { return mState; }
	Vector2 GetPosition() { return mPosition; }
	float GetScale() { return mScale; }
	float GetRotation() { return mRotation; }
	Game* GetGame() { return mGame; }

	// Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	State mState;

	// Transform
	Vector2 mPosition;
	float mScale;
	float mRotation; // Radians

	// Components held by actor
	std::vector<class Component*> mComponents;
	class Game* mGame;

	
};

