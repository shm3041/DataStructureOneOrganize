#pragma once

#define Q_SIZE 4

typedef char elementType;

typedef struct {
	elementType queue[Q_SIZE];
	int front, rear;
} QueueType;

extern QueueType *createQueue(void);
extern void destroyQueue(QueueType* Q);
extern int isQueueEmpty(QueueType* Q);
extern int isQueueFull(QueueType* Q);
extern void enQueue(QueueType* Q, elementType item);
extern elementType deQueue(QueueType* Q);
extern void printQueue(QueueType* Q);