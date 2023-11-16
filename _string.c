#include "Alpha.h"
/**
 * _strncpy - function to copy string
 * @dest: pointer parameter
 * @src: pointer parameter
 * @i: pointer parameter
 *
 * Return: string
 */
char *_strncpy(char *dest, char *src, int i)
{
	int a, b;
	char *c;

	c = dest;
	a = 0;
	while (src[a] != '\0' && a < i - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < i)
	{
		b = a;
		while (b < i)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (c);
}
/**
 * _strchr - function to find character
 * @string: pointer parameter to string
 * @c: character parameter
 *
 * Return: charcter
 */
char *_strchr(char *string, char c)
{
	do {
		if (*string == c)
			return (string);
	} while (*string++ != '\0');
	return (NULL);
}
/**
 * _strncat - function to concatenate string
 * @dest: pointer parameter
 * @src: pointer parameter
 * @i: parameter
 *
 * Return: string
 */
char *_strncat(char *dest, char *src, int i)
{
	int a, b;
	char *string;

	string = dest;
	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[a] != '\0' && b < i)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	return (string);
}
