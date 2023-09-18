#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it
 * @args: Variable argument list containing the unsigned int to convert
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    	/* Retrieve the unsigned int from the variable argument list */
	unsigned int n = va_arg(args, unsigned int);
	/* Buffer to hold the binary string representation */
	char buffer[33];

	/* Null-terminate the buffer */
	buffer[32] = '\0';

	/* Convert the unsigned int to binary */
	for (int i = 31; i >= 0; --i, n >>= 1)
	{
	/* Get the least significant bit and add it to the buffer */
	buffer[i] = (n & 1) + '0';
	}

	/* Write the binary string to standard output and return the number of characters written */
	return write(1, buffer, 32);
}

