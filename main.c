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
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);

	close(fd);
	return (0);
}
