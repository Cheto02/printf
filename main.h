#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);


int get_width(const char *format, int *i, va_list list);

/***Utils***/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
