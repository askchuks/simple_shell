#include "shellMain.h"
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
