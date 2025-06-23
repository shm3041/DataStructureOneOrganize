#pragma once
#include "Double Circular Linked List.h"

typedef elementType queueElement;
typedef NodeType QueueType;

extern QueueType* createLQueue();
extern void destroyLQueue(QueueType* LQ);
extern void enLQueue(QueueType* LQ, queueElement item);
extern queueElement deLQueue(QueueType* LQ);
extern int isLQueueEmepty(QueueType* LQ);
extern int isLQueueFull(QueueType* LQ);
extern int printLQueue(QueueType* LQ);


