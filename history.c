#include "Alpha.h"
/**
 * wr_history - function to create/append a file
 * @information: pointer parameter
 *
 * Return: integer
 */
int wr_history(info_t *information)
{
	ssize_t file_des;
	char *filename;
	list_t *n;

	filename = get_hist(information);
	n = NULL;
	if (!filename)
		return (-1);
	file_des = open(filename, O_CREAT || O_TRUNC || O_RDWR, 0664);
	free(filename);
	if (file_des == -1)
		return (-1);
	for (n = information->history; n; n = n->next)
	{
		puts_fd(n->string, file_des);
		put_fd('\n', file_des);
	}
	put_fd(BUFFER_FLUSH, file_des);
	close(file_des);
	return (1);
}
/**
 * get_hist - function to get history
 * @information: pointer parameter
 *
 * Return: string
 */
char *get_hist(info_t *information)
{
	char *buffer, *direc;

	direc = get_env(information, "HOME= ");
	if (!direc)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, direc);
	_strcat(buffer, "/");
	_strcat(buffer, HISTORY_FILE);
	return (buffer);
}
/**
 * build_hist - function for history
 * @information: pointer paramter
 * @buffer: pointer parameter
 * @count: parameter
 *
 * Return: intger
 */
int build_hist(info_t *information, char *buffer, int count)
{
	list_t *i;

	i = NULL;
	if (information->history)
		i = information->history;
	add_node2(&i, buffer, count);
	if (!information->history)
		information->history = i;
	return (0);
}
/**
 * rename_hist - function for history
 * @information: pointer parameter
 *
 * Return: integer
 */
int rename_hist(info_t *information)
{
	list_t *n;
	int j;

	n = information->history;
	j = 0;
	while(n)
	{
		n->number = j++;
		n = n->next;
	}
	return (information->history_count = j);
}
/**
 * rd_history - function for history
 * @information: pointer parameter
 *
 * Return: integer
 */
int rd_history(info_t *information)
{
	int i, final, count;
	ssize_t file_des, read_len, size;
	struct stat a;
	char *buffer, *filename;

	size = 0;
	final = 0;
	count = 0;
	buffer = NULL;
	filename = get_hist(information);
	if (!filename)
		return (0);
	file_des = open(filename, O_RDONLY);
	free(filename);
	if (file_des == -1)
		return (0);
	if (size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	read_len = read(file_des, buffer, size);
	buffer[size] = 0;
	if (read_len <= 0)
		return (free(buffer), 0);
	close(file_des);
	for (i = 0; i < size; i++)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			build_hist(information, buffer + final, count++);
			final = i + 1;
		}
	}
		if (final != i)
			build_hist(information, buffer + final, count++);
		free(buffer);
		information->history_count = count;
		while (information->history_count-- >= HISTORY_MAX)
			del_node(&(information->history), 0);
		rename_hist(information);
		return (information->history_count);
}
