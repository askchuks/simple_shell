#include "Alpha.h"
/**
 * _chain - function to test for chain delimeter
 * @information: pointer parameter
 * @buffer: pointer parameter
 * @p: pointer parameter
 *
 * Return: integer
 */
int _chain(info_t *information, char *buffer, size_t *p)
{
	size_t i;

	i = *p;
	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = 0;
		i++;
		information->cmd_buffer_type = COMMAND_OR;
	}
	else if (buffer[i] == '&' && buffer[i + 1] == '&')
	{
		buffer[i] = 0;
		i++;
		information->cmd_buffer_type = COMMAND_AND;
	}
	else if (buffer[i] == ';')
	{
		buf[i] = 0; 
		information->cmd_buffer_type = COMMAND_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}
/**
 * check_chain - function to check chaining
 * @information: pointer parameter
 * @buffer: parameter pointer
 * @p: pointer parameter
 * @i: parameter
 * @length: parameter
 *
 * Return: nothing
 */
void check_chain(info_t *information, char *buffer, size_t *p, size_t i, size_t length)
{
	size_t j;

	j = *p;
	if (information->cmd_buffer_type == COMMAND_AND)
	{
		if (information->stat)
		{
			buffer[i] = 0;
			j = length;
		}
	}
	if (information->cmd_buffer_type == COMMAND_OR)
	{
		if (!information->stat)
		{
			buffer[i] = 0;
			j = length;
		}
	}
	*p = j;
}
/**
 * replacealias - function to replace alias
 * @information: pointer parameter
 *
 * Return: inteegr
 */
int replacealias(info_t *information)
{
	int j;
	list_t *node;
	char *c;
	
	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(information->alias, information->argv[0], '=');
		if (!node)
			return (0);
		free(information->argv(char)[0]);
		c = _strchr(node->string, '=');
		if (!c)
			return (0);
		c = _strdup(c + 1);
		if (!c)
			return (0);
		information->argv[0] = c;
	}
	return (1);
}
/**
 * replace_variable - function to replace variable
 * @information: pointer parameter
 *
 * Return: int
 */
int replace_variable(info_t *information)
{
	int j;
	list_t *node;

	j = 0;
	for (j = 0; information->argv[j]; j++)
	{
		if (information->argv[j][0] != '$' || !information->argv[j][1])
			continue;
		if (!_strcmp(information->argv(char)[j], "$?"))
		{
			replace_str(&(information->argv[j]),
					_strdup(convert_number(information->stat, 10, 0)));
			continue;
		}
		if (!_strcmp(information->argv(char)[j], "$$"))
		{
			replace_str(&(information->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(information->env, &information->argv[j][1], '=');
		if (node)
		{
			replace_str(&(information->argv[j]),
					_strdup(_strchr(node->string, '=') + 1));
			continue;
		}
		replace_str(&information->argv[j], _strdup(""));
	}
	return (0);
}

/**
 * replace_str - function to replace string
 * @previous: pointer to pointer
 * @current: pointer parameter
 *
 * Return: integer
 */
int replace_str(char **previous, char *current)
{
	free(*previous);
	*previous = current;
	return (1);
}
