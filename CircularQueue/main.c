#include <stdio.h>
#include <stdlib.h>

#include "Circular Queue.h"

int main() {
	QueueType* myQ;

	myQ = createQueue();

	printQueue(myQ);

	enQueue(myQ, 'A');
	printQueue(myQ);
	enQueue(myQ, 'B');
	printQueue(myQ);
	enQueue(myQ, 'C');
	printQueue(myQ);
	enQueue(myQ, 'D');
	printQueue(myQ);

	deQueue(myQ);
	printQueue(myQ);
	deQueue(myQ);
	printQueue(myQ);
	deQueue(myQ);
	printQueue(myQ);
	deQueue(myQ);
	printQueue(myQ);

	destroyQueue(myQ);
	return 0;
}