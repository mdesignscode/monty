The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$


__OPCODES__ :

push - pushes an element onto the stack. Usage: push integer

pall - prints all alements on the stack.

pint - prints the top element on the stack.

add - adds the first and second elements and sets the result as the new top of the stack.

swap - swaps the first and second elements on the stack.

pop - removes the top element from the stack.

nop - does nothing.

sub - subtracts the top element of the stack from the second top element of the stack.

div - divides the second top element of the stack by the top element of the stack.

mul - multiplies the second top element of the stack with the top element of the stack.

mod - computes the rest of the division of the second top element of the stack by the top element of the stack.

pchar - prints the char at the top of the stack, followed by a new line.

pstr - prints the string starting at the top of the stack, followed by a new line.

rotl - rotates the stack to the top.

rotr rotates the stack to the bottom.

stack - sets the format of the data to a stack (LIFO). This is the default behavior of the program.

queue - sets the format of the data to a queue (FIFO).

Comments are denoted by #

__USAGE__: monty file
