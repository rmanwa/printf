#include "main.h"
#include "memory.h"

/**
 * _malloc - allocate memory block
 * @size: size of memory block
 *
 * Return: pointer to allocated memory, NULL if failure
 */
void *_malloc(unsigned int size)
{
	void *ptr;

	if (size == 0)
		return (NULL);

	ptr = malloc(size);

	if (ptr == NULL)
		return (NULL);

	return (ptr);
}

