#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: On success 1, on error -1 and errno set appropriately
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					len += write(STDOUT_FILENO, va_arg(args, char *), sizeof(char *));
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += write(STDOUT_FILENO, "%", sizeof(char));
					len += write(STDOUT_FILENO, &(*format), sizeof(char));
			}
		}
		else
		{
			len += write(STDOUT_FILENO, &(*format), sizeof(char));
		}
		format++;
	}
	va_end(args);
	return (len);
}

