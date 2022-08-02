#include "../include/args.h"
#include "../include/error.h"


bool is_flag(char* arg, command_line_args* args)
{
   if (strcmp(arg, "-info") == 0)
   {
      if (args->flags.about == true)
         print_message(REDUNDANT_FLAGS_WARNING, "-info");

      args->flags.info = true;
      return true; 
   }

   if (strcmp(arg, "-about") == 0)
   {
      if (args->flags.about == true)
         print_message(REDUNDANT_FLAGS_WARNING, "-about");

      args->flags.about = true;
      return true; 
   }

   else if (strcmp(arg, "-help") == 0)
   {
      if (args->flags.help == true)
         print_message(REDUNDANT_FLAGS_WARNING, "-help");
      
      args->flags.help = true; 
      return true; 
   }

   else if (strcmp(arg, "--debug") == 0 || (strcmp(arg, "-d") == 0))
   {
      if (args->flags.debug == true)
         print_message(REDUNDANT_FLAGS_WARNING, "--debug");

      args->flags.debug = true;
      return true;
   }

   else if (strcmp(arg, "--compile") == 0 || (strcmp(arg, "-c") == 0))
   {
      if (args->flags.compiler == true)
         print_message(REDUNDANT_FLAGS_WARNING, "--compile");

      args->flags.interpreter = false;
      args->flags.compiler = true;
      return true;
   }

   else if (strcmp(arg, "--optimize") == 0 || (strcmp(arg, "-o") == 0))
   {
      if (args->flags.debug == true)
         print_message(REDUNDANT_FLAGS_WARNING, "--optimize");

      args->flags.optimize = true;
      return true;
   }

   else if (strcmp(arg, "--benchmark") == 0 || (strcmp(arg, "-b") == 0))
   {
      if (args->flags.debug == true)
         print_message(REDUNDANT_FLAGS_WARNING, "--benchmark");

      args->flags.benchmark = true;
      return true;
   }

   else return false;
}
   



command_line_args* check_args(int argc, char** argv)
{
   command_line_args* args = NULL;

   // Allocate memory for the command_line_args object.
   if ((args = malloc(sizeof(command_line_args))) == NULL)
      print_message(FUNCTION_FAILURE_ERROR, "malloc()");

   // Set default values.
   args->flags.info        =  false;
   args->flags.about       =  false;
   args->flags.interpreter =   true;
   args->flags.compiler    =  false;
   args->flags.debug       =  false;
   args->flags.benchmark   =  false;
   args->flags.help        =  false;
   args->flags.optimize    =  false;
   args->input_filename     =  NULL;
   args->output_filename    =  NULL; 

   // No argument has been provided
   if (argc < 2)
      print_message(NO_INPUT_ERROR, NULL);


   // Loop through all the input tokens
   for (int i = 1; i < argc; i++)
   {
      if (!is_flag(argv[i], args)) // if the token is not a valid flag
      {
         if (strcmp(argv[i], "->") == 0) // if the current token is "->""
         { 
            if (args->output_filename) // if output_filename has already been set

               //warning: the token is -> but output_filename is already set
               print_message(TOO_MANY_ARGUMENTS_WARNING, NULL); 
               
            else // if output_filename has not been set yet
            {
               if (i+1 < argc) // if -> is not the last token
                  
                  // set next token as output_filename (syntax: blah blah -> output_filename blah blah )
                  args->output_filename = argv[++i];

               else //warning: "->" is the last token, output_filename is missing. 
               {
                  print_message(MISSING_OUTPUT_FILENAME_WARNING, NULL);
                  args->output_filename = args->input_filename;
               }   
            }
         } 

         else // the token is not "->"
         {
            if (args->input_filename ) //if input_filename has already been set
               print_message(UNRECOGNIZED_TOKEN_WARNING, argv[i]);// ignore token and throw a warning
            
            else // since no input_filename has been set yet, it's safe to assume that the current token is indeed input_filename
               (args->input_filename = argv[i]); 
         }       
      }

      else //the current token is a valid flag
      {
         if (args->flags.help) // check if the -help flag has been set
         {
            if (argc > 2) // if "-help" is passed together with other arguments, throw a warning
               print_message(TOO_MANY_ARGUMENTS_WARNING, NULL);
            
            help(); 
         }

         if (args->flags.about) // check if the -help flag has been set
         {
            if (argc > 2) // if "-help" is passed together with other arguments, throw a warning
               print_message(TOO_MANY_ARGUMENTS_WARNING, NULL);
            
            about(); 
         }
      }
   }  

   return args;
}

void check_flags(command_line_args* args)
{
   if (!args->input_filename)
      print_message(NO_INPUT_ERROR, NULL);

   if (!args->flags.compiler && !args->flags.debug && args->input_filename  && args->output_filename)
   {
      print_message(MISSING_COMPILER_DEBUG_FLAG_WARNING, NULL); 
      set_compiler_or_debug_flag(args);
   } 

   if (args->flags.compiler && !args->output_filename)
   {
      print_message(MISSING_OUTPUT_FILENAME_WARNING, NULL);
      args->output_filename = args->input_filename;
   }

   if (args->flags.benchmark && args->flags.debug)
   {
      print_message(BENCHMARK_FLAG_DEBUG_MODE_WARNING, NULL);
      args->flags.debug = false;
   }
   
   if (args->flags.optimize && args->flags.interpreter)
   {
      print_message(OPTIMIZE_FLAG_NO_COMPILER_MODE_WARNING, NULL);
      args->flags.optimize = false;
   }
       
   if (args->flags.compiler && args->flags.debug)
   {
      print_message(CONTRADDICTING_FLAGS_WARNING, NULL);
      set_compiler_or_debug_flag(args);
   } 
}

void set_compiler_or_debug_flag(command_line_args* args)
{
   int c = 0;
   int d = 0;

   while (c != '0' && c != '1')
   {
      printf("Press 0 to run compiler mode, press 1 to run debug mode: ");

      c = getchar();

      do d = getchar(); while (d != '\n');
         
      if (c != '0' && c != '1')
         print(stderr, "WARNING: Invalid input.\n");     
   }
   
   if (c == '0')
   {
      args->flags.compiler = true;
      args->flags.debug = false;
      args->flags.interpreter = false;
   }

   else if (c == '1')
   {
      args->flags.compiler = false;
      args->flags.debug = true;
      args->flags.interpreter = true;
   } 
}