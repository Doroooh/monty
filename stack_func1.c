#include "monty.h"

void stackAddition(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tempNode;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tempNode = head;
	head = *newNode;
	head->next = tempNode;
	tempNode->prev = head;
}

void stackPrint(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tempNode;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tempNode = *stack;
	while (tempNode != NULL)
	{
		printf("%d\n", tempNode->n);
		tempNode = tempNode->next;
	}
}

void topPop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL)
		more_err(7, lineNumber);

	tempNode = *stack;
	*stack = tempNode->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tempNode);
}

void topPrint(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
