#include <stdio.h>
/**
 * _strlen - function to find the length of string
 * @string: pointer parameter for string
 *
 * Return: length
 */
size_t _strlen(const char *string)
{
	size_t len;

	while (string[len] != '\0')
		len++;
	return (len);
}
