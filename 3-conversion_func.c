#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_u - Converts an unsigned int argument to unsigned decimal
 * @args: The name for va_list
 *
 * Return: The number of digits printed
 */
int print_u(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0;

    while (n)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
        _putchar(buffer[j]);

    return (i);
}

/**
 * print_o - Converts an unsigned int argument to octal
 * @args: The name for va_list
 *
 * Return: The number of digits printed
 */
int print_o(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0;

    while (n)
    {
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    for (int j = i - 1; j >= 0; j--)
        _putchar(buffer[j]);

    return (i);
}

/**
 * print_x - Converts an unsigned int argument to hexadecimal
 * @args: The name for va_list
 *
 * Return: The number of digits printed
 */
int print_x(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0;

    while (n)
    {
        int temp = n % 16;

        //To convert decimal number to hexadecimal
        buffer[i++] = temp < 10 ? temp + 48 : temp + 87;

        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        _putchar(buffer[j]);

    return (i);
}

/**
 * print_X - Converts an unsigned int argument to hexadecimal (in uppercase)
 * @args: The name for va_list
 *
 * Return: The number of digits printed
 */
int print_X(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0;

    while (n)
    {
        int temp = n % 16;

        //To convert decimal number to hexadecimal
        buffer[i++] = temp < 10 ? temp + 48 : temp + 55;

        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        _putchar(buffer[j]);

    return (i);
}

