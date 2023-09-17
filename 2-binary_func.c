#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_b - Converts an unsigned int argument to binary
 * @args: The name for va_list
 *
 * Return: The number of digits printed
 */
int print_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char *binary = malloc(sizeof(char) * 33);
	unsigned int i;
	int j;

	if (!binary)
		return (-1);
	for (i = 0; n > 0; i++)
	{
		binary[i] = (n % 2) + '0';
		n /= 2;
	}
	binary[i] = '\0';
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(binary[j]);
	}
	free(binary);
	return (i);
}

