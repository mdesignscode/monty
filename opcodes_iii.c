#include "monty.h"


/**
 * mod -  computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void mod(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	if (args.count < 2)
		p_errors(MOD, args.index, 0);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	if (!(*stack)->n)
		p_errors(BYZERO, args.index, 0);

	new_node->n = ((*stack)->prev->n) % ((*stack)->n);
	new_node->prev = (*stack)->prev->prev;

	*stack = new_node;

	args.count--;
}

/**
 * pchar - prints the char at the top of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void pchar(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (!isascii((*stack)->n))
		p_errors(PCHAR1, args.index, 0);

	if (!*stack)
		p_errors(PCHAR2, args.index, 0);

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: doubly linked list.
 * @line_number: current line number.
 *
 * Return: nothing.
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;

	if (!*stack)
		printf("\n");

	while (temp)
	{
		if (!isascii(temp->n))
			p_errors(PCHAR1, args.index, 0);
		if (!temp->n)
			exit(EXIT_FAILURE);
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}


/**
 * enqueue - adds an element to the queue.
 *
 * Return: nothing.
 */
void enqueue(void)
{
	stack_t *new_node;
	int n;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(MEMORY, 0, 0);

	n = atoi(args.line);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!args.count)
	{
		args.back = args.front = new_node;
	}
	else
	{
		args.back->prev = new_node;
		args.back->prev->next = args.back;
		args.back = new_node;
	}

	*args.stack = args.front;

	args.count++;
}

/**
 * dequeue - removes an element from the queue.
 *
 * Return: nothing.
 */
void dequeue(void)
{
	stack_t *front;

	front = args.front;

	args.front = front->prev;

	args.front->next = NULL;
	free(front);
	front = NULL;

	args.count--;
}
