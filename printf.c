#include "main.h"

void flush_buffer(char buffer[], int *buff_ind);

/**
 * my_printf - The print function
 * @format: The format string
 * Return: The number of characters printed
 */
int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int num_printed_chars = 0, buff_ind = 0;
    char buffer[BUFF_SIZE] = {0};
    
    if (!format)
        return -1;
    
    for (int l = 0; format[l] != '\0'; l++)
    {
        if (format[l] != '%')
        {
            buffer[buff_ind++] = format[l];
            
            if (buff_ind == BUFF_SIZE)
                flush_buffer(buffer, &buff_ind);
            
            num_printed_chars++;
        }
        else
        {
            flush_buffer(buffer, &buff_ind);
            l++;
            
            int flags = get_flags(format, &l);
            int width = get_width(format, &l, args);
            int precision = get_precision(format, &l, args);
            int size = get_size(format, &l);
            
            if (format[l] == '\0')
                return -1;
            
            int printed_chars = handle_print(format[l], args, buffer, flags, width, precision, size);
            
            if (printed_chars == -1)
                return -1;
            
            num_printed_chars += printed_chars;
        }
    }
    
    flush_buffer(buffer, &buff_ind);
    va_end(args);
    
    return num_printed_chars;
}

/**
 * flush_buffer - Prints contents of the buffer if it exists.
 * @buffer: An array of characters
 * @buff_ind: A pointer to the buffer index
 */
void flush_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

