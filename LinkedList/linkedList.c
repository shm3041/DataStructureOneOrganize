//코드 구조는 0429 노트로
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

linkedList_h* createCLinkedList(void) {
	return createLinkedList();
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != (listNode*)NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
	}
	free(L);
}

void destroyCLinkedList(linkedList_h* L) {
	//listNode *p = L->head;
	//listNode* temp;

	//while (L->head != L->head->link) {
	//	p = L->head->link;
	//	L->head->link = L->head->link->link;  // L->head = p->link;
	//	free(p);
	//}
	//free(L->head);
	//free(L);

	listNode* me = L->head;
	listNode* next;

	while (me->link != L->head) {
		next = me->link;
		free(me);
		me = next;
	}
	free(me);
	free(L);
}

void printList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

void printCList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Circlular Linked List(%d): ", L->follow);
	if (lptr == NULL) {
		printf("\n");
		return;
	}

	while (lptr->link != L->head) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

//에러 여부를 리턴하기 위해 리터럴을 int로 지정
//헤더를 가져와서 Node를 만든 후 노드를 삽입함
void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)  |  lptr의 주소  |  lptr의 값은 data, link
	L->head = newNode; //(2)  |  [head->link = (data, link)] -> [head->link = (data, link)] -> ~~~~
}

void insertFirstCNode(linkedList_h* L, elementType item) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1) 

	if (L->head != (listNode*)NULL) {
		listNode* temp = L->head;
		//temp = tail이다.
		while (temp->link != L->head) {
			temp = temp->link;
			L->follow++;
		}
		temp->link = newNode; //tail의 링크: new노드, new노드는 헤드 가리킴
		//L->head = newNode;
	}
	else {
		//L->head = newNode;
		newNode->link = newNode;
	}

	L->head = newNode; //(2) 
}


void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		//사진 찍어놓음 0508
		newNode->link = pre->link; //(1)
		pre->link = newNode; //(2)
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) {
	//리스트에 노드가 없다면
	if (L->head == (listNode*)NULL) {
		//삽입하려는 노드의 위치가 0이라면
		if (loc == 0) insertFirstNode(L, item);
		else fprintf(stderr, "[insertNthNode]: list empty and loc not 0\n");
		return;
	}
	else {
		if (loc == 0)
			insertFirstNode(L, item);
		else {
			/*for (int i = loc, listNode* pre = L->head;
				i--, pre = pre->link;
				i > 1 && pre->link != (listNode*)NULL) {
				if (i == 1) insertMiddleNode(L, pre, item);
				else fprintf(stderr, "[insertNthNode]: locationerror");
			}*/
			int i = loc;
			listNode* pre = L->head;
			while (i > 1 && pre->link != (listNode*)NULL) {
				i--, pre = pre->link;
				L->follow++;
			}
			if (i == 1) insertMiddleNode(L, pre, item);
			else fprintf(stderr, "[insertNthNode]: location error");
		}
		return;
	}
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode *temp, *newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	//만약 연결리스트에 값이 없다면 리턴
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return 0;
	}
	//만약 연결리스트에 값이 있다면 마지막 지점으로 설정
	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}
	temp->link = newNode;
}

void insertLastCNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	//만약 연결리스트에 값이 없다면 리턴
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return 0;
	}
	//만약 연결리스트에 값이 있다면 마지막 지점으로 설정
	while (temp->link != L->head) {
		temp = temp->link;
		L->follow++;
	}
	temp->link = newNode;
}

int compare_item(elementType first, elementType second) {
	return (first - second);
	//return (second - first);
}

void ordered_insertNode(linkedList_h* L, elementType item) {
	listNode* pre;

	//리스트가 비어있다면 0번 위치에 노드 삽입
	if (L->head == (listNode*)NULL)
		insertFirstNode(L, item);
	else {
		//0번 노드의 값 > item , 0번 위치에 노드 삽입
		if (compare_item(L->head->data, item) > 0)
			insertFirstNode(L, item);
		//아니라면 다음 노드와 비교
		else {
			pre = L->head; //->link를 가리켜도 될텐데?
			while (pre->link != (listNode*)NULL) {
				if ((compare_item(pre->data, item) < 0 &&
					 compare_item(pre->link->data, item) > 0) ||
					 compare_item(pre->data, item) == 0) break;
				pre = pre->link;
				L->follow++;
			}
			insertMiddleNode(L, pre, item);
		}
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	//리스트가 비어있다면 return
	if (L->head == (listNode*)NULL) return; 
	/* 책 코드 이상해서 주석처리(교수님 말씀)
	if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	}*/
	//2번 위치에 노드가 없다면 return  (p : 2번위치를 가리킴)
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		//pre의 link 값이 p가 아니라면, 다음 노드를 가리킴
		while (pre->link != p && p->link != (listNode*)NULL) { 
			pre = pre->link;
			L->follow++;
		}
		//1, 3번 노드를 연결, 2번 위치에 있는 노드를 삭제
		if (pre->link == p) {
			pre->link = p->link;
			free(p);
		}
		else 
			fprintf(stderr, "[deleteNode]: not in the list\n");
	}
}
void deleteCNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != L->head) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link;
			free(p);
		}
		else
			fprintf(stderr, "[deleteNode]: not in the list\n");
	}
}