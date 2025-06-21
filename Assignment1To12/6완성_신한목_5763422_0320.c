/*
시작

출력 "정수 n을 입력하세요: "
정수 n을 입력받음
출력 "n 이하의 소수: "
isPrime 함수 호출(매개변수 n)
반복문 (i는 2부터 n이하까지)
{
	반복문 (j는 2부터 i미만까지)
	{
		만약 i % j가 0이라면 BREAK
	}
	만약 i와 j가 같다면 i를 출력
}

끝
==============================================================
BEGIN

PRINT "정수 n을 입력하세요: "
READ integer n
PRINT "n 이하의 소수 : "
CALL isPrime(n)
FOR i = 2 TO n DO (i++)
	FOR j = 2 TO i - 1 DO (j++)
		IF i % j = 0 THEN
			BREAK
	IF i = j THEN
		PRINT "i "

END
*/

//시간복잡도: O(n^2)

#include <stdio.h>

//소수 판별 함수
void isPrime(int n) {
	int i, j;
	//1은 소수가 아니니 2부터 반복문 실행
	//i를 2부터 n까지 반복하며 소수 여부 확인
	//j를 i-1까지 반복하며 i가 소수인지 판별한다
	//i보다 낮은 수로 i를 나누어봤을 때 나머지가 0이 아니라면
	//소수이므로 i를 출력한다.
	for (i = 2; i <= n; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (i == j) {
			printf("%d ", i);
		}
	}
}

int main() {
	int n;
	//정수 입력
	printf("정수 n을 입력하세요 : ");
	scanf_s("%d", &n);

	//소수 출력
	printf("%d 이하의 소수 : ", n);
	isPrime(n); //소수 판별 함수호출

	return 0;
}