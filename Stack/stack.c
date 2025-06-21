#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

elementType stack[STACK_SIZE];

// Array Stack
stackType* ACreateStack() {
	stackType* s = (stackType*)malloc(sizeof(stackType));
	s->top = -1;
	return s;
}

void ADestroyStack(stackType* stack) {
	free(stack);
}

void APush(stackType* stack, elementType item) {
	if (!AIsFull(stack))
		stack->data[++(stack->top)] = item;
	else
		fprintf(stderr, "Stack is Full\n");
}

elementType APop(stackType* stack) {
	elementType r = stack->data[stack->top];
	if (!AIsEmpty(stack)) {
		stack->top--;
		return r;
	}
	else {
		fprintf(stderr, "Stack is empty\n");
		return 0;
	}
}

int AIsEmpty(stackType* stack) {
	return (stack->top == -1);
}

int AIsFull(stackType* stack) {
	return (stack->top == (STACK_SIZE - 1));
}

void APrintStack(stackType* stack) {
	printf("Stack: ");
	for (int i = 0; i <= stack->top; i++) {
		printf("[%02d]{%2d}", i, stack->data[i]);
	}
	printf("\n");
}


// Linked List Stack
stackNode* topNode;

void LCreateStack() {
	topNode = (stackNode*)NULL;
}

void LDestroyStack() {
	if (topNode != (stackNode*)NULL) {
		stackNode* s = topNode->link;
		while (s != (stackNode*)NULL) {
			free(topNode);
			topNode = s;
			s = topNode->link;
		}
		free(topNode);
		topNode = (stackNode*)NULL;
	}
}

void LPush(elementType item) {
	stackNode* n = (stackNode*)malloc(sizeof(stackNode));
	n->data = item;
	n->link = topNode;
	topNode = n;
}

elementType LPop() {
	if (!LIsEmpty()) {
		elementType r = topNode->data;
		stackNode* n = topNode->link;
		free(topNode);
		topNode = n;

		return r;
	}
	else {
		fprintf(stderr, "Stack is Empty\n");
		return -1;
	}
}

int LIsEmpty() {
	return (topNode == (stackNode*)NULL);
}

int LIsFull() {
	return 0;
}

void LPrintStack() {
	stackNode* n = topNode;

	printf("Stack: ");
	while (n != (stackNode*)NULL) {
		printf("{%2d}", n->data);
		n = n->link;
	}
	printf("\n");
}