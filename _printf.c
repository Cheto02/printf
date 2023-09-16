#include <stdio.h>
#include <stdarg.h>
#include "main.h"

// Prints a single character
static void printChar(char ch)
{
    _putchar(ch);
}

// Prints a null-terminated string
static void printString(const char *str)
{
    while (*str)
    {
        _putchar(*str);
        str++;
    }
}

// Prints a formatted string
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            printChar(*format);
            count++;
        }
        else
        {
            format++;

            switch (*format)
            {
                case 'c':
                {
                    int ch = va_arg(args, int);
                    printChar(ch);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char*);
                    printString(str);
                    while (*str)
                    {
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    printChar('%');
                    count++;
                    break;
                default:
                    printChar('%');
                    printChar(*format);
                    count += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return count;
}

