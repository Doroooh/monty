#include "monty.h"

/**
 * err - this Prints out the appropiate error messages determined by the respective error code.
 * @error_code: The error codes included are as:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_number = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handling errors.
 * @error_code:Eerror codes are:
 * (6) => Occurs When the stack is empty for pint.
 * (7) => Occurs When the stack is empty for pop.
 * (8) =>Occurs When the stack is too short for operation.
 * (9) => Division of the value  by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_number = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handling the errors.
 * @error_code: The error codes are:
 * (10) ~> The number inside a node is outside the  ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_number;

	va_start(ag, error_code);
	l_number = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
