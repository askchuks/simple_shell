#include "Alpha.h"
/**
 * info_set - function for info_t struct
 * @information: pointer parameter
 * @c: pointer to pointer parameter
 *
 * Return: nothing
 */
void info_set(info_t *information, char **c)
{
	int i;

	information->fname = c[0];
	if (information->argv)
	{
		information->argv = _strtow(information->argv, " \t");
		if (!information->argv)
		{
			information->argv = malloc(sizeof(char *) * 2);
			if (information->argv)
			{
				information->argv[0] = _strdup(information->argv);
				information->argv[1] =  NULL;
			}
		}
		for (i = 0; information->argv && information->argv[i]; i++)
		{
			;
		}
		information->argc = i;
		replacealias(information);
		replace_variable(information);
	}
}
/**
 * clear_information - function for info_t struct
 * @information: pointer parameter
 *
 * Return: nothing
 */
void clear_information(info_t *information)
{
	information->argv = NULL;
	information->argv = NULL;
	information->path = NULL;
	information->argc = 0;
}
/**
 * free_information - function to free info_t
 * @information: pointer parameter
 * @i: parameter
 *
 * Return: nothing
 */
void free_information(info_t *information, int i)
{
	_free(information->argv);
	information->argv = NULL;
	information->path = NULL;
	if (i)
	{
		if (!information->command_buffer)
			free(information->argv);
		if (information->env)
			free_list(&(information->env));
		if (information->history)
			free_list(&(information->history));
		if (information->alias)
			free_list(&(information->alias));
		ffree(information->environ);
		information->environ = NULL;
		__free((void **)information->commandd_buffer);
		if (information->read_fd > 2)
			close(information->read_fd);
		_putchar(BUFFER_FLUSH);
	}
}
