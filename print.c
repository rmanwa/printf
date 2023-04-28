#include "main.h"
#include "stringutil.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
*/
void _putchar(char c);


char* itoa(int num) {
    static char buf[32] = {0};
    int i = 30;

    if (num == 0) {
        buf[0] = '0';
        return buf;
    }

    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    while (num != 0) {
        buf[i] = (num % 10) + '0';
        i--;
        num /= 10;
    }

    if (is_negative) {
        buf[i] = '-';
        i--;
    }

    return &buf[i+1];
}
int _printf(const char *format, ...)
{
    va_list args;
    int i, len, printed = 0;
    char *str;

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    printed++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    _puts(str);
                    printed += _strlen(str);
                    break;
                case '%':
                    _putchar('%');
                    printed++;
                    break;
                case 'd':
                case 'i':
                    str = itoa(va_arg(args, int));
                    if (str == NULL)
                        str = "(null)";
                    _puts(str);
                    printed += _strlen(str);
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    printed += 2;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            printed++;
        }
    }

    va_end(args);

    return (printed);
}

