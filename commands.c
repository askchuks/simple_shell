#include "Alpha.h"
/**
 * _cd - function to change directory
 * @information: information pointer
 *
 * Return: integer
 */
int _cd(info_t *information)
{
	char *c, *direc, buffer[1024];
	int chdirec;

	c = getcwd(buffer, 1024);
	if (!c)
		_puts("getcwd error\n");
	if (!information->argv[1])
	{
		direc = get_env(information, "HOME=");
		if (!direc)
		{
			chdir = /*something*/
			chdir((direc = get_env(information, "PWD=")) ? direc : "/");
		}
		else
			chdirec = chdir(direc);
	}
	else if (_strcmp(information->(char)argv[1], "-") == 0)
	{
		if (!get_env(information, "OLDPWD="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(get_env(information, "OLDPWD=")), _putchar('\n');
		chdir((direc = get_env(information, "OLDPWD=")) ? direc : "/");
	}
	else
		chdirec = chdir(information->(char *)argv[1]);
	if (chdirec == -1)
	{
		print_err(information, "cannot cd to");
		err_puts(information->argv[1]), err_putchar('\n');
	}
	else
	{
		set_env(information, "OLDPWD", get_env(information, "PWD="));
		set_env(information, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * __exit - function to exit shell
 * @information: pointer parameter
 *
 * Return: integer
 */
int __exit(info_t *information)
{
	int check_exit;

	if (information->argv[1])
	{
		check_exit = _err_atoi(information->(char)argv[1]);
		if (check_exit == -1)
		{
			information->stat = 2;
			print_err(information, "error: ");
			err_puts(information->(char)argv[1]);
			err_putchar('\n');
			return (1);
		}
		information->error_number = _err_atoi(information->argv[1]);
		return (-2);
	}
	infomation->error_number = -1;
	return (-2);
}
/**
 * _help - function to call help
 * @information: pointer paramter
 *
 * Return: integer
 */
int _help(info_t *information)
{
	char *arg;

	arg = information->argv;
	_puts("function not implemented\n");
	if (0)
		_puts(*arg);
	return (0);
}
/**
 * _history - function to display history
 * @information: pointer parameter
 *
 * Return: integer
 */
int _history(info_t *information)
{
	print_list(information->history);
	return (0);
}
/**
 * _alias - function for alias builtin
 * @information: pointer parameter
 *
 * Return: integer
 */
int _alias(info_t *information)
{
	int i;
	char *c;
	list_t *j;

	i = 0;
	c = NULL;
	j = NULL;
	if (information->argc == 1)
	{
		j = information->alias;
		while (j)
		{
			printAlias(j);
			j = j->next;
		}
		return (0);
	}
	for (i = 1; information->argv[i]; i++)
	{
		c = _strchr(information->(char)argv[i], '=');
		if (c)
			alias_set(information, information->argv(char)[i]);
		else
			printAlias(node_starts_with(information->alias, information->argv[i], '='));
	}
	return (0);
}
