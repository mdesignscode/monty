#include "monty.h"

args_t args;

/**
 * main - main function.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		p_error(ARG_COUNT, 0, 0);

	args.file = fopen(argv[1], "r");
	if (!args.file)
		p_error(FILE_OPEN, 0, argv[1]);

	args.stack = malloc(sizeof(stack_t));
	if (!args.stack)
		return (-1);

	args.front = (stack_t *)args.stack;

	read_lines();

	free(args.stack);
	args.stack = NULL;

	return (0);
}
