#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Array Stack은 스택을 여러개 만들어서 사용할 수 있다.
// Linked List Stack은 스택을 하나밖에 만들지 못한다.
// 이 문제를 해결하기 위해서 어떻게 해야하나? (더블포인터 사용, linkedList에서 head 선언한 것 처럼 사용(ADT))

int main() {
	stackType* mystack;
	elementType item;
	mystack = ACreateStack();

	// Array Stack
	printf("Array Stack\n");
	APush(mystack, 1);
	APush(mystack, 2);
	APush(mystack, 3);
	APush(mystack, 4);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);
	
	ADestroyStack(mystack);

	// Linked List Stack
	printf("\nLinked List Stack\n");
	LCreateStack();
	LPush(1);
	LPush(2);
	LPush(3);
	LPush(4);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	LDestroyStack();
	return 0;
}