#include "main.h"
/**
 * print_b - Converts an unsigned int to binary and prints it
 * @args: A va_list pointing to the argument to be printed
 *
 * Return: The number of digits printed
 */
int print_b(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int n_copy = n, mask = 1;
    int count = 0;

    while (n_copy > 1)
    {
        n_copy /= 2;
        mask *= 2;
    }

    while (mask)
    {
        _putchar('0' + ((n & mask) != 0));
        count++;
        mask /= 2;
    }

    return (count);
}

