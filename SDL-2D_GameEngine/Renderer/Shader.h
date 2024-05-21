#pragma once

#include <string>
#include "GL/glew.h"
#include "../GameMath.h"

class Shader
{
public:
	Shader();
	~Shader();

	// Load the vertex/fragment shaders with the given names
	bool Load(const std::string& vertName, const std::string& fragName);
	void Unload();
	// Set this as the active shader program
	void SetActive();
	void SetMatrixUniform(const char* name, const Matrix4& matrix);
	void setFloat(const char* name, float value) const;

private:
	// Compile the shader
	bool CompileShader(const std::string& filename, GLenum shaderType,
		GLuint& outShader);
	bool IsCompiled(GLuint shader);
	bool IsVaildProgram();

	// Store the shader object IDs
	GLuint mVertexShader;
	GLuint mFragShader;
	GLuint mShaderProgram;
};

