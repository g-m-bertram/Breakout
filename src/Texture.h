#ifndef TEXTURE_H
#define TEXTURE_H

#include"core.h"

class Texture2D
{
public:
	unsigned int ID;
	unsigned int Width, Height;
	unsigned int Internal_Format;
	unsigned int Image_Format;
	unsigned int Wrap_S, Wrap_T;
	unsigned int Filter_Min, Filter_Max;

	Texture2D();
	// generates texture from image data
	void Generate(unsigned int width, unsigned int height, unsigned char* data);
	// binds texture as current active GL_TEXTURE_2D texture object
	void Bind() const;
};

#endif // !TEXTURE_H