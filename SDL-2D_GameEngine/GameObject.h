#pragma once
#include "Components/Component.h"
#include <unordered_set>

class GameObject
{
public:
	void AddComponent(Component* comp);
	void RemoveComponent(Component* comp);
private:
	std::unordered_set<Component*> mComponents;
};

