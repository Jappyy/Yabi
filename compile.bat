@echo off

gcc ^
%~dp0src\args.c ^
%~dp0src\error.c ^
%~dp0src\info.c ^
%~dp0src\benchmark.c ^
%~dp0src\files.c ^
%~dp0src\brackets.c ^
%~dp0src\interpreter.c ^
%~dp0src\IO.c ^
%~dp0src\parser.c ^
%~dp0src\compiler.c ^
%~dp0src\main.c ^
%~dp0src\debug.c ^
%~dp0src\tokens.c ^
-o %~dp0bin\yabi.exe ^
-lregex -march=native -O3 -std=c11 

