#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include"core.h"

#include"Texture.h"
#include"Shader.h"

class ResourceManager
{
public:
	// storage
	static std::map<std::string, Shader>	Shaders;
	static std::map<std::string, Texture2D> Textures;
	// loads and generates a shader program from file
	static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
	// retrieves a stored shader
	static Shader GetShader(std::string name);
	// loads and generates a texture from file
	static Texture2D LoadTexture(const char* file, bool alpha, std::string name);
	// retrieves a stored texture
	static Texture2D& GetTexture(std::string name);
	// deallocates all loaded resources
	static void Clear();

private:
	// private constructor, no resource manager objects
	ResourceManager() {}
	// loads and generates a shader from file
	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = NULL);
	// loads a single texture from file
	static Texture2D loadTextureFromFile(const char* file, bool alpha);
};


#endif // !RESOURCE_MANAGER_H