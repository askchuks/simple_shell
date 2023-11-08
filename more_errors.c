#include "Alpha.h"
/**
 * print_err - function that prints error
 * @information: pointer parameter
 * @c: character pointer parameter
 *
 * Return: nothing
 */
void print_err(info_t *information, char *c)
{
	err_puts(information->fname);
	err_puts(": ");
	_print_d(information->count, STDERR_FILENO);
	err_puts(": ");
	err_puts(information->argv[0]);
	err_puts(": ");
	err_puts(c);
}
/**
 * rem_comment - function to remove comments
 * @buffer: pointer parameter
 *
 * Return: nothing
 */
void rem_comment(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != '\0'; j++)
	{
		if (buffer[j] == '#' && (!j || buffer(j - 1) == ' '))
		{
			buffer[j] = '\0';
			break;
		}
	}
}
/**
 * _print_d - function prints decimal
 * @user_input: input parameter
 * @file_des: file descriptor
 *
 * Return: integer
 */
int _print_d(int user_input, int file_des)
{
	int j, counter;
	unsigned int ab, present;

	int (*$_putchar)(char) = _putchar;

	counter = 0;
	if (file_des == STDERR_FILENO)
		$_putchar = err_putchar;
	if (user_input < 0)
	{
		ab = -user_input;
		$_putchar('-');
		counter++;
	}
	else
		ab = user_input;
	present = ab;
	for (j = 1000000000, j > 1; i /= 10)
	{
		if (ab / j)
		{
			$_putchar('0' + present / j);
			counter++;
		}
		present %= j;
	}
	$_putchar('0' + present);
	counter++;
	return (counter);
}
/**
 * _itoa - function like itoa
 * @number: number parameter
 * @a: parameter
 * @flag: paramteter
 *
 * Return: integer
 */
char *_itoa(long int number, int a, int flag)
{
	static char *arr;
	static char buffer[50];
	char sign;
	char *pointer;
	unsigned long int i;

	sign = 0;
	i = number;
	if (!(flag & UNSIGNED) && number < 0)
	{
		i = -number;
		sign = '-';
	}
	arr = flag & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';
	do {
		*--pointer = arr[i % a];
		i /= a;
	} while (i != 0);
	if (sign)
		*--pointer = sign;
	return (pointer);
}
