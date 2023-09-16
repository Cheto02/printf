#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int printString(const char *str);
int handleFormatSpecifier(const char *format, va_list args) ;


#endif /* MAIN_H */
