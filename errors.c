#include "monty.h"

/**
 * err - this prints the appropriate error messages as the error determines.
 * @error_code: The below error codes are whats expected:
 * (1) => There isn't any file or more than one file to the program.
 * (2) => There is a provided file but its not readable or can be opened.
 * (3) => There is a file that has an invalid instruction.
 * (4) => This is when my program is having a challenge for the malloc of more memoryy.
 * (5) => When there is a  parameter passed to the instruction "push" is not an int.
 * (6) => The stack it empty for pint.
 * (7) => The stack it empty for pop.
 * (8) => The stack is too short for operations.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int firstl_num;

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
			firstl_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", firstl_num, op);
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
 * @error_code: The error codes are:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When stack is very short for operations.
 * (9) => Dividing by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int firstl_num;

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
			firstl_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", firstl_num, op);
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
 * (10) ~> The number inside the node is outside the ASCII bound.
 * (11) ~> Empty stack.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int firstl_num;

	va_start(ag, error_code);
	firstl_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", firstl_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", firstl_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
