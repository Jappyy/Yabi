#include "../include/header.h"

int main(int argc, char** argv)
{ 
   #ifdef __linux__ 
      atexit(restore_default);
      init();
   #endif

   clock_t time = clock();

   command_line_args* args = check_args(argc, argv);
   check_flags(args);


   FILE *source = NULL;
   FILE *output = NULL;

   source = open_input(args);

   if (args->flags.info)
   {
      if (argc > 3)
         print_message(TOO_MANY_ARGUMENTS_WARNING, NULL);
      
      info(source);
   }
      
   if (args->output_filename)
      output = open_output(args);

   char* buf = read_file(source);

   if (args->flags.compiler)
      compile(args, buf, output);
   
   else
      interpreter(args, buf, output);
   

   if (args->flags.benchmark)
      if (args->flags.compiler)
         print(stdout, "[INFO] compilation took %lf seconds", (double) (clock() - time)/CLOCKS_PER_SEC);
      
      else
         print(stdout, "[INFO] program execution took %lf seconds", (double) (clock() - time)/CLOCKS_PER_SEC);

}