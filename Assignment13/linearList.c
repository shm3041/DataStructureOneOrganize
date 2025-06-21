#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

//CRUD-PI에 의거하여 함수 생성

listType* createList(int size) {
	//선형리스트 생성
	listType* lptr = NULL;
	lptr = (listType*)malloc(sizeof(listType));

	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->move = 0;
	lptr->last = -1;

	return lptr;
}

elementType readItem(listType* list, int index) {
	if (index < 0 || list->last < index) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return item1.row - item2.row; //item1 > item2 = 0보다 큰 값 반환
	else return item1.col - item2.col; //row(행)이 같다면 열을 비교하여 값 반환
}

//OLL ADT
int ordered_insertItem(listType* list, elementType item) {
	int i;
	//item이 list->array[i]값보다 작거나 같다면
	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
	}
	//array[i]번지 ~ last번지까지의 값을 모두 뒤로 밀고
	//array[i]번지에 값을 삽입하라 (array 길이 1 증가)
	for (int j = list->last; j >= i; j--) {
		list->array[j + 1] = list->array[j];
		list->move++;
	}
	list->array[i] = item;
	list->last++;

	return 1;
}

elementType deleteItem(listType* list, int index) {
	elementType tmp = list->array[index];

	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d int deleteItem\n", index);
		return NULL_ITEM;
	}
	for (int i = index; i <= list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}
	list->last--;
	return tmp;
}

void printList(listType* list) {
	printf("List: size = %d, last = %d\nItems: \n", list->size, list->last);
	for (int i = 0; i <= list->last; i++) {
		printf("   [%d] %d, %d, %d\n", i, list->array[i].row,
			list->array[i].col,
			list->array[i].value);
	}
	printf("\n");
}

void initList(listType* list) {
	list->last = -1;
	list->move = 0;
}