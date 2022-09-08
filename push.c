#include "monty.h"

/**
 * check_int - checks if charcter is an integer
 *
 * @int: integer
 *
 * @Return: 0 if int, 1 otherwise
 */
int check_int(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n+i) != '\0'; i++)
	{
		if (isdigit(*(n+i)) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - pushes a new item at the top of the stack
 *
 * @h: head node of the d-linked list (bottom item in the stack)
 * @line_num: bytecode line number
 * @n: item to be added to the stack (integer)
 */

void push(stack_t **h, unsigned int line_num, const char *n)
{
	if (check_int(n) == 1)
	{
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_new_node(h, atoi(n)) == 1)
		{
			exit(EXIT_FAILURE);
		}
	}
}
