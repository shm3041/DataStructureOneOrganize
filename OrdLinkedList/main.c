// Ordered Linked List
#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

listType* SmTranspose(listType* org) {
	listType* tr;
	elementType o_item;

	tr = createList(org->size);

	for (int i = 0; i <= org->last; i++) {
		o_item = readItem(org, i);
		ordered_insertItem(tr, (elementType) { o_item.col, o_item.row, o_item.value });
	}

	return tr;
}

main() {
	listType *myList, *trans;
	myList = createList(20);

	ordered_insertItem(myList, (elementType) { 0, 2, 2 }); //행, 열, 데이터
	ordered_insertItem(myList, (elementType) { 0, 6, 12 });
	ordered_insertItem(myList, (elementType) { 1, 4, 7 });
	ordered_insertItem(myList, (elementType) { 2, 0, 23 });
	ordered_insertItem(myList, (elementType) { 3, 3, 31 });
	ordered_insertItem(myList, (elementType) { 4, 1, 14 });
	ordered_insertItem(myList, (elementType) { 4, 5, 26 });
	ordered_insertItem(myList, (elementType) { 5, 6, 6 });
	ordered_insertItem(myList, (elementType) { 6, 0, 52 });
	ordered_insertItem(myList, (elementType) { 7, 4, 11 });

	printf("Original Matrix\n");
	printList(myList);

	trans = SmTranspose(myList);
	printf("Transpose Matrix\n");
	printList(trans);

	/*ordered_insertItem(myList, 10);
	ordered_insertItem(myList, 20);
	ordered_insertItem(myList, 30);
	ordered_insertItem(myList, 40);

	printList(myList);

	ordered_insertItem(myList, 5);
	printList(myList);

	ordered_insertItem(myList, 15);
	printList(myList);

	ordered_insertItem(myList, 45);
	printList(myList);

	ordered_insertItem(myList, 100);
	printList(myList);

	ordered_insertItem(myList, 200);
	printList(myList);*/
}