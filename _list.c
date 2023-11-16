#include "Alpha.h"
/**
 * list_length - function for length of linked list
 * @a: pointer parameter
 *
 * Return: list
 */
size_t list_length(const list_t *a)
{
	size_t i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
/**
 * list_to_str - function to return strings
 * @begin: pointer parameter
 *
 * Return: string
 */
char **list_to_str(list_t *begin)
{
	list_t *current_node;
	size_t i, j;
	char **strings;
	char *string;

	current_node = begin;
	i = list_length(begin);
	if (!begin || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; current_node; current_node = current_node->next, i++)
	{
		string = malloc(_strlen(current_node->string) + 1);
		if (!string)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}
		string = _strcpy(string,current_ node->string);
		strings[i] = string;
	}
	strings[i] = NULL;
	return (strings);
}
/**
 * print_list - function prints elements of a list
 * @a: pointer parameter
 *
 * Return: list
 */
size_t print_list(const list_t *a)
{
	size_t i;

	i = 0;
	while (a)
	{
		_puts(_atoi(a->number, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(a->string ? a->string : "(nil)");
		_puts("\n");
		a = a->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - function to return node
 * @node: pointer parameter
 * @prefix: pointer parameter
 * @s: parameter
 *
 * Return: list
 */
list_t *node_starts_with(list_t *current_node, char *prefix, char s)
{
	char *c;

	c = NULL;
	while (current_node)
	{
		c = starts_with(current_node->string, prefix);
		if (c && ((s == -1) || (*c == s)))
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

/**
 * get_nodeindex - function to get the index of a node
 * @begin: pointer parameter
 * @current_node: pointer parameter
 *
 * Return: int
 */
ssize_t get_nodeindex(list_t *begin, list_t *current_node)
{
	size_t i;

	i = 0;
	while (begin)
	{
		if (begin == current_node)
			return (i);
		begin = begin->next;
		i++;
	}
	return (-1);
}
