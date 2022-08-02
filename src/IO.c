#include "../include/IO.h"

void print(FILE* fp, char* format, ...)
{
   va_list args;

   va_start(args, format);

   if (fp == stdout)
   {
      #ifdef _WIN32
         vprintf(format, args);

      #elif defined __linux__
      
         vwprintw(stdscr, format, args);
         refresh();
         
      #endif
   }

   else 
      vfprintf(fp, format, args);
   
}