#include "monty.h"

/**
 * read_lines - interprets a bytescode file line by line.
 *
 * Return: nothing.
 */
void read_lines(void)
{
	int is_in;
	char buffer[120], **opcodes;

	args.count = 0;
	opcodes = create_opcodes();
	args.index = 1;
	args.stack_or_queue = 's';

	while (fgets(buffer, sizeof(buffer), args.file))
	{
		args.token = strtok(buffer, " \n");
		if (!args.token || *args.token == '#' || is_string_white(buffer))
		{
			args.index++;
			continue;
		}
		is_in = is_in_array(args.token, opcodes);
		if (!is_in)
		{
			args.line_number = args.index;
			p_error(INSTRUCTION, args.index, args.token);
		}
		args.line = strtok(NULL, " \n");

		if ((!strcmp("push", args.token)) && !args.line)
			p_error(PUSH, args.index, 0);

		run_line();

		++args.index;
	}

	free(opcodes);
	opcodes = NULL;
}

/**
 * run_line - executes bytes line by line.
 *
 * Return: nothing.
 */
void run_line(void)
{
	int i;
	int is_in;
	instruction_t functions[][8] = {
	    {{"push", push}},
	     {{"pall", pall}},
	     {{"pint", pint}},
	     {{"pop", pop}},
	     {{"swap", swap}},
	     {{"add", add}},
	     {{"nop", nop}},
	     {{"sub", sub}},
	     {{"div", _div}},
	     {{"mul", mul}},
	     {{"mod", mod}},
	     {{"pchar", pchar}},
	     {{"pstr", pstr}},
	     {{"rotl", rotl}},
	     {{"rotr", rotr}},
	     {{"stack", stack}},
	     {{"queue", queue}},
	     {{NULL, NULL}}};

	for (i = 0; i < 17; i++)
	{
		is_in = strcmp(args.token, functions[i]->opcode);
		if (!is_in)
			functions[i]->f(args.stack, args.line_number);
	}
}
