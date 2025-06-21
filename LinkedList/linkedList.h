#pragma once

typedef int elementType; //노드에 저장할 데이터 타입 (정수)

typedef struct ListNode { //연결리스트의 노드 타입 정의
	elementType data;
	struct ListNode* link; //포인터 | data, next
} listNode;

//구조체에 이름이 필요한 것은 위에 기재한 것과 같이 구조체 안에서 구조체를 사용하지 위함임.
typedef struct { //연결리스트의 헤더(다음 자료의 위치)
	listNode* head;
	//tail 변수: 리스트의 가장 마지막을 가리킴
	int follow;
} linkedList_h;

extern linkedList_h* createLinkedList(void); //매개변수가 void일 때는 linkedList_h*(리터럴)를 리턴한다.
extern linkedList_h* createCLinkedList(void);

extern void destroyLinkedList(linkedList_h* L);
extern void destroyCLinkedList(linkedList_h* L);

extern void printList(linkedList_h* L);
extern void printCList(linkedList_h* L);

extern void insertFirstNode(linkedList_h* L, elementType item);
extern void insertFirstCNode(linkedList_h* L, elementType item);

extern void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);

extern void insertLastNode(linkedList_h* L, elementType item);
extern void insertLastCNode(linkedList_h* L, elementType item);

extern void insertNthNode(linkedList_h* L, int loc, elementType item); //loc: location
extern void ordered_insertNode(linkedList_h* L, elementType item);

//deleteNode First, Middle, Last 구현해보기
extern void deleteNode(linkedList_h* L, listNode* p);
extern void deleteCNode(linkedList_h* L, listNode* p);