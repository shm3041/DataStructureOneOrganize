#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularLinkedList.h"

// Create Head (Data X)
NodeType* createDClinkedList() {
	NodeType* H;

	H = (NodeType*)malloc(sizeof(NodeType));
	H->lLink = H;
	H->rLink = H;
	return H;
}

// insert First Node
void insertFirstDClinkedList(NodeType* Node, elementType item) {
	NodeType* newNode;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	newNode->lLink = Node;
	newNode->rLink = Node->rLink;
	Node->rLink->lLink = newNode;
	Node->rLink = newNode;
}

// insert Last Node
void insertLastDClinkedList(NodeType* Node, elementType item) {
	insertFirstDClinkedList(Node->lLink, item);
}

// insert Nth Node
void insertNthDClinkedList(NodeType* Node, int index, elementType item) {
	NodeType* temp = Node;
	for (int i = 0; i < index; i++)
		temp = temp->rLink;
	insertFirstDClinkedList(temp, item);
}

// delete Node
elementType deleteDCLinkedList(NodeType* Node) {
	elementType r = Node->data;

	Node->lLink->rLink = Node->rLink;
	Node->rLink->lLink = Node->lLink;
	
	free(Node);
	return r;
}

// delete Last Node
elementType deleteLastDClinkedList(NodeType* Node) {
	deleteDCLinkedList(Node->lLink);
}

// distory List
void distroyDClinkedList(NodeType* Node) {
	NodeType* temp = Node->rLink;
	while (temp != Node) {
		free(temp->lLink);
		temp = temp->rLink;
	}
}

// print List
void printDClinkedList(NodeType* H) {
	NodeType* nptr = H->rLink;

	printf("순방향: ");
	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->rLink;
	}
	printf("\n");

	nptr = H->lLink;
	printf("역방향: ");
	while (nptr != H) {
		printf("(%d, %d)", nptr->data.coef, nptr->data.expo);
		nptr = nptr->lLink;
	}
	printf("\n");
}