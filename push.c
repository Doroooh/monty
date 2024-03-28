#include "monty.h"

/**
 * is_valid_number - checks if a string is a valid integer
 * @str: string to check
 *
 * Return: 1 if string is a valid integer, 0 otherwise
 */
static int is_valid_number(char *str)
{
    if (*str == '-' || *str == '+') {
        str++;
    }

    if (!*str) {
        return 0; // String is only a sign
    }

    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0; // Non-digit character found
        }
        str++;
    }

    return 1;
}

/**
 * f_push - Adds a node to the stack or queue.
 * @head: double pointer to the top of the stack
 * @counter: line number in the file
 */
void f_push(stack_t **head, unsigned int counter)
{
    if (!bus.arg || !is_valid_number(bus.arg)) {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    int num = atoi(bus.arg);

    if (bus.lifi == 0) {
        addnode(head, num);
    } else {
        addqueue(head, num);
    }
}
