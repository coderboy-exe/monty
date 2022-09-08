#include "monty.h"

/**
 * add_new_node - add new node to dlinked_list (top of stack)
 *
 * @h: pointer to head node
 * @n: node data
 *
 * Return: 0 on success, -1 otherwise
 */
int add_new_node(stack_t **h, int n)
{
	stack_t *node;

	if (!h)
		return (-1);

	node = malloc(sizeof(stack_t));

	if (!node)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	node->n = n;

	if (*h == NULL)
	{
		*h = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = *h;
		(*h)->prev = node;
		*h = node;
	}

	return (0);
}
