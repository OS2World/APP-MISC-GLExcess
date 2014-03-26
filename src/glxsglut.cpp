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

#ifdef USE_OS2
#define INCL_DOSPROCESS
#include <os2.h>
#include <sys\time.h>
#ifdef USE_MESA
#include <bsedos.h>
extern void APIENTRY OS2_WMesaInitHab(HAB proghab,int useDive);
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef SGI_GL
#define GLUT_DISABLE_ATEXIT_HACK
#include "sgigl\glut.h"
#else
#include "gl\glut.h"
#endif

//#include <GL/glut.h>
//#include <GL/glu.h>

#ifdef SGI_GL
#pragma message ( "OpenGL Renderer (SGI/MMX, Console, GLUT)" )
#else
#pragma message ( "OpenGL Renderer (Microsoft, Console, GLUT)" )
#endif
#ifndef USE_GL10
#pragma message ( "OpenGL version 1.1 [29 Mar 1997]" )
#else
#pragma message ( "OpenGL version 1.0 [1 July 1992]" )
#endif


#include "Texture.h"
#include "utils.h"
#include "scene01.h"
#include "scene02.h"
#include "scene03.h"
#include "scene04.h"
#include "scene05.h"
#include "scene06.h"
#include "scene07.h"
#include "scene08.h"
#include "scene09.h"
#include "scene10.h"
#include "scene11.h"
#include "scene12.h"

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

#ifdef USE_DOS
#define GLUTCALL /* */
#endif

static int loop=true;
static int timerset=false;
static GLfloat timing=0;
static GLfloat step=1;
static GLuint scene=1;

void GLUTCALL drawscene()
{
	switch (scene)
	{
		case 1:
			if (!z_DrawGLScene(timing)) {scene++; z_Clean(); timing=0;}
			break;
		case 2:
			if (!a_DrawGLScene(timing)) {scene++; a_Clean(); timing=0;}
			break;
		case 3:
			if (!b_DrawGLScene(timing)) {scene++; b_Clean(); timing=0;}
			break;
		case 4:
			if (!d_DrawGLScene()) {scene++; d_Clean(); timing=0;}
			break;
		case 5:
			if (!c_DrawGLScene(timing)) {scene++; c_Clean(); timing=0;}
			break;
		case 6:
			if (!e_DrawGLScene(timing)) {scene++; e_Clean(); timing=0;}
			break;
		case 7:
			if (!f_DrawGLScene(timing)) {scene++; f_Clean(); timing=0;}
			break;
		case 8:
			if (!g_DrawGLScene(timing)) {scene++; g_Clean(); timing=0;}
			break;
		case 9:
			if (!h_DrawGLScene(timing)) {scene++; h_Clean(); timing=0;}
			break;
		case 10:
			if (!i_DrawGLScene(timing)) {scene++; i_Clean(); timing=0;}
			break;
		case 11:
			if (!j_DrawGLScene(timing)) {scene++; j_Clean(); timing=0;}
			break;
		case 12:
			if (!k_DrawGLScene(timing)) {scene++; k_Clean(); timing=0;}
			break;
		case 13:
			if (loop) {scene=1; timing=0;}
			else exit(0);
			break;
	}
}
void GLUTCALL update(int dummy)
{
	timing+=3;
	timerset=false;
}
void GLUTCALL scenemanagement()
{
	timing+=step;
	drawscene();
	//if (!timerset) {glutTimerFunc(1,update,0);timerset=true;}
}
void GLUTCALL display(void)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(5);
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(-.5,-.5,0);
	glTexCoord2f(1,0);
	glVertex3f(.5,-.5,0);
	glTexCoord2f(1,1);
	glVertex3f(.5,.5,0);
	glTexCoord2f(0,1);
	glVertex3f(-.5,.5,0);
	glEnd();
	glColor4f(1,1,1,1);
	glutSwapBuffers();
}

