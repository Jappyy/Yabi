#include "../include/IO.h"
#include <stdlib.h>


void about()
{
   print ( stdout,

            "\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|                                    YABI: Yet Another BF Interpreter                                   |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  As its name suggests, it's an interpreter for the esoteric programming language \"Brainf**k\"          |\n"
            "|  It comes with a brainf**k to C compiler, which can produce some fairly optimized code by generating  |\n"
            "|  an intermediate representation.                                                                      |\n"
            "|  It also provides a debug mode with tracer, which can generate a log file for you to analyze later.   |\n"
            "|  A built-in benchmark functionality is available in compiler and interpreter mode.                    |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
            "+-------------------------+\n"
            "|  Author: Jacopo Murino  |\n"                                                        
            "+-------------------------+\n"  
            "\n"                                                       
         );
      
   exit(EXIT_SUCCESS);
}

void help()
{
   print ( stdout,

            "\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  HOW TO RUN A PROGRAM IN INTERPRETER MODE:                  ./yabi <input_filename>                   |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );

   print( stdout,

            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  INFO: Brainf**k files use the either \".b\" or \".bf\" as file extension. Both of them are accepted      |\n"
            "|        by this program. Adding the extension at the end of the filenames is optional.                 |\n"
            "|        In fact, I suggest to omit them altogether and let the program figure it out automatically.    |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  IMPORTANT: All braif**k files must be located in the \"/examples\" folder, otherwise the program       |\n"
            "!             won't be able to find them                                                                |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );

   print ( stdout,

            "+-------------------------------------------------------------------------------------------------------+\n"            
            "|                                                                                                       |\n"
            "|  COMPILER MODE:                                            \"--compiler\" or \"-c\" flag                  |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"                             
            "|  Example: ./yabi -c input_filename -> output_filename                                                 |\n"
            "|                                                                                                       |\n"
            "|                                                                                                       |\n"
            "|  IMPORTANT: If no output filename is provided, the input filename will be used as output filename.    |\n"
            "|             Example: ./yabi -c hello_world  (the output will be called hello_world.c)                 |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  To produce more optimized code, add \"--optimize\" or \"-o\" flag                                        |\n"
            "|                                                                                                       |\n"
            "|  Example: ./yabi -c -o input_filename -> output_filename                                              |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );

   print ( stdout,
   
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  To get the execution time of a given BF program, add \"--benchmark\" or \"-b\" flag                      |\n"
            "|                                                                                                       |\n"
            "|  Example: ./yabi -b input_filename                                 (interpreter mode)                 |\n"
            "|           ./yabi -b -c input_filename -> output_filename              (compiler mode)                 |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );

   print ( stdout,
   
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  DEBUG MODE:                                               \"--debug\" or \"-d\" flag.                    |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  Example: ./yabi -d <input_filename> ( -> <output_filename> )                                         |\n"
            "|                                                                                                       |\n"
            "|                                                                                                       |\n"
            "|  IMPORTANT: If you want the program to generate a log output,you must provide an output filename      |\n"
            "|             No log file will be produced otherwise.                                                   |\n"                                                                                       
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );
         
   print ( stdout,
   
            "+-------------------------------------------------------------------------------------------------------+\n"
            "|                                                                                                       |\n"
            "|  To receive information on what a particular brainf**k program does, use \"-info\" flag                 |\n"
            "|  If present, it will print the description at the beginning of the file                               |\n"
            "|                                                                                                       |\n"
            "|  Example: ./yabi -info 99_bottles                                                                     |\n"
            "|                                                                                                       |\n"
            "|  Output: \" This program outputs the lyrics of the song \"99 bottle of beer\" \"                          |\n"
            "|                                                                                                       |\n"
            "+-------------------------------------------------------------------------------------------------------+\n"
            "\n"
         );

   exit(EXIT_SUCCESS);
}