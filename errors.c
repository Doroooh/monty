#include "monty.h"

void handleError(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNumber;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			lineNumber = va_arg(args, int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void handleAdditionalErrors(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNumber;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			lineNumber = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void handleStringErrors(int errorCode, ...)
{
	va_list args;
	int lineNumber;

	va_start(args, errorCode);
	lineNumber = va_arg(args, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
