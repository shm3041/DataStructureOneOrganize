#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"

main() {
	QueueType  *myQ;

	myQ = createLQueue();

	enLQueue(myQ, 'A');
	enLQueue(myQ, 'B');
	enLQueue(myQ, 'C');
	enLQueue(myQ, 'D');
	enLQueue(myQ, 'E');
	enLQueue(myQ, 'F');

	printLQueue(myQ);

	deLQueue(myQ);
	deLQueue(myQ);
	deLQueue(myQ);

	printLQueue(myQ);

	destroyLQueue(myQ);

}