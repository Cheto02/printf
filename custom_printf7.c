#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void custom_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            switch (*p)
            {
                case '+':
                    printf("%+d", va_arg(args, int));
                    break;
                case ' ':
                    printf("% d", va_arg(args, int));
                    break;
                case '#':
                    printf("%#x", va_arg(args, int));
                    break;
                default:
                    putchar(*p);
                    break;
            }
        }
        else
        {
            putchar(*p);
        }
    }

    va_end(args);
}

