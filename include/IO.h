#ifndef _IO_
#define _IO_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#ifdef _WIN32
   #include <conio.h>

#elif defined __linux__
   #include <curses.h>

   bool kbhit();
   void init();
   void restore_default();

#endif

   void print(FILE* fp, char* format, ...);

#endif