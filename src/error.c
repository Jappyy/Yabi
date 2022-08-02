#include "../include/error.h"

void print_message(int message, const char* argument)
{
   switch (message)
   {
      case NO_INPUT_ERROR:
         print(stderr, "ERROR: No input filename provided.\n"); 
         exit(NO_INPUT_ERROR);

      case FILE_NOT_FOUND_ERROR: 
         print(stderr, "ERROR: File \"%s\" not found.\n", argument); 
         exit(FILE_NOT_FOUND_ERROR);
    
      case FUNCTION_FAILURE_ERROR:
         print(stderr, "ERROR: Function \"%s\" failed.\n", argument); 
         exit(FUNCTION_FAILURE_ERROR);

      case UNMATCHED_BRACKETS_ERROR:
         print(stderr, "ERROR: Code contains unmatched brackets.\n");
         exit(UNMATCHED_BRACKETS_ERROR);

      case CONTRADDICTING_FLAGS_WARNING:
         print(stderr, "WARNING: Contraddicting flags. --debug and --compile flags cannot be set simultaneously.\n");
         break;

      case MISSING_COMPILER_DEBUG_FLAG_WARNING:
         print(stderr, "WARNING: Both input and output filenames have been provided, but neither --debug nor --compile flag has been set.\n"); 
         break;

      case MISSING_OUTPUT_FILENAME_WARNING:
         print(stderr, "WARNING: No output filename provided. Filename will be assigned automatically.\n");
         break;

      case BENCHMARK_FLAG_DEBUG_MODE_WARNING:
         print(stderr, "WARNING: Benchmark is not available in debug mode. Flag will be ignored\n");
         break;

      case OPTIMIZE_FLAG_NO_COMPILER_MODE_WARNING:
         print(stderr, "WARNING: -optimize flag is exclusive for compiler mode. Flag will be ignored\n");
         break;
      
      case REDUNDANT_FLAGS_WARNING:
         print(stderr, "WARNING: Redundant flag detected. %s flag has already been set.\n", argument);
         break;

      case UNRECOGNIZED_TOKEN_WARNING:
         print(stderr, "WARNING: Unrecognized token detected. \"%s\" token will be ignored.\n", argument);
         break;
      
      case TOO_MANY_ARGUMENTS_WARNING:
         print(stderr, "WARNING: Too many arguments provided.\n");
         break;
   }
}