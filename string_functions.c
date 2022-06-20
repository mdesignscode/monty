#include "monty.h"

/**
 * create_opcodes - creates a pointer to an array of strings
 * containing the opcodes.
 *
 * Return: a pointer to an array of strings.
 */
char **create_opcodes(void)
{
	char **string_of_opcodes;

	string_of_opcodes = malloc(sizeof(char *) * 8);
	if (!string_of_opcodes)
		return (NULL);

	string_of_opcodes[0] = "push";
	string_of_opcodes[1] = "pint";
	string_of_opcodes[2] = "pall";
	string_of_opcodes[3] = "pop";
	string_of_opcodes[4] = "swap";
	string_of_opcodes[5] = "add";
	string_of_opcodes[6] = "nop";
	string_of_opcodes[7] = NULL;

	return (string_of_opcodes);
}

/**
 * isNumber - checks if input is a number.
 * @number: a character pointer to the number to be checked.
 *
 * Return: 0 if not a number, 1 if is a number.
 */
int isNumber(char *number)
{
	int i;

	for (i = 0; number[i]; i++)
	{
		if (number[i] == '-')
			continue;

		if (!isdigit(number[i]))
			return (0);
	}
	return (1);
}

/**
 * is_in_array - checks if a string is in an array of strings.
 * @needle: string to be searched for.
 * @haystack: an array of strings.
 *
 * Return: 1 if string found, 0 if not.
 */
int is_in_array(char *needle, char **haystack)
{
	int i = 0;

	for (i = 0; haystack[i]; i++)
	{
		if (!strcmp(haystack[i], needle))
			return (1);
	}
	return (0);
}

/**
 * is_string_white - checks if a string is only whitespace.
 * @s: string to be checked.
 *
 * Return: 0 if a nonwhitespace character is found, else 1.
 */
int is_string_white(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!isspace(s[i]))
			return (0);
	}
	return (1);
}
