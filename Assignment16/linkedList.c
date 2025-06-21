#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "linkedList.h"

linkedList_h* createCLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->tail = (listNode*)NULL;
	lptr->follow = 0;

	return lptr;
}

void destroyCLinkedList(linkedList_h* L) {
	if (L->head == NULL) {
		free(L);
		return;
	}

	if (L->head->link != L->head) {
		listNode* me = L->head->link;
		listNode* next;

		while (me != L->head) {
			next = me->link;
			free(me);
			me = next;
		}
	}
	free(L->head);
	free(L);
}

void printMenu() {
	printf("=======  Linked_list Menu  =======\n");
	printf("1) insertFirst    (리스트의 제일 앞에 삽입)\n");
	printf("2) insertLast     (리스트의 제일 뒤에 삽입)\n");
	printf("3) insertMiddle   (특정 값 뒤에 삽입)\n");
	printf("4) insertNthNode  (N번째 위치 삽입)\n");
	printf("6) deleteNode     (특정 값 삭제)\n");
	printf("7) print Head/Tail\n");
	printf("0) Program Stop\n");
	printf("Select menu ▶ ");
}

void printCList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	if (lptr == NULL) {
		printf("\n");
		return;
	}

	while (lptr != L->tail) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");
}

void printHeadTail(linkedList_h* L) {
	if (L->head == (listNode*)NULL)
		printf("Head/Tail ▶ 리스트가 비어 있습니다.\n");
	else
		printf("Head ▶ [%d]   Tail ▶ [%d]\n", L->head->data, L->tail->data);
}

void insertFirstCNode(linkedList_h* L) {
	listNode* newNode;
	elementType item;

	// 입력
	printf("    삽입할 값: ");
	scanf("%d", &item);

	// 값 삽입
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		newNode->link = L->head;
		L->tail->link = newNode;
	}

	L->head = newNode;

	// 출력
	system("cls");
	printf("    삽입할 값: %d\n", item);
}

void insertMiddleCNode(linkedList_h* L) {
	listNode* Node, * newNode;
	elementType itemOld, itemNew;

	// 입력
	printf("  (Key) 어떤 값 뒤에?: ");
	scanf("%d", &itemOld);
	printf("  삽입할 값: ");
	scanf("%d", &itemNew);

	// itemOld까지 이동
	Node = L->head;
	while (Node->data != itemOld) {
		Node = Node->link;
		L->follow++;
	}
	
	// 값 삽입
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = itemNew;
	newNode->link = Node->link;
	Node->link = newNode;

	// 출력
	system("cls");
	printf("  삽입할 값: %d\n", itemNew);
}

void insertNthCNode(linkedList_h* L) {
	listNode* Node, * newNode;
	int index;
	elementType item;

	// 입력
	printCList(L);
	//printf("\033[A"); // \n 지우기
	printf("  위치(index, 0부터): ");
	scanf("%d", &index);
	printf("  삽입할 값: ");
	scanf("%d", &item);

	// index - 1까지 이동
	int count = 0;
	Node = L->head;
	while (count != index - 1) {
		Node = Node->link;
		count++;
		L->follow++;
	}

	// 값 삽입
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = Node->link;
	Node->link = newNode;

	// 출력
	system("cls");
	printf("  삽입할 값: %d\n", item);
}

void insertLastCNode(linkedList_h* L) {
	listNode* newNode;
	elementType item;

	printf("    삽입할 값: ");
	scanf("%d", &item);

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = newNode;
		L->head = newNode;
		L->tail = newNode;
	}
	else {
		L->tail->link = newNode;
		newNode->link = L->head;
		L->tail = newNode;
	}

	system("cls");
	printf("    삽입할 값: %d\n", item);
}

void deleteCNode(linkedList_h* L) {

	listNode* Node, * delNode;
	elementType item;

	printf("    삭제할 값: ");
	scanf("%d", &item);

	//리스트 비어 있을 때
	if (L->head == NULL)
		return;

	// 2. 삭제할 대상(노드의 link가 삭제 대상)이 있는지 찾기
	Node = L->head;
	int found = 0;
	do {
		if (Node->link->data == item) {
			found = 1;
			break;
		}
		Node = Node->link;
		L->follow++;
	} while (Node != L->head);

	// 만약 찾지 못했다면
	if (!found) {
		printf("리스트에 %d 값이 존재하지 않습니다.\n", item);
		return;
	}

	delNode = Node->link;

	// 값 1개
	if (L->head == L->tail) {
		L->head = NULL;
		L->tail = NULL;
	}
	//이전 노드가 tail
	else if (delNode == L->head) {
		L->head = delNode->link;
		Node->link = L->head;
	}
	// 삭제할 노드가 tail
	else if (delNode == L->tail) {
		L->tail = Node;
		Node->link = L->head;
	}
	// 중간 노드
	else {
		Node->link = delNode->link;
	}

	free(delNode);

	// 출력
	system("cls");
	printf("    삭제할 값: %d\n", item);
}
