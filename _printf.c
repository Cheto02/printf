#include "main.h"
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format != NULL)/* checks if the format argument is not NULL */
	{
		int count = 0, i;/* init a var count to 0 and declare vars.*/
		int (*j)(va_list);
		va_list args;
		/**
		 * va_start macro to init args variable with var arguments 
		 * va start allows the function to access the variable
		 * arguments using the va_list type.
		 */
		va_start(args, format);
		i = 0;
		/**
		 * function then enters a loop that iterates over each char
		 * in the format string. It checks if the current character
		 * is a % character, which indicates a format specifier.
		 */
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != NULL && format[i] != '\0')
		{
			/**
			 * If the current character is %, the function checks
			 * if the next char is also %. If it is, it means that
			 * a literal % character should be printed.the function
			 * calls the _putchar to print the % character and
			 * increments the count variable
			 */
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += _putchar(format[i]);
					i += 2;
				}
				/**
				 *If the next character is not %, it means
				 *that a format specifier is present, so the
				 *function retrieves the corresponding function
				 *pointer using the get_func function and calls
				 *that function with the args variable.
				 *The result is added to the count variable.
				 */
				else
				{
					j = get_func(format[i + 1]);
					if (j)
						count += j(args);
					/**
					 *If the current character is not %,
					 *it means that it is a regular char
					 *should be printed.function calls the
					 *_putchar function to print.
					 *increments the count variable.
					 */
					else
					count = _putchar(format[i]) + _putchar(format[i + 1]);
					i += 2;
				}
			}
			else
			{
				count += _putchar(format[i]);
				i++;
			}
		}
		va_end(args);/*  clean up the args variable. */
		return (count);/* number of characters printed */
	}
	return (-1);/* If format is NULL, the function returns -1. */
}
