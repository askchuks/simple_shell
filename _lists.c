#include "Alpha.h"
/**
 * add_node - function to add node
 * @begin: pointer to pointer parameter
 * @string: pointer parameter
 * @number: parameter
 *
 * Return: list
 */
list_t *add_node(list_t **begin, const char *string, int number)
{
	list_t *head;

	if (!begin)
		return (NULL);
	head = malloc(sizeof(list_t));
	if (!head)
		return (NULL);
	_memset((void *)head, 0, sizeof(list_t));
	head->number = number;
	if (string)
	{
		head->string = _strdup(string);
		if (!head->string)
		{
			free(head);
			return (NULL);
		}
	}
	head->next = *begin;
	*begin = head;
	return (head);
}

/**
 * add_node_last - function to add node
 * @begin: pointer to pointer parameter
 * @string: pointer parameter
 * @number: parameter
 *
 * Return: list
 */
list_t *add_node2(list_t **begin, const char *string, int number)
{
	list_t *new_node, *current_node;

	if (!begin)
		return (NULL);

	current_node = *begin;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->number = number;
	if (string)
	{
		new_node->string = _strdup(string);
		if (!new_node->string)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	else
		*begin = new_node;
	return (new_node);
}

/**
 * print_list_string - function to print list
 * @a: pointer parameter
 *
 * Return: int
 */
size_t print_list(const list_t *a)
{
	size_t i;

	i = 0;
	while (a)
	{
		_puts(a->string ? a->string : "(nil)");
		_puts("\n");
		a = a->next;
		i++;
	}
	return (i);
}

/**
 * del_node_index - function to delete node
 * @head: pointer of pointer parameter
 * @index: parameter
 *
 * Return: integer
 */
int del_node(list_t **begin, unsigned int index)
{
	list_t *current_node, *previous_node;
	unsigned int i;

	i = 0;
	if (!begin || !*begin)
		return (0);

	if (!index)
	{
		current_node = *begin;
		*begin = (*begin)->next;
		free(current_node->string);
		free(current_node);
		return (1);
	}
	current_node = *begin;
	while (current_node)
	{
		if (i == index)
		{
			previous_node->next = current_node->next;
			free(current_node->string);
			free(current_node);
			return (1);
		}
		i++;
		previous_node = current_node;
		current_node = current_node->next;
	}
	return (0);
}

/**
 * free_list - function to free list
 * @head_pointer: pointer parameter
 *
 * Return: nothing
 */
void free_list(list_t **head_pointer)
{
	list_t *current_node, *next_node, *head;

	if (!head_pointer || !*head_pointer)
		return;
	head = *head_pointer;
	current_node = head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node->string);
		free(current_node);
		current_node = next_node;
	}
	*head_pointer = NULL;
}
