// Linked List
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
	/*linkedList_h mylist;
	mylist.head = (listNode*)NULL;*/

	linkedList_h* mylist;
	mylist = createLinkedList();

	//ctrl + D
	//First
	insertFirstNode(mylist, 50);
	insertFirstNode(mylist, 40);
	insertFirstNode(mylist, 30);
	insertFirstNode(mylist, 20);e
	insertFirstNode(mylist, 10);
	insertFirstNode(mylist, 00);

	//Last
	insertLastNode(mylist, 60);
	insertLastNode(mylist, 70);
	insertLastNode(mylist, 80);
	insertLastNode(mylist, 90);

	//Middle
 	insertMiddleNode(mylist, mylist->head->link->link->link->link, 1000);

	//Nth
	insertNthNode(mylist, 2, 25);

	printList(mylist);
	destroyLinkedList(mylist);

	printf("Destroy unorder linked list and New ordered linked list\n");
	mylist = createLinkedList();
	ordered_insertNode(mylist, 16);
	ordered_insertNode(mylist, 14);
	ordered_insertNode(mylist, 11);
	ordered_insertNode(mylist, 18);
	ordered_insertNode(mylist, 15);
	ordered_insertNode(mylist, 13);
	ordered_insertNode(mylist, 13);

	printList(mylist);

	deleteNode(mylist, mylist->head->link->link);
	printList(mylist);

	destroyLinkedList(mylist);

	mylist = createCLinkedList();
	insertFirstCNode(mylist, 10);
	insertFirstCNode(mylist, 20);
	insertFirstCNode(mylist, 30);
	insertFirstCNode(mylist, 40);
	insertFirstCNode(mylist, 50);

	printCList(mylist);

	deleteCNode(mylist, mylist->head->link->link);
	printCList(mylist);

	destroyCLinkedList(mylist);

	return 0;
}
