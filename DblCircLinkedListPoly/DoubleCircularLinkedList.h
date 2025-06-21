#pragma once

typedef struct elementType {
	int coef;
	int expo;
} elementType;

typedef struct Node {
	struct Node* lLink;
	elementType data;
	struct Node* rLink;
} NodeType;

extern NodeType* createDClinkedList();
extern void insertFirstDClinkedList(NodeType* Node, elementType item);
extern void insertLastDClinkedList(NodeType* Node, elementType item);
extern void insertNthDClinkedList(NodeType* Node, int index, elementType item);
extern elementType deleteDCLinkedList(NodeType* Node);
extern elementType deleteLastDClinkedList(NodeType* Node);
extern void distroyDClinkedList(NodeType* Node);
extern void printDClinkedList(NodeType* H);