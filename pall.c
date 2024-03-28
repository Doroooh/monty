#include "monty_lib.h" // Assuming monty.h can be variably named for uniqueness

/**
 * printStack - Outputs the elements of the stack sequentially
 * @top: Pointer to the top of the stack
 * @lineNum: Line number in script, not utilized in this function
 * 
 * This function traverses from the top of the stack to its base, printing
 * each element's value. The traversal continues as long as there are elements.
 */
void printStack(stack_t **top, unsigned int lineNum)
{
    stack_t *currentElement;
    // Explicitly marking unused parameters to enhance readability and compliance
    (void)lineNum;

    currentElement = *top; // Initialize currentElement with the top of the stack
    // Loop continues as long as 'currentElement' is not null, indicating the end of the stack
    while (currentElement != NULL)
    {
        printf("%d\n", currentElement->n); // Print current element's value
        currentElement = currentElement->next; // Move to the next element
    }
    // Function concludes without a return statement as it returns void
}
