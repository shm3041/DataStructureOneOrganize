#include <stdio.h>

int main() {
	int input;
	int result = 0;

	//값 입력받기
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &input);

	//10진수 -> 2진수로 변환하여 출력하기
	 //32자리만큼 출력, 왼쪽부터 출력하기 위해 오른쪽으로
	 //비트를 이동시키고, AND연산자를 사용하여 해당 비트에
	 //값이 존재한다면 1, 존재하지 않는다면 0을 출력
	printf("입력된 정수의 32비트 표현 : ");
	for (int i = 31; i >= 0; i--) { 
		result = input >> i & 1;
		printf("%d", result);
	}

	return 0;
}