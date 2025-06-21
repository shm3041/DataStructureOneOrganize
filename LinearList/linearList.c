#include <stdio.h>
#include <stdlib.h>
#include "linearList.h" //개발자가 만든 헤더파일을 include할 때는 ""로
//함수는 CRUID - PI에 따라 생성

//listType이라는 구조체 형식으로 createList 함수 생성
listType* createList(int size) {
	listType* lptr;
	//리스트 생성
	lptr = (listType*)malloc(sizeof(listType));
	//List에 size만큼 공간을 할당할 수 있게 array멤버변수의 크기 elementType(int) * size만큼 할당한다.
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);

	lptr->size = size;
	lptr->last = -1; //list에 초기 데이터가 없으니 기본값: -1
	lptr->move = 0;

	return lptr;
}

elementType readItem(listType* list, int index) {
	//만약 index가 element의 범위를 초과하였다면 error메세지를 출력한다.
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}

	return list->array[index];
	//return *(list->array + index); //위의 방식과 동일하다.
}

int insertItem(listType* list, int index, elementType item) {
	//index가 원소의 범위를 초과하였는지 체크 / 배열 안에 원소가 가득 차 있는지 체크
	if (index < 0 || index > list->last + 1) {
		fprintf(stderr, "Index error %d in insertItem\n", index);
		return NULL_ITEM;
	}
	if (index > list->size) {
		fprintf(stderr, "list is full (%d) in insertItem\n", index);
		return NULL_ITEM;
	}
	
	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;
	
	return 1;
}

elementType deleteItem(listType* list, int index) {
	elementType r = list->array[index];

	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in deleteItem\n", index);
		return NULL_ITEM;
	}

	for (int i = index; i < list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}

	list->last--;
	return r;
}

int printList(listType* list) {
	printf("List: size = %d, last = %d, move = %d\n\t Items: ", list->size, list->last, list->move);
	for (int i = 0; i <= list->last; i++) {
		printf(" [%d][%d] ", i, list->array[i]);
	}
	printf("\n");
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
}