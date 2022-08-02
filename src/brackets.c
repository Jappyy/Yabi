#include "../include/brackets.h"

void check_brackets(char* buf)
{
   int counter = 0;

   for (size_t i = 0; buf[i] != '\0'; i++)
   {
      if (buf[i] == '[') 
            counter++;
        
      else if (buf[i] == ']') 
         counter--;   

      if (counter < 0)
            print_message(UNMATCHED_BRACKETS_ERROR, NULL);
   }
   
   if (counter != 0)
      print_message(UNMATCHED_BRACKETS_ERROR, NULL);
}

size_t closed_bracket(char* buf, size_t index)
{
   size_t res = index;
   size_t counter = 1;

   while (counter)
   {
      char c = buf[++res];
      if (c == '[') 
            ++counter;
        
      else if (c == ']') 
         --counter;   
   }
    return res;
}

size_t open_bracket(char* buf, size_t index)
{
   size_t res = index;
   size_t counter = 1;

   while (counter)
   {
      char c = buf[--res];
      if (c == ']') 
            ++counter;
        
      else if (c == '[') 
         --counter;   
   }
    return res;
}
