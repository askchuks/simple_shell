#include "Alpha.h"
/**
 * _memset - function to fill memory
 * @c: pointer parameter
 * @d: parameter
 * @n: parameter
 * Return: string
 */
char *_memset(char *c, char d, unsigned int n)
{
	unsigned int i;
	
	for (i = 0; i < n; i++)
		c[i] = d;
	return (c);
}
/**
 * _free - function to free a string
 * @p: pointer parameter
 *
 * Return: nothing
 */
void __ffree(char **p)
{
	char **c;
       
	c = p;
	if (!p)
		return;
	while (*p)
		free(*p++);
	free(c);
}
/**
 * re_alloc - function to reallocate memory
 * @pointer: pointer parameter
 * @previous_size: parameter
 * @new_size: parameter
 *
 * Return: nothing
 */
void *re_alloc(void *pointer, unsigned int previous_size, unsigned int new_size)
{
	char *c;
	if (!pointer)
		return (malloc(new_size));
	if (!new_size)
		return (free(pointer), NULL);
	if (new_size == previous_size)
		return (pointer);
	c = malloc(new_size);
	if (!c)
		return (NULL);
	previous_size = previous_size < new_size ? previous_size : new_size;
	while (previous_size--)
		c[previous_size] = ((char *)pointer)[previous_size];
	free(pointer);
		return (c);
}
