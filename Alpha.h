#ifndef alpha_h
#define alpha_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
* creating my own main.h function
* As Alpha.h (header file)
*
* Using display prompt and my own printf
*/
void read.command(char *command, size_t size);
void display_prompt(void);
void self_printf(const char *message);
void execute_command(const char *command);
#endif
