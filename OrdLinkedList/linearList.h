#pragma once
#define NULL_ITEM (elementType) {-1, -1, -1} //행, 열, 값
//ADT 선형 목록을 작성

typedef struct ElementType {
	int row;
	int col;
	int value;
} elementType;

//#define NULL_ITEM (elementType) -1
//typedef int elementType; //int자료형에 별명 부여

typedef struct ListType {
	int last; //배열의 가장 마지막에 값이 없다는 것을 표시하기 위해 선언
	int size; //배열의 크기를 할당하기 위해 선언
	int move; //데이터를 몇 개 움직여야 하는지 선언
	elementType* array; //malloc로 size만큼 메모리 할당할 것
}listType;

//include 할 때 createList는 linearList.c라는 .h가 아닌 다른 곳에 있다는 것.
extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern elementType deleteItem(listType* list, int index);
extern int printList(listType* list);
extern int initList(listType* list);
extern int ordered_insertItem(listType* list, elementType item);
extern int compare_item(elementType item1, elementType item2);