#include "Alpha.h"
/**
 * get_environment -  function to get environ
 * @information: pointer parameter
 *
 * Return: character
 */
char **get_environment(info_t *information)
{
	if (!information->environ || information->env_change)
	{
		information->environ = list_to_str(information->env);
		information->env_change = 0;
	}
	return (information->environ);
}
int set_env(info_t *information, char *variable, char *value)
{
	char *buf;
	list_t *n;
	char *c;

	buf = NULL;
	if (!variable || !value)
		return (0);
	buf = malloc(_strlen(variable) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, variable);
	_strcat(buf, "=");
	_strcat(buf, value);
	n = information->env;
	while (n)
	{
		c = starts_with(n->string, variable);
		if (c && *c == '=')
		{
			free(n->string);
			n->string = buf;
			information->env_change = 1;
			return (0);
		}
		n = n->next;
	}
	add_node2(&(information->env), buf, 0);
	free(buf);
	information->env_change = 1;
	return (0);
}
int unset_env(info_t *info, char *variable)
{
	list_t *n;
	size_t a;
	char *c;

	n = info->env;
	a = 0;
	if (!n || !variable)
		return (0);
	while (n)
	{
		c = starts_with(n->string, variable);
		if (c && *c == '=')
		{
			info->env_change = del_node_index(&(info->env), a);
			a = 0;
			n = n->next;
			continue;
		}
		n = n->next;
		a++;
	}
	return (info->env_change);
}
