#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int check_breace(char* ex) {
	stackType* mystack;
	char* cptr = ex;

	mystack = ACreateStack();

	while (*cptr != '\0') {
		switch (*cptr) {
		case '(' :
			APush(mystack, *cptr);
			break;
		case ')' :
			APop(mystack);
			break;
		default:
			break;
		}
		cptr++;
	}
	if (AIsEmpty(mystack))
		printf("Correct!!!\n");
	else
		printf("Error!!!\n");
}

char* infix_to_postfix(char* expr) {
	stackType* mystack;
	mystack = ACreateStack();

	char* postfix = (char*)malloc(strlen(expr) + 1);
	char* cptr = postfix;
	
	while (*expr != '\0') {
		switch (*expr) {
		case '*' :
		case '+' :
		case '-' :
		case '/' :
			APush(mystack, *expr);
			expr++;
			break;
		case ')' :
			*cptr = *expr;
			cptr++;
			*cptr = APop(mystack);
			expr++;
			cptr++;
			break;
		default:
			*cptr++ = *expr++;
			break;
		}
	}
	*cptr = '\0';
	return postfix;
	ADestroyStack(mystack);
}

int eval_postfix(char* postfix) {
	int opr1, opr2, value;
	int i = 0;
	int length = strlen(postfix);
	char symbol;

	stackType* mystack;
	mystack = ACreateStack();

	for (i = 0; i < length; i++) {
		APrintStack(mystack);
		printf("\n");

		symbol = postfix[i];
		switch (symbol) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			APush(mystack, symbol);
			break;
		case '*':
			opr1 = (int)APop(mystack) - '0';
			opr2 = (int)APop(mystack) - '0';
			value = opr2 * opr1;
			APush(mystack, (elementType)(value + '0'));
			break;
		case '/':
			opr1 = (int)APop(mystack) - '0';
			opr2 = (int)APop(mystack) - '0';
			value = opr2 / opr1;
			APush(mystack, (elementType)(value + '0'));
			break;
		case '+':
			opr1 = (int)APop(mystack) - '0';
			opr2 = (int)APop(mystack) - '0';
			value = opr2 + opr1;
			APush(mystack, (elementType)(value + '0'));
			break;
		case '-':
			opr1 = (int)APop(mystack) - '0';
			opr2 = (int)APop(mystack) - '0';
			value = opr2 - opr1;
			APush(mystack, (elementType)(value + '0'));
			break;
		}
	}

	value = (int)APop(mystack) - '0';
	ADestroyStack(mystack);
	return value;
}

int main() {
	char* expr = "((2+(3*4))-(5*6))";
	char* postfix;
	int r;

	check_breace(expr);
	printf("Infix = %s\n", expr);

	postfix = infix_to_postfix(expr);
	printf("Postfix = %s\n", postfix);

	r = eval_postfix(postfix);
	printf("Evaluation result = %d\n", r);
	
	return 0;
}