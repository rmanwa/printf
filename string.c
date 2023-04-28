#include "main.h"

/**
 * convert_int - Converts an int to a string
 * @num: The int to be converted
 *
 * Return: A pointer to the converted string
 */
char *convert_int(int num)
{
    int i = 0, sign = 0;
    char *str = NULL;

    if (num == 0)
        return ("0");

    if (num < 0)
    {
        sign = 1;
        num = -num;
    }

    i = num_digits(num);
    str = malloc((sign == 1 ? i + 2 : i + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);

    str[i--] = '\0';
    while (num)
    {
        str[i--] = (num % 10) + '0';
        num /= 10;
    }
    if (sign == 1)
        str[i--] = '-';

    return (str + i + 1);
}

