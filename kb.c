#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef WIN32
   #include <conio.h>
#elif defined __linux__
   #include "include/getch.h"
#endif


void prova();

int main(int argc, char** argv)
{
   while(1)
   prova();
   
}

void prova()
{
   while(clock() < time + 1000)
   {
      if(_kbhit())
      {}
   }
}

