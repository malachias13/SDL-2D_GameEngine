#pragma once

class Actor;
class Component
{
public:
	Component();
	Component(Actor* owner, int updateOrder = 100);

	virtual ~Component();
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const uint8_t* keyState){}
	int GetUpdateOrder() const { return mUpdateOrder; }

protected:
	// Owning actor
	Actor* mOwner;
	
	int mUpdateOrder;

};

