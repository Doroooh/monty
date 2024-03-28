#include "custom_monty.h" // Assuming monty.h can have an alternative name

/**
 * performModulus - Calculates the modulus of the second top element by the top
 * element of the stack and updates the stack accordingly.
 * @stackPointer: Pointer to the top of the stack.
 * @scriptLine: Line number in the Monty bytecode script for error reporting.
 * 
 * This operation requires at least two elements in the stack, and the top
 * element must not be zero (to avoid division by zero errors).
 */
void performModulus(stack_t **stackPointer, unsigned int scriptLine)
{
    stack_t *current;
    int elementCount = 0, result;

    // Traverse the stack to count the elements
    for (current = *stackPointer; current != NULL; current = current->next) {
        elementCount++;
    }

    // Verify the stack is sufficiently large
    if (elementCount < 2) {
        fprintf(stderr, "L%d: can't mod, stack too short\n", scriptLine);
        cleanAndExit();
    }

    // Ensure the top element is not zero to prevent division by zero
    if ((*stackPointer)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", scriptLine);
        cleanAndExit();
    }

    // Compute the modulus and update the stack
    result = (*stackPointer)->next->n % (*stackPointer)->n;
    stack_t *nodeToFree = *stackPointer; // Keep reference to the node to free
    *stackPointer = (*stackPointer)->next; // Move head to the next node
    (*stackPointer)->n = result; // Update the value with modulus result

    free(nodeToFree); // Free the old top of the stack
}

/**
 * cleanAndExit - Cleans resources and exits due to an error.
 * 
 * This function centralizes cleanup operations for file resources, 
 * dynamically allocated memory, and the stack to ensure a graceful exit 
 * in the face of errors. Designed to avoid code duplication.
 */
void cleanAndExit() {
    fclose(bus.file); // Assuming 'bus' is accessible here
    free(bus.content);
    free_stack(*stackPointer); // Adjust based on actual scope and access to 'stackPointer'
    exit(EXIT_FAILURE);
}
