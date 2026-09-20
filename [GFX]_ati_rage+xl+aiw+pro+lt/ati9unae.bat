@echo off
@Echo **** ATI UnInstaller
rundll32 %windir%\SYSTEM\atiiiexx.dll,_InfEngUnInstallINFFile_RunDLL@16 -force_restart -flags:0x2010001 -inf:%windir%\SYSTEM\ATii9xAB.INF %1
