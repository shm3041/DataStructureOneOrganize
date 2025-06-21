#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

int main() {
	listType* myList1, * myList2, * myList3;
	elementType iMatrix;
	myList1 = createList(10);
	myList2 = createList(10);
	myList3 = createList(20);

	int i = 0;
	//첫 번째 행렬 입력받기
	printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
	while (1) {
		scanf("%d", &iMatrix.row);
		if (iMatrix.row == -1) break;
		scanf("%d %d", &iMatrix.col, &iMatrix.value);

		//ordered_insertItem(myList1, iMatrix); //함수 사용 시 자동으로 값이 정렬되어 삽입됨.
		myList1->array[i] = iMatrix;
		myList1->last++;
		i++;
	}
	//두 번째 행렬 입력받기
	i = 0;
	printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
	while (1) {
		scanf("%d", &iMatrix.row);
		if (iMatrix.row == -1) break;
		scanf("%d %d", &iMatrix.col, &iMatrix.value);

		//ordered_insertItem(myList2, iMatrix);
		myList2->array[i] = iMatrix;
		myList2->last++;
		i++;
	}

	i = 0;
	int j = 0;
	while (i <= myList1->last && j <= myList2->last) {
		elementType item1 = readItem(myList1, i);
		elementType item2 = readItem(myList2, j);

		int cmp = compare_item(item1, item2);
		if (cmp == 0) {
			// 같은 위치의 원소는 값을 더함
			ordered_insertItem(myList3, (elementType) { item1.row, item1.col, item1.value + item2.value });
			i++;
			j++;
		}
		else if (cmp < 0) {
			// item1이 item2보다 앞에 위치
			ordered_insertItem(myList3, item1);
			i++;
		}
		else {
			// item2가 item1보다 앞에 위치
			ordered_insertItem(myList3, item2);
			j++;
		}
	}

	// 비교할 대상이 없는 원소 출력
	while (i <= myList1->last) {
		ordered_insertItem(myList3, readItem(myList1, i++));
	}
	while (j <= myList2->last) {
		ordered_insertItem(myList3, readItem(myList2, j++));
	}

	//printList(myList1);
	//printList(myList2);
	printf("두 행렬의 합\n");
	printList(myList3);

	return 0;
}