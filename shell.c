#include "Alpha.h"
/**
 * hsh - function for shell loop
 * @information: parameter pointer
 * @av: pointer tompointer parametre
 *
 * Return: integer
 */
int hsh(info_t *information, char **av)
{
	ssize_t i;
	int built_in;

	i = 0;
	built_in = 0;
	while (i != -1 && built_in != -2)
	{
		clear_information(information);
	if (interact(information))
		_puts("$ ");
	err_putchar(BUFFER_FLUSH);
	i = get_input(information);
	if (i != -1)
	{
		info_set(information, av);
		built_in = find_builtin(information);
		if (built_in == -1)
			find_command(information);
	}
	else if (_interact(information))
		_putchar('\n');
	free_information(information, 0);
	}
	wr_hist(information);
	free_information(information, 1);
	if (!interact(information) && information->stat)
		exit(information->stat);
	if (built_in == -2)
	{
		if (information->error_number == -1)
			exit(information->stat);
	exit(information->error_number);
	}
	return (built_in);
}
/**
 * find_builtin - function to find builtin
 * @information: parameter
 *
 * Return: integer
 */
int find_builtin(info_t *information)
{
	int i, built_in;

	built_in = -1;
	builtin_tab builtintable[] = {
		{"exit", __exit},
		{"help", _help},
		{"history", _history},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};
	for (i = 0; builtintable[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			information->count++;
			built_in = builtintable[i].func(information);
			break;
		}
	return (built_in);
}
/**
 * find_command - function to find command
 * @information: pointer parameter
 *
 * Return: void
 */
void find_command(info_t *information)
{
	char *path;
	int i, j;

	path = NULL;
	information->path = information->argv[0];
	if (information->count_flag == 1)
	{
	information->count++;
	information->count_flag = 0;
	}
	for (i = 0, j = 0; information->argv[i]; i++)
	if (!_delimiter(information->argv[i], " \t\n"))
		j++;
	if (!j)
		return;
	path = find_path(information, get_env(information, "PATH="), information->argv(char)[0]);
	if (path)
	{
	information->path = path;
	fork_command(information);
	}
	else
	{
		if ((interact(information) || get_env(information, "PATH=")
			|| information->argv[0] == '/') && _cmd(information, information->argv(char)[0]))
				fork_command(information);
		else if (*(information->argument) != '\n')
		{
			information->stat = 127;
			print_err(info, "not found\n");
		}
	}
}
/**
 * fork_command - function to fork
 * @information: pointer parameter
 *
 * Return: void
 */
void fork_command(info_t *information)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(information->path, information->(char *)argv, get_env(information)) == -1)
		{
		free_information(information, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(information->stat));
		if (WIFEXITED(information->stat))
		{
			information->stat = WEXITSTATUS(information->stat);
				if (info->status == 126)
					print_err(information, "Permission declined\n");
		}
	}
}
