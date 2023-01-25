@echo off
if .%1. == .. GOTO USAGE
IF NOT EXIST UPDTCLK.BAT GOTO USAGE

IF NOT EXIST %1\OS2\BOOT\CLOCK01.SYS GOTO FILE1N
IF NOT EXIST %1\OS2\BOOT\CLOCK02.SYS GOTO FILE2N
IF NOT EXIST clock01.sys GOTO FILE3N
IF NOT EXIST clock02.sys GOTO FILE4N

IF EXIST %1\OS2\BOOT\CLOCK01.WRP GOTO FILE5N
IF EXIST %1\OS2\BOOT\CLOCK02.WRP GOTO FILE6N

copy %1\OS2\BOOT\CLOCK01.SYS %1\OS2\BOOT\CLOCK01.WRP
copy %1\OS2\BOOT\CLOCK02.SYS %1\OS2\BOOT\CLOCK02.WRP

attrib +r %1\OS2\BOOT\CLOCK01.WRP
attrib +r %1\OS2\BOOT\CLOCK02.WRP

attrib -r %1\os2\boot\clock01.sys
attrib -r %1\os2\boot\clock02.sys

copy clock01.sys %1\os2\boot\clock01.sys
copy clock02.sys %1\os2\boot\clock02.sys

ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Clock Driver update has completed.                       Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
goto END

:FILE1N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find \OS2\BOOT\CLOCK01.SYS, check usage           Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:FILE2N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find \OS2\BOOT\CLOCK02.SYS, check usage           Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:FILE3N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find <default drive>:\CLOCK01.SYS, check usage    Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:FILE4N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё Cannot find <default drive>:\CLOCK02.SYS, check usage    Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO USAGE

:FILE5N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё UPDTCLK has already been run                             Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO END

:FILE6N
ECHO здддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё UPDTCLK has already been run                             Ё
ECHO юдддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO END

:USAGE
ECHO .
ECHO зддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
ECHO Ё  Usage: UPDTCLK TARGETDRIVE:                                      Ё
ECHO Ё                                                                   Ё
ECHO Ё Examples: UPDTINST C:  updates hard disk partition C:             Ё
ECHO Ё              or                                                   Ё
ECHO Ё           UPDTINST D:  updates hard disk partition D:             Ё
ECHO Ё                                                                   Ё
ECHO цддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд╢
ECHO Ё Your current directory must contain this BAT/CMD file and all the Ё
ECHO Ё new files to install.                                             Ё
ECHO Ё                                                                   Ё
ECHO юддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
GOTO END

:END
