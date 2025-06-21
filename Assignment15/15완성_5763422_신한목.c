#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearList.h"

int main() {
    listType* book;
    book = createList(100);

    while (1) {
        printf("===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("5. 종료\n");
        printf("메뉴를 선택하세요 : ");

        int input;
        scanf("%d", &input);
        switch (input) {
        case 1:            
            AddPhone(book);
            break;
        case 2:
            deletePhone(book);
            break;
        case 3:
            searchPhone(book);
            break;
        case 4:
            printList(book);
            break;
        case 5:
            destroyList(book);
            return 0;
        }
    }
}