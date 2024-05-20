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
		maxX /= 2;
		maxY /= 2;

		// (Screen wrapping code only for stars)
		if (pos.x < -maxX) { pos.x = maxX - 2; }
		else if (pos.x > maxX) { pos.x = -maxX; }

		if (pos.y < -maxY) { pos.y = maxY - 2; }
		else if (pos.y > maxY) { pos.y = -maxY; }

		mOwner->SetPosition(pos);
	}
}
