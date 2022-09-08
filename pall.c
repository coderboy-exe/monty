#include "monty.h"

/**
 * pall - print all items in a stack
 *
 * @h: head of dlinked_list (bottom of stack)
 * @line_num: bytecode line number
 */
void pall(stack_t **h, unsigned int line_num)
{
	stack_t *node = NULL;
	(void)line_num;

	node = *h;

	if (node == NULL)
		return;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
