#ifndef _ARGS_
#define _ARGS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/IO.h"


struct flags
{
   bool info;        /* Prints the description at the beginning of the file             */

   bool about;       /* Prints info on this interpreter                                 */             
                     
   bool interpreter; /* Sets interpreter mode (default flag)                            */

   bool compiler;    /* Sets compiler mode (compile BF into a valid C program)          */

   bool debug;       /* Set debug mode                                                  */
   
   bool benchmark;   /* Add benchmark info on both interpreter and compiler mode.       */
                     /* (warning: benchmark unavailable in debug mode.)                 */

   bool help;        /* Print instructions manual for this interpreter/compiler         */

   bool optimize;    /* Create intermediate reppresentation and optimize output program */
                     /* (warning: optimization unavailable in interpreter/debug mode.)  */
};

typedef struct
{
   struct flags flags;
   const  char* input_filename;
   const  char* output_filename;

} command_line_args;

/* Checks wheter a certain input token is a valid flag.         */
bool is_flag(char* arg, command_line_args* input); 

/* Sets flags and parameters in the command_line_params object. */ 
/* Also checks for syntax errors in the input arguments.        */
command_line_args* check_args(int argc, char** argv);

/* Checks for logical errors/contradictions in the flags set.   */
void check_flags(command_line_args* input);

/* Sets compiler flag on and debug flag of, or vice versa       */
void set_compiler_or_debug_flag(command_line_args* input);

/* Prints random info                                           */
void about();

/* Prints instructions manual for this interpreter/compiler     */
void help();

#endif   
 