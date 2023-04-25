#include "main.h"
#include <stdio.h>

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;
    char c, *s;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            count++;
        }
        else
        {
            switch (format[++i])
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    while (*s)
                    {
                        putchar(*s++);
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(format[i]);
                    count += 2;
                    break;
            }
        }
    }

    va_end(args);

    return count;
}
