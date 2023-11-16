#include "Alpha.h"
/**
 * __free - function to free a pointer
 * @pointer: pointer to pointer parameter
 *
 * Return: integer
 */
int __free(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
/**
 * _cmd - function for executable
 * @information: pointer parameter
 * @path: pointer parameter
 *
 * Return: integer
 */
int _cmd(info_t *information, char *path)
{
	struct stat a;

	(void)information;
	if (a.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * duplicate_char - function to duplicate character
 * @pathstring: pointer parameter
 * @start: parameter
 * @stop: parameter
 *
 * Return: string
 */
char *duplicate_char(char *pathstring, int begin, int stop)
{
	static char buffer[1024];
	int i, j;

	i = 0;
	j = 0;
	for (j = 0, i = begin; i < stop; i++)
		if (pathstring[i] != ':')
			buffer[j++] = pathstring[i];
	buffer[j] = 0;
	return (buffer);
}
/**
 * find_path - function to find command
 * @information: pointer parameter
 * @pathstring: pointer parameter
 * @command: pointer parameter
 *
 * Return: string
 */
char *find_path(info_t *information, char *pathstring, char *command)
{
	int i, current_position;
	char *path;

	i = 0;
	current_position = 0;
	if (!pathstring)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (_cmd(information, command))
			return (command);
	}
	while (1)
	{
		if (!pathstring[i] || pathstring[i] == ':')
		{
			path = duplicate_char(pathstring, current_position, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (_cmd(information, path))
				return (path);
			if (!pathstring[i])
				break;
			current_position = i;
		}
		i++;
	}
	return (NULL);
}
