#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	if (args.count < 2)
		p_error(ADD, args.index, 0);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	new_node->n = ((*stack)->n) + ((*stack)->next->n);
	new_node->next = (*stack)->next->next;

	*stack = new_node;
}

/**
 * nop - doesn’t do anything.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
