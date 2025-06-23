#include <stdio.h>
#include <stdlib.h>

#include "Circular Queue.h"

QueueType* createQueue(void) {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;

	return Q;
}

void destroyQueue(QueueType* Q) {
	free(Q);
}

int isQueueEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

int isQueueFull(QueueType* Q) {
	return (((Q->rear + 1) % Q_SIZE) == Q->front);
}

void enQueue(QueueType* Q, elementType item) {
	if (isQueueFull(Q))
		return;
	else {
		// 핵심 : rear을 Q_SIZE로 나눠줘야 원형이 된다.
		// if SIZE: 5일때 rear이 4이고, 데이터를 삽입한다면
		// rear이 5가 된다. 이 때 front는 5의 위치와 동일(0)
		// 따라서 rear % Q_SIZE를 해줘서 0으로 만들어주어
		// rear을 front위치로 만들어서 원형으로 사용할 수 있다.
		Q->queue[Q->rear] = item;
		Q->rear = (Q->rear + 1) % Q_SIZE;
		
	}
}

elementType deQueue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		printf("Early Empty!\n");
		return;
	}
	else {
		Q->front = (Q->front + 1) % Q_SIZE;
		return Q->queue[Q->front];
	}
}

void printQueue(QueueType* Q) {
	printf("Queue: [");
	for (int i = Q->front; i != Q->rear; i = (i + 1) % Q_SIZE) {
		printf("%c ", Q->queue[i]);
	}

	if (Q->front != Q->rear)
		printf("\b]\n");
	else
		printf("]\n");
}