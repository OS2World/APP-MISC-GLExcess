@echo off
del glex*.exe
set include=C:\0C\OGF_SRC\REL_ICC\INCLUDE;%include%
cls
echo GLEX,GLUT,WARPMESA,GL11
icc -Q+ -Ss -Oc -Gl+ /W1 /DUSE_MESA /DUSE_OS2 src\*.c* tcpip32.lib ..\AA\LIBWM5\Mesa_PM.LIB ..\AA\LIBWM5\MesaGL2.LIB ..\AA\LIBWM5\libGLU.LIB ..\AA\LIBWM5\libGlut.LIB /B"/NOLOGO /st:2000000 /exepack:2 /packd /optfunc /pm:pm"
rc -n ogf_os2.res texture.exe > nul
ren texture.exe glex_os2_mesa_11.exe
del *.obj
del *.err
cls
echo GLEX,GLUT,WARPMESA,GL10
icc -Q+ -Ss -Oc -Gl+ /W1 /DUSE_GL10 /DUSE_MESA /DUSE_OS2 src\*.c* tcpip32.lib ..\AA\LIBWM5\Mesa_PM.LIB ..\AA\LIBWM5\MesaGL2.LIB ..\AA\LIBWM5\libGLU.LIB ..\AA\LIBWM5\libGlut.LIB /B"/NOLOGO /st:2000000 /exepack:2 /packd /optfunc /pm:pm"
rc -n ogf_os2.res texture.exe > nul
ren texture.exe glex_os2_mesa_10.exe
del *.obj
del *.err

