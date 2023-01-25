@echo off
if .%1. == .. GOTO USAGE
IF NOT EXIST UPDTCLK.BAT GOTO USAGE

IF NOT EXIST %1\OS2\BOOT\CLOCK01.WRP GOTO FILE1N
IF NOT EXIST %1\OS2\BOOT\CLOCK02.WRP GOTO FILE2N

attrib -r %1\os2\boot\clock01.wrp
attrib -r %1\os2\boot\clock02.wrp

copy %1\OS2\BOOT\CLOCK01.wrp %1\OS2\BOOT\CLOCK01.sys
copy %1\OS2\BOOT\CLOCK02.wrp %1\OS2\BOOT\CLOCK02.sys

del %1\OS2\BOOT\CLOCK01.WRP
del %1\OS2\BOOT\CLOCK02.WRP

attrib +r %1\OS2\BOOT\CLOCK01.SYS

ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Clock Driver restore has completed.                      Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
goto END

:FILE1N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find \OS2\BOOT\CLOCK01.WRP, check usage           Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:FILE2N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find \OS2\BOOT\CLOCK02.WRP, check usage           Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:USAGE
ECHO .
ECHO зддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё  Usage: RSTRCLK TARGETDRIVE:                                      Ё
ECHO Ё                                                                   Ё
ECHO Ё Examples: RSTRCLK C:  updates hard disk partition C:              Ё
ECHO Ё              or                                                   Ё
ECHO Ё           RSTRCLK D:  updates hard disk partition D:              Ё
ECHO Ё                                                                   Ё
ECHO цддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд╢
ECHO Ё Your current directory must contain this BAT/CMD file and all the Ё
ECHO Ё new files to install.                                             Ё
ECHO Ё                                                                   Ё
ECHO юддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO END

:END
