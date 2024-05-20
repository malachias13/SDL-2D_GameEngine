#pragma once

#include "SDL2/SDL.h"
#include "Component.h"

class Shader;
class Texture;

class SpriteComponent : public Component
{
public:
	// (Lower draw order corresponds with further back)

	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(Shader* shader);
	virtual void SetTexture(Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
protected:
	Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;

};

