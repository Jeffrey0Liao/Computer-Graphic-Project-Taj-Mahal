#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define GL_CLAMP_TO_EDGE 0x812F

#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma pack(1)
#define WORD unsigned short
#define DWORD unsigned int
#define LONG int
typedef struct tagBITMAPFILEHEADER
{
	WORD  bfType;
	DWORD bfSize;
	WORD  bfReserved1;
	WORD  bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER, * PBITMAPFILEHEADER;
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER;
#endif

#include <iostream>

using namespace std;

Texture::~Texture(void)
{
	GLuint t;
	// free up all the textures
	for (map<int, string>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		t = static_cast<GLuint>(it->first);
		glDeleteTextures(static_cast<GLsizei>(1), &t);
	}
}

// Loads a bitmap into texture memory
int Texture::GetTexture(string fileName)
{
	for (map<int, string>::iterator ii = textures.begin(); ii != textures.end(); ++ii)
	{
		if (ii->second == fileName)
		{
			return ii->first;
		}
	}

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	unsigned char* pixelBuffer;
	GLuint texObject;
	FILE* bitmapFile = fopen(fileName.c_str(), "r");

	// read in file header
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, bitmapFile);

	// Read in the pixel data
	int width, height, channels;

	// flip the png image up-side-down due to its format
	stbi_set_flip_vertically_on_load(true);
	// use stbi loader to read in image file
	pixelBuffer = stbi_load(fileName.c_str(), &width, &height, &channels, 0);

	// Enable texturing
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	// Generate a texture buffer
	glGenTextures(static_cast<GLsizei>(1), &texObject);

	// Upload texture data
	if (pixelBuffer)	// selector: if has three channel, then RGB format, if four, then RGBA format.
	{
		GLenum format;
		if (channels == 1)
			format = GL_RED;
		else if (channels == 3)
			format = GL_RGB;
		else if (channels == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, texObject);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixelBuffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); //suse GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		// Set texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		stbi_image_free(pixelBuffer);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << fileName << std::endl;
		stbi_image_free(pixelBuffer);
	}

	// insert texture into texture list
	textures.insert(textures.end(), pair<int, string>(static_cast<int>(texObject), fileName));

	// Delete old copy of pixel data
	fclose(bitmapFile);
	glDisable(GL_TEXTURE_2D);

	return static_cast<int>(texObject);
}