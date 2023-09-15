#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */
int _printf(const char *format, ...)
{
	int chr_print = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	while (*format)
	{
		if (*format != '&')
			write(1, format, 1);
			chr_print++;
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format  == '%')
				write(1, format, 1);
				chr_print++;
			else if (*format == 'c')
				char c = va_arg(list, int);

				write(1, &c, 1);
				char_print++
			else if (*format == 's')
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chr_print += str_len;
		}
		format++;
	}
	va_end(list);
	return (chr_print);
}