void GLUTCALL keyboard(unsigned char key, int x1, int y)
{
	switch (key)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			switch (scene)
			{
				case 1:	z_Clean(); break;
				case 2: a_Clean(); break;
				case 3: b_Clean(); break;
				case 4: d_Clean(); break;
				case 5: c_Clean(); break;
				case 6: e_Clean(); break;
				case 7: f_Clean(); break;
				case 8: g_Clean(); break;
				case 9: h_Clean(); break;
				case 10: i_Clean(); break;
				case 11: j_Clean(); break;
				case 12: k_Clean(); break;
			}
			scene = (key - 47);timing=0;
			break;
		case ' ':
			switch (scene)
			{
				case 1:	z_Clean(); break;
				case 2: a_Clean(); break;
				case 3: b_Clean(); break;
				case 4: d_Clean(); break;
				case 5: c_Clean(); break;
				case 6: e_Clean(); break;
				case 7: f_Clean(); break;
				case 8: g_Clean(); break;
				case 9: h_Clean(); break;
				case 10: i_Clean(); break;
				case 11: j_Clean(); break;
				case 12: k_Clean(); break;
			}
			scene++;timing=0;
			break;

		case 'a':
			step+=1;
			break;

		case 'z':
			step-=1;
			if (step<-1) step=-1;
			break;

		case 27:
			exit(0);
			break;

		default:
			glutPostRedisplay();
			break;
	}
}

#ifdef USE_MESA
HAB mainhab = NULLHANDLE; /* PM anchor block handle */
HMQ mainhmq = NULLHANDLE; /* message queue handle */
HPS mainhpsCurrent;

int InitPM(int mode)
{
	if ( ( mainhab = WinInitialize( 0UL ) ) == NULLHANDLE )
		return 1;
	if ( ( mainhmq = WinCreateMsgQueue( mainhab, 32UL ) ) == NULLHANDLE )
		return 2;
//	if (WinMessageBox(HWND_DESKTOP,HWND_DESKTOP,"Use DIVE calls?","2D Acceleration",0L, MB_YESNO | MB_ICONQUESTION | MB_MOVEABLE) == MBID_YES)
//		OS2_WMesaInitHab(mainhab,1); else 
		OS2_WMesaInitHab(mainhab,0);
	
	return 0;
}
#endif

int main(int argc, char** argv)
{
#ifdef USE_V2
	int use_glutfullscreen = 0;
#endif
	int i;
	printf("argc=%d\n",argc);
	for (i=0; i<argc; i++) printf("argv[%d]:%s\n",i,argv[i]);
	int wparams[5]={0,400,300,16,60}; // 400 - min X, 60 - min HZ !!!
	for (i=0; ((i<argc-1)&&(i<5)); i++) wparams[i]=toint(argv[i+1]);

#ifdef USE_OS2
//	DosGetInfoBlocks(&tib, &pib); pib->pib_ultype = 3;
#ifdef USE_MESA
	if (InitPM(0)) return 1;
#endif
#endif

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

#ifdef USE_V2
	if (wparams[0])
	{
		printf ("Trying to use the glutEnterGameMode to obtain fullscreen (%s)\n", buildgamestring(wparams, argc));

		glutGameModeString(buildgamestring(wparams, argc));
		if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
		{
			use_glutfullscreen = 1;
			glutEnterGameMode();
		}
		else
		{
			printf("Game mode not available\n");
			printf("Using glutFullScreen instead, width and height might be different than requested\n");
			use_glutfullscreen = 1;
			glutFullScreen();
		}
	}
	if (!use_glutfullscreen)
	{
#endif
#ifdef USE_MESA
	glutInitWindowPosition(50, 50); 
#endif
#ifdef WIN32
	glutInitWindowPosition (0, 0);
#endif
	glutInitWindowSize (wparams[1], wparams[2]);
	glutCreateWindow("GLExcess");
#ifdef USE_V2
	} // if not f/s
#endif
	// glutPostRedisplay(); // what for ?

	glutKeyboardFunc(keyboard);
	glutDisplayFunc(scenemanagement);
	glutIdleFunc(scenemanagement);

	glutMainLoop();
	return 0;
}
