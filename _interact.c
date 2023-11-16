#include "Alpha.h"
/**
 * interact - checks if shell is in interactive mode
 * @info: info address
 *
 * Return: integer
 */
int _interact(info_t *information)
{
	return (isatty(STDIN_FILENO) && information->read_fd <= 2);
}
/**
 * _atoi - function to convert string to number
 * @string: pointer parameter to string
 *
 * Return: integer
 */
int _atoi(char *string)
{
	int i, result, flag, sign;
	unsigned int output;

	flag = 0;
	sign = 1;
	output = 0;
	for (i = 0; string[i] != '\0' && flag != 2; i++)
	{
		if (string[i] == '-')
			sign *= -1;
		if (string[i] >= '0' && string[i] <= '9')
		{
			flag = 1;
			output *= 10;
			output += (string[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		result = -output;
	else
		result = output;
	return (result);
}
/**
 * _delimiter - checks for delimiter
 * @c:character
 * @delimiter: delimeter pointer
 *
 * Return: integer
 */
int _delimiter(char c, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter++ == c)
			return (1);
	}
	return (0);
}
