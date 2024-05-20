#pragma once
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string& filename);
	void Unload();
	void SetActive();

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

private:

	// OpenGL ID of this texture
	unsigned int mTextureID;

	int mWidth;
	int mHeight;

};

