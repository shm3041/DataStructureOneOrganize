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
	/*NodeType* newNode;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	newNode->lLink = Node->lLink;
	newNode->rLink = Node;
	Node->lLink->rLink = newNode;
	Node->lLink = newNode;*/
	insertFirstDClinkedList(Node->lLink, item);
}

// insert Nth Node
void insertNthDClinkedList(NodeType* Node, int index, elementType item) {
	/* NodeType* newNode;
	NodeType* temp = Node;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	for (int i = 0; i <= index; i++) {
		temp = temp->rLink;
	}

	newNode->lLink = temp;
	newNode->rLink = temp->rLink;
	temp->rLink->lLink = newNode;
	temp->rLink = newNode; */
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
		printf("[%d]", nptr->data);
		nptr = nptr->rLink;
	}
	printf("\n");

	printf("역방향: ");
	nptr = H->lLink;
	while (nptr != H) {
		printf("[%d]", nptr->data);
		nptr = nptr->lLink;
	}
	printf("\n");

	/*if (nptr->rLink == H) return;
	nptr = nptr->rLink;

	do {
		printf("[%d]", nptr->data);
		nptr->rLink;
	} while (nptr != H);
	printf("\n");*/
}