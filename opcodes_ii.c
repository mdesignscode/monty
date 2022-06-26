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

	new_node->n = ((*stack)->n) + ((*stack)->prev->n);
	new_node->prev = (*stack)->prev->prev;

	*stack = new_node;

	args.count--;
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

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	if (args.count < 2)
		p_errors(SUB, args.index, 0);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	new_node->n = ((*stack)->prev->n) - ((*stack)->n);
	new_node->prev = (*stack)->prev->prev;

	*stack = new_node;

	args.count--;
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void _div(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	if (args.count < 2)
		p_errors(DIV, args.index, 0);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	if (!(*stack)->n)
		p_errors(BYZERO, args.index, 0);

	new_node->n = ((*stack)->prev->n) / ((*stack)->n);
	new_node->prev = (*stack)->prev->prev;

	*stack = new_node;

	args.count--;
}
/**
 * mul - multiplies the top two elements of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void mul(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	if (args.count < 2)
		p_errors(MUL, args.index, 0);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	new_node->n = ((*stack)->n) * ((*stack)->prev->n);
	new_node->prev = (*stack)->prev->prev;

	*stack = new_node;

	args.count--;
}
