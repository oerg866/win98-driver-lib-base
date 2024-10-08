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

ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Clock Driver restore has completed.                      �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
goto END

:FILE1N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find \OS2\BOOT\CLOCK01.WRP, check usage           �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:FILE2N
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
ECHO � Cannot find \OS2\BOOT\CLOCK02.WRP, check usage           �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
GOTO USAGE

:USAGE
ECHO .
ECHO 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
ECHO �  Usage: RSTRCLK TARGETDRIVE:                                      �
ECHO �                                                                   �
ECHO � Examples: RSTRCLK C:  updates hard disk partition C:              �
ECHO �              or                                                   �
ECHO �           RSTRCLK D:  updates hard disk partition D:              �
ECHO �                                                                   �
ECHO 쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
ECHO � Your current directory must contain this BAT/CMD file and all the �
ECHO � new files to install.                                             �
ECHO �                                                                   �
ECHO 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
GOTO END

:END
