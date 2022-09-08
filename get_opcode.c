#include "monty.h"

/**
 * get_opcode - choose correct operation function
 *
 * @tok1: first bytecode input (opcode)
 *
 * Return: pointer to the correct op code
 */

void (*get_opcode(char *tok1))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;

	while(instruction_s[i].f != NULL)
	{
		if (strcmp(tok1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
