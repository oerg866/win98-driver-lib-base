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

ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Clock Driver update has completed.                       �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
goto END

:FILE1N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find \OS2\BOOT\CLOCK01.SYS, check usage           �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:FILE2N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find \OS2\BOOT\CLOCK02.SYS, check usage           �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:FILE3N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find <default drive>:\CLOCK01.SYS, check usage    �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:FILE4N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find <default drive>:\CLOCK02.SYS, check usage    �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:FILE5N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � UPDTCLK has already been run                             �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO END

:FILE6N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � UPDTCLK has already been run                             �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO END

:USAGE
ECHO .
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
ECHO �  Usage: UPDTCLK TARGETDRIVE:                                      �
ECHO �                                                                   �
ECHO � Examples: UPDTINST C:  updates hard disk partition C:             �
ECHO �              or                                                   �
ECHO �           UPDTINST D:  updates hard disk partition D:             �
ECHO �                                                                   �
ECHO 쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
ECHO � Your current directory must contain this BAT/CMD file and all the �
ECHO � new files to install.                                             �
ECHO �                                                                   �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
GOTO END

:END
