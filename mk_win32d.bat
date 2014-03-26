@echo off
cls
set include=%include%;R:\STK\ogfview\105_SRC\include
set lib=%lib%;R:\STK\ogfview\105_SRC\include

echo *** making ***
cl /DUSE_V2 /nologo /W3 /GX /Od /ZI /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /debug /out:glex_ms_gl11d.exe *.obj
del *.obj
cls
cl /DUSE_GL10 /DUSE_V2 /nologo /W3 /GX /Od /ZI /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /debug /out:glex_ms_gl10d.exe *.obj
del *.obj
cls
cl /DSGI_GL /nologo /W3 /GX /Od /ZI /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /nologo /debug /out:glex_sgi_11d.exe opengl.lib glu.lib glut.lib *.obj
del *.obj
cls
cl /DSGI_GL /nologo /W3 /GX /Od /ZI /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
link /DUSE_GL10 /nologo /debug /out:glex_sgi_10d.exe opengl.lib glu.lib glut.lib *.obj
del *.obj