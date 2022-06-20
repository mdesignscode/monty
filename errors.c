#include "monty.h"

/**
 * p_error - print an error message to stderr and exits with code EXIT_FAILURE.
 * @type: type of error to display.
 * @line_number: line number where error occurs.
 * @id: string associated with error.
 *
 * Return: nothing.
 */
void p_error(int type, int line_number, char *id)
{
	switch (type)
	{
	case 1:
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 2:
		dprintf(2, "Error: can't open file %s\n", id);
		exit(EXIT_FAILURE);
	case 3:
		dprintf(2, "L%d: unknown instruction %s\n", line_number, id);
		exit(EXIT_FAILURE);
	case 4:
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case 5:
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	case 6:
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	case 7:
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	case 8:
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	case 9:
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);

	default:
		break;
	}
}
