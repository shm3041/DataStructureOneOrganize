#pragma once

// typedef int elementType;
typedef char elementType;

typedef struct Node {
	struct Node* llink;
	elementType data;
	struct Node* rlink;
} NodeType;

extern NodeType *createDClinkedList();
extern void destroyDClinkedList(NodeType* H);
extern void insertDClinkedList(NodeType *p, elementType item);
extern void insertLastDClinkedList(NodeType* H, elementType item);
extern elementType deleteDClinkedList(NodeType* p);
extern elementType deleteLastDClinkedList(NodeType* H);
extern void printDClinkedList(NodeType* H);