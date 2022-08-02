#ifndef _INTERPRETER_
   #define _INTERPRETER_

   #include "../include/args.h"
   #include "../include/brackets.h"
   #include <time.h>


#define CELLS_NUM 30000
#define ESC 27

typedef enum
{
   none,
   up_arrow_key,
   down_arrow_key,
   left_arrow_key,
   right_arrow_key,
   skip

} debug_controls;

debug_controls internal_debug_input();

debug_controls debug_input();

void interpreter(command_line_args* args, char* buf, FILE* output);

void logger(FILE* fp, int counter, char instruction, int cell_pos, int cell_val);

void print_cells(FILE* fp, unsigned char cells[], unsigned char* ptr, int offset);

bool debug_exec(FILE* fp, unsigned char cells[], unsigned char* ptr);



#endif