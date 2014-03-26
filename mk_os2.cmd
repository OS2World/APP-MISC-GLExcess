@echo off
cls
del ogf*.exe
SET WATCOM=G:\WATCOM
SET PATH=%WATCOM%\BINNT;%WATCOM%\BINW;%PATH%
SET INCLUDE=%WATCOM%\H;%WATCOM%\H\OS2;%ZINCLUDE%
SET LIB=%WATCOM%\lib386\OS2;%WATCOM%\lib386;.;%ZLIB%
SET INCLUDE=%WATCOM%\samples\os2\os2c\openil\include;%INCLUDE%
SET EDPATH=%WATCOM%\EDDAT
cls
cd src
wcl386 -k2m -dUSE_GL10 -dUSE_OS2 -cc++ -zq -w1 -3r -bt=os2v2_pm -bw -onatx -d0 -zp1 -bcl=os2v2_pm glxsglut.cpp scene01.cpp scene02.cpp scene03.cpp scene04.cpp scene05.cpp scene06.cpp scene07.cpp scene08.cpp scene09.cpp scene10.cpp scene11.cpp scene12.cpp Texture.cpp utils.cpp ..\lib10\opengl.lib ..\lib10\glut.lib
move glxsglut.exe ..\glex_os2_gl10.exe 
del *.obj
del *.err
cd ..

cd src
wcl386 -k2m -dUSE_OS2 -cc++ -zq -w1 -3r -bt=os2v2_pm -bw -onatx -d0 -zp1 -bcl=os2v2_pm glxsglut.cpp scene01.cpp scene02.cpp scene03.cpp scene04.cpp scene05.cpp scene06.cpp scene07.cpp scene08.cpp scene09.cpp scene10.cpp scene11.cpp scene12.cpp Texture.cpp utils.cpp ..\lib11\opengl.lib ..\lib11\glut.lib
move glxsglut.exe ..\glex_os2_gl11.exe 
del *.obj
del *.err
cd ..
