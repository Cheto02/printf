#include <stdarg.h> /* Include the standard argument library. */
#include <stdio.h>  /* Include the standard input/output library. */
#include "main.h"

int _printf(const char *format, ...) { /* Define the function _printf which takes a format string and a variable number of arguments. */
    va_list args; /* Declare a va_list type variable. */
    int count = 0; /* Initialize the count of printed characters. */
    const char *traverse; /* Declare a pointer to traverse the format string. */
    char *temp; /* Declare a pointer to traverse the string argument. */

    va_start(args, format); /* Initialize the va_list variable with the arguments after format. */

    for (traverse = format; *traverse != '\0'; traverse++) { /* Start a loop over the format string. */
        while (*traverse != '%' && *traverse != '\0') { /* Print characters until '%' or end of string. */
            putchar(*traverse); /* Print the character to stdout. */
            traverse++; /* Move to the next character. */
            count++; /* Increment the count of printed characters. */
        }

        if (*traverse == '\0') break; /* If end of string, exit the loop. */

        traverse++; /* Skip '%' character. */

        switch (*traverse) { /* Switch on the character after '%'. */
            case 'c': { /* If it's 'c', a character argument is expected. */
                char c = va_arg(args, int); /* Get the next argument as an int and convert to char. */
                putchar(c); /* Print the character. */
                count++; /* Increment the count of printed characters. */
                break;
            }
            case 's': { /* If it's 's', a string argument is expected. */
                char *s = va_arg(args, char*); /* Get the next argument as a string. */
                for (temp = s; *temp != '\0'; temp++) { /* Loop over the string until end of string. */
                    putchar(*temp); /* Print each character of the string. */
                    count++; /* Increment the count of printed characters. */
                }
                break;
            }
            case '%': { /* If it's '%', print a '%' character. */
                putchar('%');
                count++; /* Increment the count of printed characters. */
                break;
            }
        }
    }

    va_end(args); /* Clean up the va_list variable. */

    return count; /* Return the number of characters printed. */
}
int main() {
    _printf("Hello, %s!\n", "world");
    return 0;
}
