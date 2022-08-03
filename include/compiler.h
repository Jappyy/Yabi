#ifndef _COMPILER_
#define _COMPILER_

#include "../include/error.h"
#include "../include/args.h"
#include "../include/brackets.h"

#include <stdarg.h>
#include <regex.h>

typedef enum type
{
   _move_ptr, //used to signal that you have to move the pointer
   _token,
   _input,
   _output,
   _const_output,
   _loop,
   _end_loop,
   _set_val,

} Type;


typedef struct BF_token
{
   int offset;
   int increment;

} BF_token;


union as
{
   struct BF_token* token;
   struct token* loop;
   int value;
};

typedef struct token
{
   enum type type;
   union as as;
   struct token* next;

} Token;


void compile(command_line_args* args, char* buf, FILE* output);

BF_token* parse_params(char* string);

Token* new_token(Type type, ...);

Token* parse(char* buf);

Token* internal_parser(char* ptr,int len, char* buf, regex_t preg);

void print_tokens(Token* program, int depth);

void print_prologue(command_line_args* args, FILE* fp);


void compiler_output_00(command_line_args* args, FILE* fp, char* buf);
void compiler_output_01(command_line_args* args, FILE* fp, Token* program, int depth);

void print_indent(FILE* fp, int depth);

#endif 
