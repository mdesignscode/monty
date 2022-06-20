#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;
	int n;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);
	if (!isNumber(args.line) || !args.line)
		p_error(PUSH, args.index, 0);

	n = atoi(args.line);
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * pall - displays all elements on the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top;

	top = *stack;

	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pint - prints the value at the top of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (!(*stack))
		p_error(PINT, args.index, 0);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *popped;

	if (!*stack)
		p_error(POP, args.index, 0);

	popped = *stack;

	*stack = (*stack)->next;

	free(popped);
}


/**
 * swap - swaps the top two elements of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top;

	if (args.count < 2)
		p_error(SWAP, args.index, 0);

	top = *stack;

	*stack = (*stack)->next;

	top->next = (*stack)->next;

	(*stack)->next = top;

}
