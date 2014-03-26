@echo off
cls
set include=%include%;R:\STK\ogfview\105_SRC\include
set lib=%lib%;R:\STK\ogfview\105_SRC\include
set PREFAST_ROOT=F:\NT52DDK\bin\x86\prefast
set PATH=%PREFAST_ROOT%\scripts;%PATH%

echo *** making ***
prefast cl /DUSE_V2 /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
prefast view
del *.obj
exit
cls
prefast cl /DSGI_GL /nologo /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /MD /c /Isrc src\*.c*
prefast view
del *.obj
