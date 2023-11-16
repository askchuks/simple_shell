#include "Alpha.h"
/**
 * _strlen - function to find the length of string
 * @string: pointer parameter for string
 *
 * Return: length
 */
size_t _strlen(char *string)
{
	size_t len;

	while (string[len] != '\0')
		len++;
	return (len);
}
/**
 * _strcat - function to concatenate string
 * @dest: pointer parameter destination
 * @src: pointer parameter source
 *
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	char *result;

	result = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}
/**
 * _strcmp - function to compare strings
 * @string1: first string
 * @string2: second string
 *
 * Return: integer
 */
int _strcmp(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
}
/**
 * starts_with - function to check needle
 * @hay_st: pointr parameter
 * @n: pointer parameter
 *
 * Return: character
 */
char *starts_with(const char *hay_st, const char *n)
{
	while (*n)
		if (*n++ != *hay_st++)
			return (NULL);
	return ((char *)hay_st);
}
/**
 * _alpha - function to check for alphabets
 * @i: parameter
 *
 * Return: integer
 */
int _alpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}
