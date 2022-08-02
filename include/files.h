#ifndef _FILES_
#define _FILES_

#include "../include/error.h"
#include "../include/args.h"


bool check_file_extension(const char* filename, const char* extension);

FILE* open_file(const char* filename, const char* folder, const char* extension, const char* mode);

FILE* open_input(command_line_args* args);

FILE* open_output(command_line_args* args);

void info( FILE* source);

char* read_file( FILE* source);

#endif 