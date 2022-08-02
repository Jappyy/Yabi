#include "../include/header.h"

int main(int argc, char** argv)
{ 
   #ifdef __linux__ 
      atexit(restore_default);
      init();
   #endif

   benchmark();
   command_line_args* args = check_args(argc, argv);
   check_flags(args);

   
   

   //printf("input: %s, output: %s\n\n", args->input_filename, args->output_filename);

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
      benchmark();

/*
   if (args->flags.compiler)    printf("compiler mode\n"   );
   if (args->flags.about)       printf("about\n"           );
   if (args->flags.about_file)  printf("about(file)\n"     );
   if (args->flags.benchmark)   printf("benchmark\n"       );
   if (args->flags.debug)       printf("debug mode\n"      );
   if (args->flags.help)        printf("help\n"            );
   if (args->flags.interpreter) printf("interpreter mode\n");
   if (args->flags.optimize)    printf("optimize\n"        );
*/

}