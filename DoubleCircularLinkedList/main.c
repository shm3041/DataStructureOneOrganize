#include <stdio.h>
#include <stdlib.h>

#include "DoubleCircularLinkedList.h"

int main() {
	NodeType* mylist;
	mylist = createDClinkedList();

	/* insertFirstDClinkedList(mylist, 0); // 1번 위치에 삽입
	insertFirstDClinkedList(mylist, 1); // 1번 위치에 삽입
	insertFirstDClinkedList(mylist->rLink, 2); // 2번 위치에 삽입
	insertFirstDClinkedList(mylist->lLink, 3); // 마지막 위치에 삽입
	printDClinkedList(mylist);

	deleteDCLinkedList(mylist->rLink); // 1번 노드 삭제
	deleteDCLinkedList(mylist->lLink); // 마지막 노드 삭제
	deleteDCLinkedList(mylist->rLink->rLink); // 2번 노드 삭제
	printDClinkedList(mylist); */

	insertLastDClinkedList(mylist, 1);
	insertLastDClinkedList(mylist, 2);
	insertLastDClinkedList(mylist, 3);
	insertLastDClinkedList(mylist, 4);
	insertLastDClinkedList(mylist, 5);
	printDClinkedList(mylist);

	deleteLastDClinkedList(mylist);
	deleteLastDClinkedList(mylist);
	printDClinkedList(mylist);

	insertNthDClinkedList(mylist, 1, 333);
	printDClinkedList(mylist);

	distroyDClinkedList(mylist);

	return 0;
}