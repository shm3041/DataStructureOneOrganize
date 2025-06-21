#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinearList.h"

void removeSpaces(char* str) {
    char* i = str;
    char* j = str;
    while (*j != 0) {
        *i = *j++;
        if (*i != ' ') i++;
    }
    *i = 0;
}

elementType parseTerm(char* term) {
    elementType item = { 0, 0 };
    char* xPtr = strchr(term, 'x');

    if (xPtr) {
        if (xPtr == term) item.coef = 1;
        else if (xPtr == term + 1 && term[0] == '-') item.coef = -1;
        else {
            char coefStr[10] = { 0 };
            strncpy(coefStr, term, xPtr - term);
            item.coef = atoi(coefStr);
        }

        char* expoPtr = strchr(term, '^');
        if (expoPtr) item.expo = atoi(expoPtr + 1);
        else item.expo = 1;
    }
    else {
        item.coef = atoi(term);
        item.expo = 0;
    }

    return item;
}

void parsePolynomial(char* input, listType* poly) {
    if (input == NULL || strlen(input) == 0) {
        printf("입력된 문자열이 없습니다.\n");
        return;
    }
    char temp[100];
    strcpy(temp, input);
    removeSpaces(temp);
    char* token = strtok(temp, "+");
    while (token != NULL) {
        elementType item = parseTerm(token);
        ordered_insertItem(poly, item);
        token = strtok(NULL, "+");
    }
}

listType* polymul(listType* f, listType* s) { //poly3 메모리 공간 할당 및 변수 선언 
    listType* a; 
    elementType f_item, s_item, r_item; 
    a = createList(f->size + s->size + 2);

    //i는 f의 항, j는 s의 항을 가리킴
    for (int i = 0; i <= f->last; i++) {
        f_item = readItem(f, i);
        for (int j = 0; j <= s->last; j++) {
            s_item = readItem(s, j);
            r_item.coef = f_item.coef * s_item.coef;
            r_item.expo = f_item.expo + s_item.expo;

            //같은 지수를 갖고 있는 항이 있다면 합하여라.
            int found = 0;
            for (int k = 0; k <= a->last; k++) {
                if (a->array[k].expo == r_item.expo) {
                    a->array[k].coef += r_item.coef; // 계수 합치기
                    found = 1;
                    break;
                }
            }
            //같은 지수를 갖고 있는 항이 없다면 값을 삽입하라
            if (!found) {
                ordered_insertItem(a, r_item);
            }
        }
    }

    return a;
}

int main() {
    listType* poly1, * poly2, * poly3;
    char input[100];

    poly1 = createList(50); // 리스트 크기 확장
    poly2 = createList(50);

    printf("첫 번째 다항식을 입력하시오 (예: 3x^2+4x+1):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    parsePolynomial(input, poly1);

    printf("두 번째 다항식을 입력하시오 (예: 2x^2+5x+3):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    parsePolynomial(input, poly2);

    poly3 = polymul(poly1, poly2);
    printList(poly3);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(poly3);
    return 0;
}