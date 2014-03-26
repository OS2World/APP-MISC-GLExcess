#ifndef TEXTURE_H
#define TEXTURE_H
#define MAX_TEXTURE_NAME_LENGTH 64

#ifndef true
#define true -1
#define false 0
#endif

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#ifdef SGI_GL
#define GLUT_DISABLE_ATEXIT_HACK
#include <SGIGL/gl.h>
#include <SGIGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class Texture
{
	public:
		Texture();
		~Texture();
		int Load(char* Opaque);
		void Kill();
		void Use();

	protected:
		int Create(char* FileName);
		char Name[MAX_TEXTURE_NAME_LENGTH];
		GLuint tID;
		GLuint Width, Height;
};
#endif

