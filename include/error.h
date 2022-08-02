#ifndef _ERROR_
#define _ERROR_

#include "../include/IO.h"
#include <stdlib.h>

#define NO_INPUT_ERROR                          1     
#define FILE_NOT_FOUND_ERROR                    2 
#define FUNCTION_FAILURE_ERROR                  3
#define UNMATCHED_BRACKETS_ERROR                4

#define CONTRADDICTING_FLAGS_WARNING            5
#define MISSING_COMPILER_DEBUG_FLAG_WARNING     6
#define MISSING_OUTPUT_FILENAME_WARNING         7
#define BENCHMARK_FLAG_DEBUG_MODE_WARNING       8
#define OPTIMIZE_FLAG_NO_COMPILER_MODE_WARNING  9
#define REDUNDANT_FLAGS_WARNING                 10
#define UNRECOGNIZED_TOKEN_WARNING              11
#define TOO_MANY_ARGUMENTS_WARNING              12

/* Receives an error flag and (optionally) a string as input and prints an error message accordingly. */
void print_message(int message, const char* argument); 

#endif 