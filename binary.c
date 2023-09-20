#include "main.h"
/**
 * print_binary - print a binary number
 *@args: unsigned integer input
 *
 * Return: no return
 */
int print_binary(va_list args)
{
	unsigned int c;
	int  i, j;
	int arr[100];

	c = va_arg(args, int);
	i = 0;
	if (c == 0)
	{
		_putchar('0');
		return (1);
	}
	while (c > 0)
	{
		arr[i] = c % 2;
		c = c / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(arr[j] + '0');
	return (i);
}
