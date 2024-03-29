#include "monty.h"

/**
 * err - Printing teh right error messages basing on error codes as under error_code.
 * @error_code: The error codes include: 
 * (1) => No any file or more than one file given to the program.
 * (2) => The file can't be opened or readable.
 * (3) => The file has some invalid instructions.
 * (4) => program is cant malloc more memory.
 * (5) => Parameter passed to the  "push" instruction isn't an int.
 * (6) => Stack empty for pint
 * (7) => Stack empty for pop
 * (8) => stack too short for operations
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
			myfirst_num = va_arg(ag, int);
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
 * more_err - handling the errors
 * @error_code: The error codes are listed as:
 * (6) => Stack empty for pint
 * (7) => Stack empty for pop
 * (8) => Stack too short for any operations.
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
 * string_err - handling errors
 * @error_code: The error codes:
 * (10) ~> The number inside  node outside ASCII bounds.
 * (11) ~> Empty stack
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
