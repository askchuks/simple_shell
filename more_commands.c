#include "Alpha.h"
/**
 * alias_set - function to set alias
 * @information: pointer paramter
 * @string: string pointer parameter
 *
 * Return: integer
 */
int alias_set(info_t *information, char *string)
{
	char *c;

	c = _strchr(string, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (alias_unset(information, string));
	alias_unset(information, string);
	return (add_node_2(&(information->alias), string, 0) == NULL);
}
/**
 * alias_unset - function for alias
 * @information: pointer parameter
 * @string: pointer parameter
 *
 * Return: integer
 */
int alias_unset(info_t *information, char *string)
{
	char *c, d;
	int result;

	c = _strchr(string, '=');
	if (!c)
		return (1);
	d = *c;
	*c = 0;
	result = del_node(&(information->alias),
	       get_node(information->alias, start_node(information->alias,
			       string, -1)));
	*c = d;
	return (result);
}
/**
 * alias_printing - alias printing function
 * @node: alias node paramter
 *
 * Return: integer
 */
int alias_printing(list_t *node)
{
	char *c, *d, *string;

	c = NULL;
	d = NULL;
	if (node)
	{
		c = _strchr(node->string, '=');
		for (d = node->string; d <= c; d++)
			_putchar(*c);
		_putchar('\'');
		_puts(c + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
