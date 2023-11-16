#include "Alpha.h"
/**
 * get_line - function to get new line
 * @information: pointer parameter
 * @pointer: pointer to pointer parameter
 * @len: pointer parameter
 *
 * Return: integer
 */
int get_line(info_t *information, char **pointer, size_t *len)
{
	static char buffer[RD_BUFFER_SIZE];
	static size_t i, length;
	size_t n;
	ssize_t a, b;
	char *p, *p2, *c;

	a = 0;
	b = 0;
	p = NULL;
	p2 = NULL;
	p = *pointer;
	if (p && len)
		b = *len;
	if (i == length)
		i = length = 0;

	a = read_buffer(information, buffer, &length);
	if (a == -1 || (a == 0 && length == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	n = c ? 1 + (unsigned int)(c - buf) : length;
	p2 = re_alloc(p, b, b ? b + n : n + 1);
	if (!p2)
		return (p ? free(p), -1 : -1);

	if (b)
		_strncat(p2, buffer + i, n - i);
	else
		_strncpy(p2, buffer + i, n - i + 1);

	b +=  - i;
	i = n;
	p = p2;

	if (len)
		*len = b;
	*pointer = p;
	return (b);
}
/**
 * input_buffer - function for buffer
 * @information: pointer parameter
 * @buffer: pointer to pointer parameter
 * @length: pointer parameter
 *
 * Return: int
 */
ssize_t input_buffer(info_t *information, char **buffer, size_t *length)
{
	ssize_t i;
	size_t len;

	i = 0;
	len = 0;
	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sa_handler);
#if USE_GETLINE
		i = getline(buffer, &len, stdin);
#else
		i = get_line(information, buffer, &len);
#endif
		if (i > 0)
		{
			if ((*buffer)[i - 1] == '\n')
			{
				(*buffer)[i - 1] = '\0';
				i--;
			}
			information->count_flag = 1;
			rem_comment(*buffer);
			build_hist(information, *buffer, information->history_count++);
			if (_strchr(*buffer, ';'))
			{
				*length = i;
				information->command_buffer = buffer;
			}
		}
	}
	return (i);
}
/**
 * get_input - function to get input
 * @information: pointer parameter
 *
 * Return: int
 */
ssize_t get_input(info_t *information)
{
	static char *buffer;
	static size_t i, j, length;
	ssize_t n;
	char **buffer_a = &(information->arg), *c;

	n = 0;
	_putchar(BUFFER_FLUSH);
	n = input_buffer(information, &buffer, &length);
	if (n == -1)
		return (-1);
	if (length)
	{
		j = i;
		c = buffer + i;

		check_chain(information, buffer, &j, i, length);
		while (j < length)
		{
			if (_chain(information, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			information->cmd_buffer_type = COMMAND_NOR;
		}

		*buffer_a = c;
		return (_strlen(c));
	}
	*buffer_a = buffer;
	return (n);
}
/**
 * read_buffer - function for buffer
 * @information: pointer parameter
 * @buffer: pointer parameter
 * n: parameter pointer
 *
 * Return: int
 */
ssize_t read_buffer(info_t *information, char *buffer, size_t *n)
{
	ssize_t i;

	i = 0;
	if (*n)
		return (0);
	i = read(information->read_fd, buffer, RD_BUFFER_SIZE);
	if (i >= 0)
		*n = i;
	return (i);
}
/**
 * signal_handler - function for control c
 * @n: parameter
 *
 * Return: nothing
 */
void sa_handler(__attribute__((unused))int n)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}
