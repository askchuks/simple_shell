#include "Alpha.h"
/**_strtow - function for strings to words
 * @string: pointer parameter
 * @c: pointer parameter
 *
 * Return: string
 */
char **_strtow(char *string, char *c)
{
	int i, j, a, b, number;
	char **r;

	number = 0;
	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!c)
		c = " ";
	for (i = 0; string[i] != '\0'; i++)
	{
		if (!_delimiter(string[i], c) && (_delimiter(string[i + 1], c) || !string[i + 1]))
			number++;
	}
	if (number == 0)
		return (NULL);
	r = malloc((1 + number) * sizeof(char *));
	if (!r)
		return (NULL);
	for (j = 0; j < number; j++)
	{
		while (_delimiter(string[i], c))
			i++;
		a = 0;
		while (_delimiter(string[i + a], c) && string[i + a])
			a++;
		r[j] = malloc((a + 1) * sizeof(char));
		if (!r[j])
		{
			for (a = 0; a < j; a++)
				free(r[a]);
			free(r);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			r[j][b] = string[i++];
		r[j][b] = 0;
	}
	r[j] = NULL;
}
/**
 * __strtow - second function
 * @string: pointer parameter
 * @c: parameter
 *
 * Return: string
 */
char **__strtow(char *string, char c)
{
	int i, j, a, b, number;
	char **s;

	number = 0;
	if (string == NULL || string[0] == 0)
		return (NULL);
	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] != c && string[i + 1] == c) ||
		    (string[i] != c && !string[i + 1]) || string[i + 1] == c)
			number++;
	if (number == 0)
		return (NULL);
	s = malloc((1 + number) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < number; j++)
	{
		while (string[i] == c && string[i] != c)
			i++;
		a = 0;
		while (string[i + a] != c && string[i + a] && string[i + a] != c)
			a++;
		s[j] = malloc((a + 1) * sizeof(char));
		if (!s[j])
		{
			for (a = 0; a < j; a++)
				free(s[a]);
			free(s);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			s[j][b] = str[i++];
		s[j][b] = 0;
	}
	s[j] = NULL;
	return (s);
}
