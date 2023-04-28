#include <stdio.h>

void _puts(const char *str) {
    while (*str) {
        putchar(*str++);
    }
}

size_t _strlen(const char *str) {
    size_t len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

