#ifndef _BRACKETS_
#define _BRACKETS_

#include "../include/error.h"

void check_brackets(char* buf);

size_t closed_bracket(char* buf, size_t index);

size_t open_bracket(char* buf, size_t index);

#endif