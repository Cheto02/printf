#include "main.h"
/**
 * print_binary - prints binary
 * @args: integer argument
 * Returns: count
 */
int print_binary(va_list args)
{
	int i;

	unsigned int num = va_args(args, unsigned int);
	char binary[33];

	intToBinary(num, binary);
	int count = 0;

	for (i = 0; binary[i] != '/0'; i++)
		count += _putchar(binary[i]);

	return (count);
}
