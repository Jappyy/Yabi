#include "../include/compiler.h"


void compile(command_line_args* args, char* buf, FILE* output)
{
   if (args->flags.optimize)
   {
      Token* program = parse(buf);
      print_prologue(args, output);
      //print_tokens(program, 0); debug
      compiler_output_01(args, output, program, 0);
   }
   
   else
      compiler_output_00(args, output, buf);
}



void print_tokens(Token* program, int depth)
{
   while(program)
   {

      switch (program->type)
      {
         case _token:
            print_indent(stdout, depth);
            print(stdout, "(token: %d, %d)\n", program->as.token->increment, program->as.token->offset);
            break;

         case _input:
            print_indent(stdout, depth);
            print(stdout, "input\n");
            break;

         case _output:
            print_indent(stdout, depth);
            print(stdout, "output\n");
            break;

         case _loop:
            print(stdout, "\n");
            print_indent(stdout, depth);
            print(stdout, "loop:\n"); 
            print_indent(stdout, depth);
            print(stdout, "{\n");

            print_tokens(program->as.loop, depth+1);
            break;

         case _end_loop:
            print_indent(stdout, depth-1);
            print(stdout, "}\n\n");
            break;
      }
 

      program = program->next;
   }
}




void compiler_output_00(command_line_args* args, FILE* fp, char* buf)
{
   print_prologue(args, fp);
   
   char c;
   int indent = 0;

   for (size_t i = 0; (c = buf[i]) != '\0'; i++)
   {
      switch (c)
      {
         case '>':
            print_indent(fp, indent);
            print(fp, "ptr++;\n");
         break;

         case '<':
            print_indent(fp, indent);
            print(fp, "ptr--;\n");
         break;
      
         case '+':
            print_indent(fp, indent);
            print(fp, "(*ptr)++;\n");
         break;

         case '-':
            print_indent(fp, indent);
            print(fp, "(*ptr)--;\n");
         break;

         case '.':
            print_indent(fp, indent); 
            print(fp, "printf(\"%%c\", *ptr);\n");
         break;

         case ',':
            print_indent(fp, indent); 
            print(fp, "*ptr = getchar();\n");
         break;

         case '[':
            print(fp, "\n");
            print_indent(fp, indent); 
            print(fp, "while (*ptr)\n");
            print_indent(fp, indent);
            print(fp, "{\n");
            indent++;
         break;

         case ']':
            indent--;
            print_indent(fp, indent);
            print(fp, "}\n");
         break;

         case '!':
            break;
      }  
   }
   
   
   print(fp, "}");
}




void compiler_output_01(command_line_args* args, FILE* fp, Token* program, int depth)
{

   while(program)
   {
      switch (program->type)
      {
         case _token:
            print_indent(fp, depth);
            print(fp, "*(ptr +=(%d)) += (%d);\n", program->as.token->offset, program->as.token->increment);
            break;

         case _input:
            print_indent(fp, depth);
            print(fp, "*ptr = getchar();\n");
            break;

         case _output:
            print_indent(fp, depth);
            print(fp, "printf(\"%%c\", *ptr );\n");
            break;

         case _loop:
            print(fp,"\n");
            print_indent(fp, depth);
            print(fp, "while (*ptr)\n"); 
            print_indent(fp, depth);
            print(fp, "{\n");

            compiler_output_01(args, fp, program->as.loop, depth+1);
            break;

         case _end_loop:
            print_indent(fp, depth-1);
            print(fp,"}\n\n");
            break;
      }
   
      program = program->next;
   }
}




void print_indent(FILE* fp, int depth)
{
   for (int i = 0; i < depth+1; i++)
      print(fp, "   "); 
}



void print_prologue(command_line_args* args, FILE* fp)
{
   if (args->flags.benchmark)
   {
      print( fp,

         "#include <stdio.h>\n"
         "#include <stdlib.h>\n"
         "#include <stdbool.h>\n"
         "#include <time.h>\n\n"

         "void benchmark()\n"
         "{\n"
         "   static clock_t tic;\n"
         "   static clock_t toc;\n"
         "   static bool timer_start = false;\n\n"

         "   if(timer_start == false)\n"
         "   {\n"
         "      timer_start = true;\n"
         "      tic = clock();\n"
         "      return;\n"
         "   }\n\n"

         "   if (timer_start == true)\n"
         "   {\n"
         "      toc = clock();\n"
         "      printf(\"[INFO: The program took %%lf seconds]\", (double)(toc - tic) / CLOCKS_PER_SEC);\n"
         "      return;\n"
         "   } \n"  
         "}\n\n"

         "int main()\n"
         "{\n"
         "   atexit(benchmark);\n"
         "   benchmark();\n"
         "   unsigned char cells[30000] = {0};\n"
         "   unsigned char* ptr = &cells[15000];\n"
         "   clock_t time = clock();\n\n"
      );
   }  
   
   else
      print(fp, 

         "#include <stdio.h>\n\n"

         "int main()\n"
         "{\n"
         "   unsigned char cells[30000] = {0};\n"
         "   unsigned char* ptr = &cells[15000];\n\n"
      );
}