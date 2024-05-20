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
	void ComputeWorldTransform();

	virtual void UpdateActor(float deltaTime);


	// Getters/Setters
	const State GetState() const { return mState; }
	const Vector2& GetPosition() const { return mPosition; }
	float GetScale() const { return mScale; }
	float GetRotation() const { return mRotation; }
	Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }
	const Matrix4& GetWorldTransform() const { return mWorldTransform; }
	
	void SetPosition(const Vector2& pos) { mPosition = pos; mRecomputeWorldTransform = true; }
	void SetRotation(float rotation) { mRotation = rotation; mRecomputeWorldTransform = true; }
	void SetScale(float scale) { mScale = scale; mRecomputeWorldTransform = true; }
	void SetState(State _state) { mState = _state; }

	Game* GetGame() { return mGame; }
	
	void ProcessInput(const uint8_t* keyState);
	// Any actor-specific input code (overridable)
	virtual void ActorInput(const uint8_t* keyState);

	// Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	State mState;

	// Transform
	Matrix4 mWorldTransform;
	Vector2 mPosition;
	float mScale;
	float mRotation; // Radians

	bool mRecomputeWorldTransform;

	// Components held by actor
	std::vector<class Component*> mComponents;
	Game* mGame;

	
};

