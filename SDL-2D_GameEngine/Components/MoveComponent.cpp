#include "MoveComponent.h"
#include "../GameMath.h"
#include "../Actor.h"
#include "../Game.h"

MoveComponent::MoveComponent(Actor* owner, int updateOrder)
	:Component(owner, updateOrder),
	mAngularSpeed(0.0f),
	mForwardSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}
	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

		int maxX, maxY;
		mOwner->GetGame()->GetWindowSize(&maxX, &maxY);
		// (Screen wrapping code only for stars)
		if (pos.x < 0.0f) { pos.x = maxX; }
		else if (pos.x > maxX) { pos.x = 2.0f; }

		if (pos.y < 0.0f) { pos.y = maxY; }
		else if (pos.y > maxY) { pos.y = 2.0f; }

		mOwner->SetPosition(pos);


	}
}
