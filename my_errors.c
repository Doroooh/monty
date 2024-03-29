#include "monty.h"

/**
 * err - Printing the appropriate error messages that is determined by the error code.
 * @error_code: error codes are as:
 * (1) => User hasn’t given the program any file or more than one file.
 * (2) => File  provided isn’t an openable or readable file.
 * (3) => The provided file has invalid instruction.
 * (4) => program can’t malloc more memory.
 * (5) => Parameter passed to the instruction "push" isn’t an int (integer).
 * (6) => The stack it empty for pint.
 * (7) => Stack empty for pop.
 * (8) => Stack too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int myfirst_num;

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
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", myfirst_num, op);
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
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for operation.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int myfirst_num;

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
			myfirst_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", myfirst_num, op);
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
 * string_err - handling errors.
 * @error_code: Error codes are:
 * (10) ~> The number inside the node is outside ASCII bounds.
 * (11) ~> Stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int myfirst_num;

	va_start(ag, error_code);
	myfirst_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", myfirst_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", myfirst_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
