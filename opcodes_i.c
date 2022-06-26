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

	(void)stack;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);
	if (!isNumber(args.line) || !args.line)
		p_error(PUSH, args.index, 0);

	if (args.stack_or_queue == 'q')
	{
		enqueue();
		return;
	}

	n = atoi(args.line);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!args.count)
		args.front = args.back = new_node;

	else
	{
		args.front->next = new_node;
		args.front = new_node;
		args.front->prev = *args.stack;
		args.front->next = NULL;
	}

	*args.stack = args.front;
	args.count++;
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

	(void)stack;
	top = *stack;

	while (top)
	{
		printf("%d\n", top->n);

		top = top->prev;
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
	stack_t *popped __attribute__((unused));

	if (!*stack)
		p_error(POP, args.index, 0);

	if (args.stack_or_queue == 'q')
	{
		dequeue();
		return;
	}
	*args.stack = args.front->prev;

	popped = args.front;

	args.front = popped->prev;

	free(popped);
	popped = NULL;

	args.count--;
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

	*stack = (*stack)->prev;

	top->prev = (*stack)->prev;

	(*stack)->prev = top;

	args.count--;
}
