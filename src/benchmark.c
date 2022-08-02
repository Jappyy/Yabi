#include "../include/benchmark.h"

void benchmark()
{
   static clock_t tic;
   static clock_t toc;
   static bool timer_start = false;
   

   
   if(timer_start == false) 
   {
      timer_start = true;
      tic = clock();
      return;
   }

   if (timer_start == true)
   {
      toc = clock();
      print(stdout, "\n[INFO: The program took %f seconds]\n", (double)(toc - tic) / CLOCKS_PER_SEC);
      return;
   }   
}