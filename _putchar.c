#include "Alpha.h"
/**
 * _putchar - function to print character
 * @c: character
 *
 * Return: integer
 */
int _putchar(char c)
{
	static int i;
	static char buffer[WR_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WR_BUFFER_SIZE)
	{
		write(1, buffer, 1);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[i++] = c;
	return (1);
}
/**
 * _puts - function to get string
 * @string: pointer parameter
 *
 * Return: nothing
 */
void _puts(char *string)
{
	int i;

	i = 0;
	if (!string)
		return;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}
/**
 * _strcpy - function to copy string
 * @dest: pointer parameter for destination
 * @src: pointer parameter
 *
 * Return:string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _strdup - function to duplicate string
 * @string: pointer parameter for string
 *
 * Return: string
 */
char *_strdup(const char *string)
{
	int len;
	char *result;

	len = 0;
	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	for (len++; len--;)
		result[len] = *--string;
	return (result);
}
