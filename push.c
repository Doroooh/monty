#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;

    if (!stack) {
        fprintf(stderr, "L%d: Stack not initialized\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(bus.arg); // Assuming bus.arg is your integer argument as a string
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void f_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number; // Unused parameter

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
