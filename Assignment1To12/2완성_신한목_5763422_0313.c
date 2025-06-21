#include <stdio.h>

int main() {
    float input; //소수 입력받을 변수
    unsigned int bits; //소수를 정수로 변환하여 받을 변수

    //소수 입력받고 자료형 변환
    printf("소수를 입력하세요 : ");
    scanf_s("%f", &input);
    bits = *(unsigned int*)&input; //비트 연산에 사용하기 위해 float -> unsigned int로 변환

    //1비트(부호부) 출력
    printf("부호 (1비트) : %d\n", bits >> 31 & 1);

    //8비트(지수부) 출력
    printf("지수 (8비트) : ");
    for (int i = 30; i >= 23; i--) {
        printf("%d ", bits >> i & 1);
    }
    printf("\n");

    //23비트(가수부) 출력
    printf("가수 (23비트) : ");
    for (int i = 22; i >= 0; i--) {
        printf("%d ", (bits >> i) & 1);
    }
    printf("\n");

    return 0;
}