#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void printChar(int ch, int* count) {
    _putchar(ch);
    (*count)++;
}

void printString(char* str, int* count) {
    while (*str) {
        _putchar(*str);
        str++;
        (*count)++;
    }
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            count++;
        }
        else
        {
            format++;

            switch (*format)
            {
                case 'c':
                    printChar(va_arg(args, int), &count);
                    break;
                case 's':
                    printString(va_arg(args, char*), &count);
                    break;
                case '%':
                    printChar('%', &count);
                    break;
                default:
                    printChar('%', &count);
                    printChar(*format, &count);
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return count;
}

