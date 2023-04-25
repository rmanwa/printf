#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

// Flags used to indicate formatting options
enum {
    F_MINUS = 1,
    F_PLUS = 2,
    F_ZERO = 4,
    F_HASH = 8,
    F_SPACE = 16
};

// Sizes used to indicate the length of a variable type
enum {
    S_LONG = 2,
    S_SHORT = 1
};

// Struct to hold a format specifier and its associated function
typedef struct {
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i);

#endif

