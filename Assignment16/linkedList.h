#pragma once

typedef int elementType;

//Node
typedef struct ListNode { 
	elementType data;
	struct ListNode* link;
} listNode;

//List
typedef struct { 
	listNode* head; // First
	listNode* tail; // Last
	int follow;
} linkedList_h;

extern linkedList_h* createCLinkedList(void);
extern void destroyCLinkedList(linkedList_h* L);
extern void printMenu();
extern void printCList(linkedList_h* L);
extern void printHeadTail(linkedList_h* L);
extern void insertFirstCNode(linkedList_h* L);
extern void insertMiddleCNode(linkedList_h* L);
extern void insertNthCNode(linkedList_h* L);
extern void insertLastCNode(linkedList_h* L);
extern void deleteCNode(linkedList_h* L);
