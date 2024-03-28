#include "monty.h"

/**
 * error_cleanup - Handles cleanup and error messaging
 * @head: stack head
 * @counter: line_number
 */
void error_cleanup(stack_t **head, unsigned int counter) {
    fprintf(stderr, "L%d: usage: push integer\n", counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * is_valid_number - Checks if a string is a valid integer
 * @str: The string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_number(char *str) {
    if (*str == '-') { // Skip leading minus if present
        str++;
    }

    if (!*str) { // If only a minus sign, it's not valid
        return 0;
    }

    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return 0; // Found a non-digit character
        }
        str++;
    }

    return 1; // Only digits (and possibly a leading minus), so it's valid
}

/**
 * f_push - Add a node to the stack or queue
 * @head: stack head
 * @counter: line number
 */
void f_push(stack_t **head, unsigned int counter) {
    int n;

    // Check for a valid argument and if it's a valid integer
    if (!bus.arg || !is_valid_number(bus.arg)) {
        error_cleanup(head, counter);
    }

    n = atoi(bus.arg);

    // Depending on the mode, add to stack or queue
    if (bus.lifi == 0) {
        addnode(head, n);
    } else {
        addqueue(head, n);
    }
}
