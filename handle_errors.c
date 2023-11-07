#include "shellMain.h"
/**
 * err_putchar -  function to print error for char
 * @c: character parameter
 *
 * Return: integer
 */
int err_putchar(char c)
{
	static int j;
	static char buffer[WR_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || j >= WR_BUFFER_SIZE)
	{
		write(2, buffer, j);
		j = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[j++] = c;
	return (1);
}
/**
 * err_puts - function to print str
 * @string: pointer parameter to string
 *
 * Return: nothing
 */
void err_puts(char *string)
{
	int j;

	j = 0;
	if (!string)
		return;
	while (string[j] != '\0')
	{
		err_putchar(string[j]);
		j++;
	}
}
/**
 * puts_fd - function to print str
 * @string: string pointer paramter
 * @file_des: file descriptor
 *
 * Return: integer
 */
int puts_fd(char *string, int file_des)
{
	int j;

	j = 0;
	if (!string)
		return (0);
	while (*string)
		j += put_fd(*string++, file_des);
	return (j);
}
/**
 * put_fd - function to print str
 * @c: character parameter
 * @file_des: file descriptor
 *
 * Return: integer
 */
int put_fd(char c, int file_des)
{
	static int j;
	static char buffer[WR_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || j >= WR_BUFFER_SIZE)
	{
		write(file_des, buffer, j);
		j = 0;
	}
	if (c != BUFFER_FLUSH)
		c = buffer[j++];
	return (1);
}
