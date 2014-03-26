@echo off
set include=F:\SCITECH\examples\snap\graphics\gatestgl\makes;%include%
cls
dmake clean
dmake OPT=1 FULLSCREEN=1 USE_CAUSEWAY=1
del *.o *.obj *.map *.err *.exp *.lib *.res
