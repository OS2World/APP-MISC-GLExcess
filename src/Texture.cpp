/*
GLExcess v1.0 Demo
Copyright (C) 2001-2003 Paolo Martella
                                                                                                                                                                    
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
                                                                                                                                                                    
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#include "Texture.h"

#ifdef USE_OS2
#define CALLBACK __syscall
#ifdef __IBMCPP__
#ifndef USE_MESA
#define GLUTCALL _System
#else
#define GLUTCALL _Optlink
#endif
#else
#define GLUTCALL APIENTRY
#endif
#else
#define GLUTCALL /* */
#endif

#ifdef USE_GL10
char * rawdata[125];
GLuint wcoord[125];
GLuint hcoord[125];
GLuint btID = 0;
#endif

#ifndef USE_GL10
Texture::Texture() {tID=0;}
#else
Texture::Texture() {tID=btID; btID++;}
#endif
Texture::~Texture(){Kill();}
int Texture::Create(char* FileName)
{
#ifndef USE_GL10
	Kill();
	glGenTextures(1, &tID);
#endif
	tID++; // Use an offset of +1 to differentiate from non-initialized state.
#ifndef USE_GL10
	glBindTexture(GL_TEXTURE_2D, tID-1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#ifdef USE_MIPMAP
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
#else
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
#endif
#endif
	return true;
}

void Texture::Kill()
{
	if(tID)
	{
		tID--;
#ifndef USE_GL10
	glDeleteTextures(1, &tID);
	tID=0;
#else
	delete [] rawdata[tID];
	btID--;
#endif
	}
}
GLuint pow2(GLuint exp)
{
	GLuint result=1;
	if (!exp) return result;
	for (GLuint a=0; a<exp; a++)
	{
		result*=2;
	}
	return result;
}
void Texture::Use()
{
#ifndef USE_GL10
	glBindTexture(GL_TEXTURE_2D,tID-1);
#else
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#ifdef USE_MIPMAP
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
#else
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
#endif
#ifdef USE_MIPMAP
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,wcoord[tID-1],hcoord[tID-1],GL_RGB,GL_UNSIGNED_BYTE,rawdata[tID-1]);
#else
	glTexImage2D(GL_TEXTURE_2D,0,3,wcoord[tID-1],hcoord[tID-1],0,GL_RGB,GL_UNSIGNED_BYTE,
		rawdata[tID-1]);
#endif
#endif
}

int Texture::Load(char* Opaque)
{
	if(Opaque==0) return false;
	if (!Create(Opaque)) return false;
#ifndef USE_GL10
	char * rgbdata;
	GLuint w,h;
#endif
	FILE * fhandle=NULL;
	fhandle=fopen(Opaque,"rb");
	if (!fhandle) return false;
	char ww,hh;
	if (fread(&ww,sizeof(char),1,fhandle) != sizeof(char)) return false;
#ifndef USE_GL10
	w=pow2(ww-48);
#else
	wcoord[tID-1]=pow2(ww-48);
#endif
	if (fread(&hh,sizeof(char),1,fhandle) != sizeof(char)) return false;
#ifndef USE_GL10
	h=pow2(hh-48);
#else
	hcoord[tID-1]=pow2(hh-48);
#endif
#ifndef USE_GL10
	GLuint size=w*h*3;
	rgbdata=new char[size];
	GLuint read=fread(rgbdata,sizeof(char),size,fhandle);
	if (read!=size) return false;
#else
	GLuint size=wcoord[tID-1]*hcoord[tID-1]*3;
	rawdata[tID-1]=new char[size];
	GLuint read=fread(rawdata[tID-1],sizeof(char),size,fhandle);
	if (read!=size) return false;
#endif
	fclose(fhandle);
#ifndef USE_GL10
#ifdef USE_MIPMAP
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,w,h,GL_RGB,GL_UNSIGNED_BYTE,rgbdata);
#else
	glTexImage2D(GL_TEXTURE_2D,0,3,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,
		rgbdata);
#endif
	delete [] rgbdata;
#endif
	return true;
}
