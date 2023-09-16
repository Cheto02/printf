#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/* Function: _printf
 * -----------------
 * Entry point for the custom _printf implementation.
 * Takes a format string and a variable number of arguments.
 * Iterates over the format string, checks for format specifiers,
 * and calls the appropriate function to handle each specifier.
 * Returns the total number of characters printed.
 */
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
            count += handleFormatSpecifier(format, args);
        }

        format++;
    }

    va_end(args);

    return count;
}
/* Function: handleFormatSpecifier
 * -------------------------------
 * Handles each format specifier encountered in the _printf function.
 * Takes the format specifier and a va_list of arguments as input.
 * Performs the necessary operations based on the specifier,
 * such as printing a character, printing a string, or printing a literal '%'.
 * Returns the number of characters printed for the specific format specifier.
 */
int handleFormatSpecifier(const char *format, va_list args)
{
    switch (*format)
    {
        case 'c':
        {
            int ch = va_arg(args, int);
            printChar(ch);
            return 1;
        }
        case 's':
        {
            char *str = va_arg(args, char*);
            int len = printString(str);
            return len;
        }
        case '%':
            printChar('%');
            return 1;
        default:
            printChar('%');
            printChar(*format);
            return 2;
    }
}
/* Function: printString
 * ---------------------
 * Helper function used to print a null-terminated string.
 * Takes a pointer to a string as input and iterates over the characters of the string,
 * printing each character. Returns the number of characters printed.
 */
int printString(const char *str)
{
    int count = 0;
    while (*str)
    {
        printChar(*str);
        str++;
        count++;
    }
    return count;
}

