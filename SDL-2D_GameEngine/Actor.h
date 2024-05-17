#pragma once

#include "GameMath.h"
#include <vector>

class Game;
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

	Actor(Game* game);
	virtual ~Actor();


	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);

	virtual void UpdateActor(float deltaTime);

	// Getters/Setters
	State GetState() { return mState; }
	Vector2 GetPosition() { return mPosition; }
	float GetScale() { return mScale; }
	float GetRotation() { return mRotation; }
	Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }
	
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	void SetRotation(float rotation) { mRotation = rotation; }

	Game* GetGame() { return mGame; }
	
	void ProcessInput(const uint8_t* keyState, float deltaTime);
	// Any actor-specific input code (overridable)
	virtual void ActorInput(const uint8_t* keyState, float deltaTime);

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
	Game* mGame;

	
};

