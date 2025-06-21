#pragma once
#define STACK_SIZE 10000

typedef char* elementType;

typedef struct {
	int top;
	elementType data[STACK_SIZE];
} stackType;

typedef struct stackNode {
	elementType data;
	struct stackNode* link;
} stackNode;

// extern elementType stack[STACK_SIZE] // stack.c에 선언

// Array Stack
extern stackType* ACreateStack();
extern void ADestroyStack(stackType* stack);
extern void APush(stackType* stack, elementType item);
extern elementType APop(stackType* stack);
// initStack은 개인이 구현해볼 것
extern int AIsEmpty(stackType* stack);
extern int AIsFull(stackType* stack);
extern void APrintStack(stackType* stack);

// Linked List Stack
extern stackNode* topNode;
extern void LCreateStack();
extern void LDestroyStack();
extern void LPush(elementType item);
extern elementType LPop();
extern int LIsEmpty();
extern int LIsFull();
extern void LPrintStack();