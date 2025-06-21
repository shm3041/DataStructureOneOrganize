#include <stdio.h>
#include <string.h> //strlen()

int main() {
	char input[100]; //입력된 문자열 저장할 배열

	//문자열 입력
	printf("문자열을 입력하세요: ");
	gets(input);

	//입력된 문자열 길이 출력
	printf("문자열 길이: %d\n", strlen(input));

	for (int i = 0; i < strlen(input); i++) {
		//문자열이 대문자라면 소문자로
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = input[i] + 32;
		}
		//문자열이 소문자라면 대문자로
		else if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = input[i] - 32;
		}
	}
	//변환된 문자열 출력
	printf("변환된 문자열 : %s", input);

	return 0;
}