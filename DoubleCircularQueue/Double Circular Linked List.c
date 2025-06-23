// Double Circular Linked List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>

#include "Double Circular Linked List.h"

NodeType* createDClinkedList() {
	NodeType* H;

	H = (NodeType*)malloc(sizeof(NodeType));
	H->llink =  H->rlink = H;
	return H;
}

void destroyDClinkedList(NodeType* H) {
	while (H->rlink != H) {
		deleteDClinkedList(H->rlink);
	}
	free(H);
}

void insertDClinkedList(NodeType* p, elementType item) {
	NodeType* n = (NodeType*)malloc(sizeof(NodeType)); //1
	
	n->data = item; //2

	n->llink = p; //3
	n->rlink = p->rlink; //4
	p->rlink = n; //5 p->rlink->link = n;(6) 
	n->rlink->llink = n;//6  p->rlink = n; (5)
}

void insertLastDClinkedList(NodeType* H, elementType item) {
	insertDClinkedList(H->llink, item);
}

elementType deleteDClinkedList(NodeType* p) {
	elementType r = p->data;

	p->llink->rlink = p->rlink; //1
	p->rlink->llink = p->llink; //2
	free(p);
	return r;
}

elementType deleteLastDClinkedList(NodeType* H) {
	deleteDClinkedList(H->llink);
}

void printDClinkedList(NodeType* H) {
	NodeType* nptr = H->rlink;

	printf("이중연결리스트 출력:(순방향)");
	while (nptr != H) {
		printf("(%c)", nptr->data);
		nptr = nptr->rlink;
	}

	printf("(역방향)");
	nptr = H->llink;
	while (nptr != H) {
		printf("(%c)", nptr->data);
		nptr = nptr->llink;
	}

	printf("\n");
}