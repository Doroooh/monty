#include "monty.h"

void fileOpen(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
		errorHandler(2, fileName);

	fileRead(fileDescriptor);
	fclose(fileDescriptor);
}

void fileRead(FILE *fileDescriptor)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNumber = 1; getline(&buffer, &len, fileDescriptor) != -1; lineNumber++)
	{
		format = lineParse(buffer, lineNumber, format);
	}
	free(buffer);
}

int lineParse(char *buffer, int lineNumber, int format)
{
	char *operationCode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		errorHandler(4);

	operationCode = strtok(buffer, delimiter);
	if (operationCode == NULL)
		return (format);
	value = strtok(NULL, delimiter);

	if (strcmp(operationCode, "stack") == 0)
		return (0);
	if (strcmp(operationCode, "queue") == 0)
		return (1);

	functionFind(operationCode, value, lineNumber, format);
	return (format);
}

void functionFind(char *operationCode, char *value, int lineNumber, int format)
{
	int i;
	int flag;

	instruction_t functionList[] = {
		{"push", stackAdd},
		{"pall", stackPrint},
		{"pint", topPrint},
		{"pop", topPop},
		{"nop", nop},
		{"swap", nodesSwap},
		{"add", nodesAdd},
		{"sub", nodesSub},
		{"div", nodesDiv},
		{"mul", nodesMul},
		{"mod", nodesMod},
		{"pchar", charPrint},
		{"pstr", strPrint},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (operationCode[0] == '#')
		return;

	for (flag = 1, i = 0; functionList[i].operationCode != NULL; i++)
	{
		if (strcmp(operationCode, functionList[i].operationCode) == 0)
		{
			functionCall(functionList[i].f, operationCode, value, lineNumber, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errorHandler(3, lineNumber, operationCode);
}

void functionCall(op_func func, char *op, char *val, int lineNumber, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errorHandler(5, lineNumber);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorHandler(5, lineNumber);
		}
		node = nodeCreate(atoi(val) * flag);
		if (format == 0)
			func(&node, lineNumber);
		if (format == 1)
			queueAdd(&node, lineNumber);
	}
	else
		func(&head, lineNumber);
}
