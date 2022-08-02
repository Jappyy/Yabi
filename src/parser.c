#include "../include/compiler.h"



Token* parse(char* buf)
{
   char * pattern = "([><]*[\\+\\-]*|\\[|\\.|,)";
   regex_t preg;

   if (regcomp(&preg, pattern, REG_EXTENDED))
      print_message(FUNCTION_FAILURE_ERROR, "regcomp()");

   Token* program = internal_parser(buf, strlen(buf), buf, preg);
   return program;
}



Token* internal_parser(char* ptr,int len, char* buf, regex_t preg)
{     
   Token* new = NULL;

   regmatch_t pmatch[2];

   if(regexec(&preg, buf, 2, pmatch, 0) != 0)
      print_message(FUNCTION_FAILURE_ERROR, "regexec()");
   
   size_t offset = (size_t) pmatch[0].rm_eo;

   if (!offset)
      return  new_token(_end_loop);

  char* copy = NULL;

   if((copy = malloc (offset + 1)) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   strncpy(copy, buf, offset);
   copy[offset] = '\0';


   if (*copy =='[')
   {
      size_t loop_len = closed_bracket(buf, 0);
      buf[loop_len] = '\0';

      new = new_token(_loop);

      new->as.loop = internal_parser(ptr, len, buf+1, preg);

      new->next = internal_parser(ptr, len, buf+loop_len+1, preg);

      return new;
   }

   if (*copy == ',')
      new = new_token(_input);

   if (*copy == '.')
      new = new_token(_output);

   else
   {
      BF_token* params = parse_params(copy);
      new = new_token(_token, params);
   }


   buf += offset;

   new->next = internal_parser(ptr, len, buf, preg);
   return new;
}

