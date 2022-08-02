#include "../include/interpreter.h"

void interpreter(command_line_args* args, char* buf, FILE* output)  
{
   unsigned char cells[CELLS_NUM] = {0};
   unsigned char* ptr = &cells[CELLS_NUM/2];
   char c;
   int d;
   bool skip = false;

   
   for (size_t i = 0; (c = buf[i]) != '\0'; i++)
   {
      switch (c)
      {
         case '>':
            ptr++;
         break;

         case '<':
            ptr--;
         break;
      
         case '+':
            (*ptr)++;
         break;

         case '-':
            (*ptr)--;
         break;

         case '.':
            if (!skip)
            {
               if (args->flags.debug)
                  print(stdout, "\noutput: '%c'\n\n", *ptr); 

               print(stdout, "%c", *ptr);
            }
         break;

         case ',':
            if (args->flags.debug)
               print(stdout, "insert input: ");
            
            *ptr = (unsigned char) getchar();

            if (args->flags.debug)
            {
               do d = getchar(); while(d != '\n');

               print(stdout, "\ninput: '%c'\n\n", *ptr); 
            }
         break;

         case '[':
            if (*ptr == 0)
               i = closed_bracket(buf, i);
         break;

         case ']':
            if (*ptr != 0)
               i = open_bracket(buf, i);
         break;

         case '!':
            if (args->flags.debug)
            {
               print(stdout, "breakpoint\n");
               skip = false;
            }
            break;
      }
      
      if (args->flags.debug)
      {
         if (args->output_filename)
         {
            logger (output, i, c, ptr-cells, *ptr);
            print_cells(output, cells, ptr, 0);
         }

         if (!skip)
         {
            logger (stdout, i, c, ptr-cells, *ptr);
            skip =  debug_exec(stdout, cells, ptr);
         }
      }
   }
}

