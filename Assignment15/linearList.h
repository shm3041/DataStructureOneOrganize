#pragma once

//Polynomial
#define NULL_ITEM (elementType) {0, 0} 

typedef struct ElementType {
	char name[20];
	char phone[20];
} elementType;

typedef struct ListType {
	int size;
	int last;
	int move;
	elementType* array;
} listType;

extern listType* createList(int size);
extern void destroyList(listType* list);
extern elementType readItem(listType* list, int index);
extern int ordered_insertItem(listType* list, elementType item);
extern void deleteItem(listType* list, elementType index);
extern int printList(listType* book);
extern void AddPhone(listType* book);
extern void deletePhone(listType* book);
extern int initList(listType* list);
extern void searchPhone(listType* book);