#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"


QueueType* createLQueue() {
	return createDClinkedList();
}

void destroyLQueue(QueueType* LQ) {
	destroyDClinkedList(LQ);
}

void enLQueue(QueueType* LQ, queueElement item) {
	insertLastDClinkedList(LQ, item);
}

queueElement deLQueue(QueueType* LQ) {
	if (!isLQueueEmepty(LQ))return deleteDClinkedList(LQ->rlink);
	else return ('\0');
}

int isLQueueEmepty(QueueType* LQ) {
	return (LQ->rlink == LQ);
}
int isLQueueFull(QueueType* LQ) {
	return 0;
}

int printLQueue(QueueType* LQ) {
	printDClinkedList(LQ);
}

