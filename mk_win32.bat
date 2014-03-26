@echo off
cls
set include=%include%;R:\STK\ogfview\105_SRC\include
set lib=%lib%;R:\STK\ogfview\105_SRC\include

echo *** making ***
cl /DUSE_V2 /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /align:4096 /release /out:glex_ms_gl11.exe *.obj
del *.obj
cls
cl /DUSE_GL10 /DUSE_V2 /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /align:4096 /release /out:glex_ms_gl10.exe *.obj
del *.obj
cls
cl /DSGI_GL /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /align:4096 /release /out:glex_sgi_11.exe opengl.lib glu.lib glut.lib *.obj
del *.obj
cls
cl /DUSE_GL10 /DSGI_GL /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /align:4096 /release /out:glex_sgi_10.exe opengl.lib glu.lib glut.lib *.obj
del *.obj