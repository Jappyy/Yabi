#include "../include/compiler.h"

BF_token* parse_params(char* string)
{
   int offset = 0, increment = 0;

   BF_token* new;
   if ((new = malloc (sizeof(BF_token))) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   for (size_t i = 0; i < strlen(string); i++)
   {
      switch (string[i])
      {
         case '>':
            ++offset;
            break;

         case '<':
            --offset;
            break;

         case '+':
            ++increment;
            break;
         case '-':
            --increment;
            break;
      }
   }

   new->increment = increment;
   new->offset = offset;
   
   return new;
}


Token* new_token(Type type, ...)
{
   va_list args;
   va_start(args, type);

   Token* new = NULL;
   if((new = malloc(sizeof(Token))) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   new->type = type;
   new->next = NULL;

   switch (type)
   {
      case _move_ptr: 
      case _input:
      case _output:
      case _const_output:
      case _set_val:
         new->as.value = va_arg(args, int);  
      break;

      case _loop:
         new->as.loop = NULL;
      break;

      case _token:
         new->as.token = va_arg(args, BF_token*);
      break;
   }

   va_end(args);
   return new;
}

