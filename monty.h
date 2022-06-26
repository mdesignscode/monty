#ifndef _MONTY_H_
#define _MONTY_H_



/* ------ library headers ------ */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

/* ------ library headers ------ */



/* ------ MACROS ------ */

#define ARG_COUNT 1
#define FILE_OPEN 2
#define INSTRUCTION 3
#define MEMORY 4
#define PUSH 5
#define PINT 6
#define POP 7
#define SWAP 8
#define ADD 9
#define SUB 10
#define DIV 11
#define MUL 12
#define MOD 13
#define PCHAR1 14
#define PCHAR2 15
#define BYZERO 16

/* ------ MACROS ------ */



/* ------ data structures ------ */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - structure containing variables to be used by other functions
 * @line_number: line where error occurs, if any.
 * @file: the file to be opened.
 * @token: the arguments int the file.
 * @stack: doubly linked list representation of a stack.
 * @line: the command to give to the opcode.
 * @index: current line.
 * @count: number of elements on the stack.
 * @stack_or_queue: sets the program behavior to LIFO or FIFO.
 * @front: the start of the queue.
 * @back: the end of the queue.
 *
 */
typedef struct args_s
{
        unsigned int line_number;
        FILE *file;
        char *token;
        stack_t **stack;
        char *line;
        int index;
        int count;
        char stack_or_queue;
        stack_t *front;
        stack_t *back;
} args_t;

/* ------ data structures ------ */



/* ------ shared variable ------ */

extern args_t args;

/* ------ shared variable ------ */



/* ------ function prototypes ------ */

void p_error(int type, int line_number, char *id);
void p_errors(int type, int line_number, char *id);
int is_string_white(char *s);
void read_lines(void);
void run_line(void);
ssize_t getline(char **__restrict__ __lineptr, size_t *__restrict__ __n, FILE *__restrict__ __stream);
char **create_opcodes(void);
int dprintf(int __fd, const char *__restrict__ __fmt, ...);
int isascii(int c);
int isNumber(char *number);
int is_in_array(char *needle, char **haystack);
void (*get_opcode(void))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void enqueue(void);
void dequeue(void);

/* ------ function prototypes ------ */

#endif
