#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct error {
    int code;
    char *message;
    int needs_var;
} error_t;

const error_t errors[] = {
    {1, "USAGE: monty file\n", 0},
    {2, "Error: Can't open file %s\n", 1},
    {3, "L%d: unknown instruction %s\n", 2},
    {4, "Error: malloc failed\n", 0},
    {5, "L%d: usage: push integer\n", 1},
    {6, "L%d: can't pint, stack empty\n", 1},
    {7, "L%d: can't pop an empty stack\n", 1},
    {8, "L%d: can't %s, stack too short\n", 2},
    {9, "L%d: division by zero\n", 1},
    {10, "L%d: can't pchar, value out of range\n", 1},
    {11, "L%d: can't pchar, stack empty\n", 1},
    {0, NULL, 0} // Terminator
};

void handle_error(int error_code, ...) {
    va_list args;
    va_start(args, error_code);

    for (int i = 0; errors[i].message != NULL; i++) {
        if (errors[i].code == error_code) {
            if (errors[i].needs_var == 1) {
                int line_number = va_arg(args, int);
                fprintf(stderr, errors[i].message, line_number);
            } else if (errors[i].needs_var == 2) {
                int line_number = va_arg(args, int);
                char *op = va_arg(args, char *);
                fprintf(stderr, errors[i].message, line_number, op);
            } else {
                fprintf(stderr, "%s", errors[i].message);
            }
            break;
        }
    }

    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}
