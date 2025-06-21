/*
BEGIN

PRINT "정수의 개수를 입력하세요: "
READ integer size

MALLOC integer array arr(size)

PRINT "SIZE개의 정수를 입력하세요\n"
FOR i = 0 TO size - 1 DO (i++)
	READ arr(i)

FOR i = 0 TO size - 2 DO (i++)
	FOR j = 0 to size - i - 2 DO (j++)
		IF arr(j) > arr(j+1) THEN
			SWAP(arr(j), arr(j+1))

PRINT "오름차순으로 정렬된 정수들:\n"
FOR i = 0 TO size - 1 DO (i++)
	PRINT "arr(i)"

FREE integer array arr

END
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	int* arr;

	printf("정수의 개수를 입력하세요: ");
	scanf_s("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	printf("%d개의 정수를 입력하세요:\n", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("오름차순으로 정렬된 정수들:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}