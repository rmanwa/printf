#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void _putchar(char c);
int print_char(va_list args, char buffer[], int ibuf);
int print_str(va_list args, char buffer[], int ibuf);
int print_number(va_list args, char buffer[], int ibuf);
int print_unsigned(va_list args, char buffer[], int ibuf);
int print_hex(va_list args, char buffer[], int ibuf, int uppercase);
int print_octal(va_list args, char buffer[], int ibuf);
int print_binary(va_list args, char buffer[], int ibuf);
int print_pointer(va_list args, char buffer[], int ibuf);
int print_custom(va_list args, char buffer[], int ibuf, const char *format);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

enum
{
    F_MINUS = 1,
    F_PLUS = 2,
    F_ZERO = 4,
    F_HASH = 8,
    F_SPACE = 16
};

enum
{
    S_LONG = 2,
    S_SHORT = 1
};

typedef struct
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

#endif

