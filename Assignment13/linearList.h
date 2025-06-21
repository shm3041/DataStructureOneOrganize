#pragma once
//에러 메세지
#define NULL_ITEM (elementType) {-1, -1, -1}
//선형리스트를 제작하기 위해 필요한 자료형을 선언.

//리스트 원소의 자료형
typedef struct ElementType {
	int row; //행
	int col; //열
	int value; //값
} elementType;

//리스트 관리 변수
typedef struct ListType {
	int size; //크기
	int move; //이동 (특정 위치에 원소를 삽입하기 위함)
	int last; //마지막 원소
	elementType* array; //malloc, 리스트
}listType;

//include 할 때 createList는 linearList.c라는 .h가 아닌 다른 곳에 있다는 것.
extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern elementType deleteItem(listType* list, int index);
extern void printList(listType* list);
extern void initList(listType* list);
extern int ordered_insertItem(listType* list, elementType item);
extern int compare_item(elementType item1, elementType item2);