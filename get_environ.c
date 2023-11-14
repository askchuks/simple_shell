#include "Alpha.h"
/**
 * _env - function for environment
 * @information: pointer parameter
 *
 * Return: integer
 */
int _env(info_t *information)
{
	print_list(information->env);
	return (0);
}
/**
 * get_environ - function to get environ variable
 * @information: pointer parameter
 * @var_name: variable name
 *
 * Return: string value
 */
char get_environ(info_t information, const char *var_name)
{
	list_t *n;
	char *c;

	n = information->env;
	while (n)
	{
		c = start(n->string, var_name);
		if (c && *c)
			return (c);
		n = n->next;
	}
	return (NULL);
}
/**
 * env_unset - function to unset environ variable
 * @information: pointer parameter
 *
 * Return: integer
 */
int env_unset(info_t *information)
{
	int i;

	if (information->argc == 1)
	{
		err_puts("few arguments\n");
		return (1);
	}
	for (i = 1; i <= information->argc; i++)
		unset_env(information, information->argv[i]);
	return (0);
}
/**
 * env_set - function to change environ variable
 * @information: pointer parameter
 *
 * Return: integer
 */
int env_set(info_t *information)
{
	if (information->argc != 3)
	{
		err_puts("wrong argument number\n");
		return (1);
	}
	if (set_env(information, information->argv[1], information->argv[2]))
		return (0);
	return (1);
}
/**
 * pop_env - function for environ population
 * @information: pointer parameter
 *
 * Return: integer
 */
int pop_env(info_t *information)
{
	list_t *i;
	size_t j;

	i = NULL;
	for (j = 0; environ[i]; i++)
		add_node_2(&i, environ[j], 0);
	information->env = i;
	return (0);
}
