#include "monty.h"

/**
 * pint - print the top node in a stack
 * @h: head of list
 * @line_num: bytecode line number
 */
void pint(stack_t **h, unsigned int line_num)
{
	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);

}
