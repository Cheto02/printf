#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
void printChar(int ch, int* count);
void printString(char* str, int* count);

#endif /* MAIN_H */
