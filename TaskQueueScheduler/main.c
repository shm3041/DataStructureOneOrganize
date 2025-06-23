#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "Queue.h"

QueueType* myQ;

void producer() {
	int job = rand() % 10;
	if (!isLQueueFull(myQ))
		enLQueue(myQ, job);
	printf("[Producer] create Job = %d\n", job);
}

void consumer() {
	int job;

	if (!isLQueueEmepty(myQ)) {
		job = deLQueue(myQ);
		printf("[Consumer] dispath job = %d", job);
		job = job - 1;
		Sleep(1000);
		if (job > 0 && !isLQueueFull(myQ)) {
			enLQueue(myQ, job);
			printf(", insert job = %d", job);
		}
	}
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		int r = rand() % 10;
		if (r == 0)
			producer();
		else {
			consumer();
			Sleep(1000);
		}
	}


	return 0;
}