#include "Shader.h"
#include "SDL2/SDL.h"
#include <fstream>
#include <sstream>

Shader::Shader() :
	mShaderProgram(0),
	mVertexShader(0),
	mFragShader(0)
{
}

Shader::~Shader()
{
}

bool Shader::Load(const std::string& vertName, const std::string& fragName)
{
	// Compile vertex and fragment shaders
	if (!CompileShader(vertName, GL_VERTEX_SHADER, mVertexShader) ||
		!CompileShader(fragName, GL_FRAGMENT_SHADER, mFragShader))
	{
		return false;
	}

	// Create a shader program that links vertex/frag shaders
	mShaderProgram = glCreateProgram();
	glAttachShader(mShaderProgram, mVertexShader);
	glAttachShader(mShaderProgram, mFragShader);
	glLinkProgram(mShaderProgram);

	// Verify that the program linkedd successfully
	if (!IsVaildProgram())
	{
		return false;
	}
	return true;
}

void Shader::Unload()
{
	glDeleteProgram(mShaderProgram);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragShader);

}

void Shader::SetActive()
{
	glUseProgram(mShaderProgram);
}

void Shader::SetMatrixUniform(const char* name, const Matrix4& matrix)
{
	// Find the uniform by this name
	GLuint loc = glGetUniformLocation(mShaderProgram, name);
	// Send the matrix data to the uniform
	glUniformMatrix4fv(loc, 1, GL_TRUE, matrix.GetAsFloatPtr());
}

void Shader::setFloat(const char* name, float value) const
{
	glUniform1f(glGetUniformLocation(mShaderProgram, name), value);
}

bool Shader::CompileShader(const std::string& filename, GLenum shaderType, GLuint& outShader)
{
	// Open file
	std::ifstream shaderFile(filename);
	if (shaderFile.is_open())
	{
		// Read all the text into a string
		std::stringstream sstream;
		sstream << shaderFile.rdbuf();
		std::string contents = sstream.str();
		const char* contentChar = contents.c_str();

		// Create a shader of the specified type
		outShader = glCreateShader(shaderType);
		// Set the soure characters and  try to compile
		glShaderSource(outShader, 1, &(contentChar), nullptr);
		glCompileShader(outShader);

		if (!IsCompiled(outShader))
		{
			SDL_Log("Failed to compile shader %s", filename.c_str());
			return false;
		}
	}
	else
	{
		SDL_Log("Shader file not found: %s", filename.c_str());
		return false;
	}

	return true;
}

bool Shader::IsCompiled(GLuint shader)
{
	GLint status;
	// Query the compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetShaderInfoLog(shader, 511, nullptr, buffer);
		return false;
	}
	return true;
}

bool Shader::IsVaildProgram()
{
	GLint status;
	glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetProgramInfoLog(mShaderProgram, 511, nullptr, buffer);
		return false;
	}

	return true;
}
