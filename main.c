#include "monty.h"

/*
 * main - main funcion (entry into interpreter)
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: Always 0 (On success)
 */

int main(int argc, char *argv[])
{
	int fd, is_push = 0;
	char *buf, *toks;
	unsigned int line = 1;
	ssize_t n_read;
	stack_t *h = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buf = malloc(sizeof(char) * 10000);
	if (!buf)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	n_read = read(fd, buf, 10000);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		exit(EXIT_FAILURE);
	}

	toks = strtok(buf, "\n\t\a\r :;");

	while (toks)
	{
		if (is_push == 1)
		{
			push(&h, line, toks);
			is_push = 0;
			toks = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(toks, "push") == 0)
		{
			is_push = 1;
			toks = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_opcode(toks) != 0)
			{
				get_opcode(toks)(&h, line);
			}
			else
			{
				free_dlinked_list(&h);
				printf("L%d: unknown instruction %s\n", line, toks);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		toks = strtok(NULL, "\n\t\a\r ;:");
	}

	free_dlinked_list(&h); free(buf);

	close(fd);
	return (0);
}
