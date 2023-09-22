#include "main.h"

/**
 * print_unsigned - Prints an unsigned int
 * @args: The va_list that contains the unsigned int to be printed
 * Return: The number of digits printed
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
        count += _putchar('0');
    else
        count += print_number(num);

    return count;
}

/**
 * print_octal - Prints an int in octal base
 * @args: The va_list that contains the int to be converted and printed
 * Return: The number of digits printed
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
        count += _putchar('0');
    else
        count += print_base(num, 8); 

    return count;
}

/**
 * print_hex - Prints an int in hexadecimal (lowercase)
 * @args: The va_list that contains the int to be converted and printed
 * Return: The number of digits printed
 */
int print_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
        count += _putchar('0');
    else
        count += print_base(num, 16); /* print lowercase hexadecimal */

    return count;
}

/**
 * print_HEX - Prints an int in hexadecimal (uppercase)
 * @args: The va_list that contains the int to be converted and printed
 * Return: The number of digits printed
 */
int print_HEX(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
        count += _putchar('0');
    else
        count += print_base_UPPER(num, 16); /* print_uppercase hexadecimal */

    return count;
}

