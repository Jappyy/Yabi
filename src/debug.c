#include "../include/interpreter.h"


debug_controls internal_debug_input()
{
   int c = 0;

  #ifdef _WIN32
   
   c = getch();

   if (c == ESC)
      exit(1);

   if(c == 0)
   {
      c = getch(); 

      switch (c)
      {
         case 'H':
         return up_arrow_key;

         case 'P':
         return down_arrow_key;

         case 'K':
         return left_arrow_key; 

         case 'M':
         return right_arrow_key;

      }
   }


   #elif defined __linux__

   c = wgetch(stdscr);

   switch (c)
   {
      case ESC:
         exit(1);

      case KEY_UP:
         return up_arrow_key;

      case KEY_DOWN:
         return down_arrow_key;

      case KEY_LEFT:
         return left_arrow_key;

      case KEY_RIGHT:
         return right_arrow_key;
   }






/*
   if(c == ESC)
   {
      c = getch(); 

      if(c == '[')
      {
         c = getch();

         switch (c)
         {
            case 'A':
            return up_arrow_key;

            case 'B':
            return down_arrow_key;

            case 'D':
            return left_arrow_key;

            case 'C':
            return right_arrow_key;

         }
      }

      else
         exit(1);
   }*/

   #endif

   return none;
}

debug_controls debug_input()
{
   debug_controls a = internal_debug_input();

  if (a == down_arrow_key)
   {
      clock_t time = clock();

      #ifdef _WIN32
      
      while (clock() < time + 200)
            if (kbhit())
               if(internal_debug_input() == down_arrow_key)
                  return skip;

      #elif defined __linux__
      timeout(200);
      if( internal_debug_input() == down_arrow_key)
         return skip;
      
      #endif 
   } 

   return a;
}





void logger(FILE* fp, int counter, char instruction, int cell_pos, int cell_val)
{
   print(fp, "current intruction: %d\t '%c'\tcell n. %4d\tvalue: %3d\n",counter, instruction, cell_pos, cell_val);
}



void print_cells(FILE* fp, unsigned char cells[], unsigned char* ptr, int offset)
{ 
   int index = 10 * ((ptr - cells) / 10);

   print(fp, "(cells %d - %d)\t\t", (index + offset), (index + offset + 10));

   for (size_t i = 0; i < 10; i++)  
      print(fp, (&cells[index + i + offset] == ptr ) ? "[%d]\t" : "%d\t", cells[index + i + offset]);
   print(fp,"\n");
}


bool debug_exec(FILE* fp, unsigned char cells[], unsigned char* ptr)
{
   static int offset = 0;

   while (1)
   {
      debug_controls command = debug_input();

      switch (command)
      {
         case up_arrow_key:
            print_cells(fp, cells, ptr, offset);
            break;

         case  right_arrow_key:
            if (offset < (CELLS_NUM/2))
               offset += 10;
            print_cells(fp, cells, ptr, offset);
         break;

         case  left_arrow_key:
            if (offset > -(CELLS_NUM/2))
               offset -= 10;
            print_cells(fp, cells, ptr, offset);
         break;

         case down_arrow_key:
            return false;

         case skip:
            print(stdout, "SKIP\n");
            return true;
         
         case none:
         break;
      }
   }
}