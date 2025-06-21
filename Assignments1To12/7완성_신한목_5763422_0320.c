#include <stdio.h>
#include <stdlib.h> // exit(1)
#include <string.h>
#include <ctype.h> // isdigit()(문자, 숫자 구분)

#define MAX_LENGTH 100

float calculate(float num1, float num2, char operator);//사칙연산을 하기 위한 함수 (매개변수: 정수 2개, 연산자)
float add(float a, float b); //더하기
float subtract(float a, float b); //빼기
float multiply(float a, float b); //곱하기
float divide(float a, float b); //나누기

int main() {
    //값을 입력받을 배열
    char input[MAX_LENGTH];

    // scanf_s를 사용하여 입력 받기. 입력 크기 제한을 두어야 한다.
    printf("계산할 수식을 입력하세요: ");
    scanf_s("%s", input, sizeof(input));

    float num[MAX_LENGTH / 2]; // 숫자 배열(소수점 연산 가능해야하므로 float 선언)
    char chr[MAX_LENGTH / 2]; // 문자 배열
    int numCount = 0, chrCount = 0; //숫자, 문자 카운트

    // 숫자와 연산자를 분리하여 배열에 저장
    int i = 0;
    while (i < strlen(input)) {
        if (isdigit(input[i]) || input[i] == '.') { //문자, 숫자 구분
            char number[MAX_LENGTH] = { 0 };
            int j = 0;

            while (isdigit(input[i]) || input[i] == '.') {
                number[j++] = input[i++];
            }
            num[numCount++] = atof(number);
        }
        else {
            chr[chrCount++] = input[i++];
        }
    }
    // 곱셈(*)과 나눗셈(/) 먼저 계산
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '*' || chr[i] == '/') {
            float result = calculate(num[i], num[i + 1], chr[i]);
            num[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) num[j] = num[j + 1];
            numCount--;
            for (int j = i; j < chrCount - 1; j++) chr[j] = chr[j + 1];
            chrCount--;
            i = -1;
        }
    }
    // 덧셈(+)과 뺄셈(-) 계산
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '+' || chr[i] == '-') {
            float result = calculate(num[i], num[i + 1], chr[i]);
            num[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) num[j] = num[j + 1];
            numCount--;
            for (int j = i; j < chrCount - 1; j++) chr[j] = chr[j + 1];
            chrCount--;
            i = -1;
        }
    }

    printf("계산 결과: %.2f\n", num[0]);
    return 0;
}

// 연산 함수
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) {
    if (b != 0) return a / b;
    printf("0으로 나눌 수 없습니다!\n");
    exit(1);
}

float calculate(float num1, float num2, char operator) {
    switch (operator) {
    case '+': return add(num1, num2);
    case '-': return subtract(num1, num2);
    case '*': return multiply(num1, num2);
    case '/': return divide(num1, num2);
    default: return 0;
    }
}