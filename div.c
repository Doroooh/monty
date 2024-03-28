#include "monty_lib.h" // Changed include to reflect a unique name

/**
 * divideStackTop - Performs division on the top two elements of the stack.
 * @stackTop: Reference to the top of the stack
 * @lineNo: Current line number in the script for error messaging
 * 
 * This function divides the second top element of the stack by the top element.
 * It requires at least two elements in the stack to work, and division by zero is not permitted.
 */
void divideStackTop(stack_t **stackTop, unsigned int lineNo)
{
    stack_t *tempNode;
    int stackDepth = 0;

    // Calculate the stack's depth
    for (tempNode = *stackTop; tempNode != NULL; tempNode = tempNode->next) {
        stackDepth++;
    }

    // Ensure there are at least two elements in the stack
    if (stackDepth < 2) {
        fprintf(stderr, "L%d: can't div, stack too short\n", lineNo);
        exitWithError();
    }

    // Check for division by zero
    if ((*stackTop)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", lineNo);
        exitWithError();
    }

    // Perform the division
    int divisionResult = (*stackTop)->next->n / (*stackTop)->n;
    stack_t *nodeToRemove = *stackTop;
    (*stackTop)->next->n = divisionResult; // Store result in the next node
    *stackTop = (*stackTop)->next; // Move the head pointer to the next node

    free(nodeToRemove); // Free the original top node
}

/**
 * exitWithError - Handles cleanup and exits on error.
 * 
 * This function centralizes the error handling code, performing cleanup
 * tasks common to error scenarios, then exiting with failure status.
 */
void exitWithError() {
    fclose(bus.file);
    free(bus.content);
    free_stack(*stackTop); // Assuming stackTop is globally accessible or passed appropriately
    exit(EXIT_FAILURE);
}
