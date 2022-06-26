#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *temp;

	top = temp = *stack;

	*stack = (*stack)->prev;

	while (temp->prev)
		temp = temp->prev;

	temp->prev = top;
	top->prev = temp;

	top->prev = NULL;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last, *temp;

	temp = *stack;

	while (temp->prev->prev)
		temp = temp->prev;

	last = temp->prev;
	last->prev = NULL;

	temp->prev = NULL;

	last->prev = (*stack);

	*stack = last;
}

/**
 * stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void stack(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	(void)stack;
	args.stack_or_queue = 's';
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void queue(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	(void)stack;
	args.stack_or_queue = 'q';
}
