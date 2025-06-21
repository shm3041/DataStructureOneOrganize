#include <stdio.h>
#include <stdlib.h>

int main() {
	int** arr1;
	int** arr2;

	//2차원 동적 메모리 할당 arr1
	arr1 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr1[i] = (int*)malloc(sizeof(int) * 2);
	}

	//2차원 동적 메모리 할당 arr2
	arr2 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr2[i] = (int*)malloc(sizeof(int) * 2);
	}

	//첫 번째 행렬 입력
	printf("첫 번째 행렬 입력:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr1[i][j]);
		}
	}

	//두 번째 행렬 입력
	printf("두 번째 행렬 입력:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}

	//행렬 덧셈 결과 출력
	printf("행렬 덧셈 결과:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", arr1[i][j] + arr2[i][j]);
		}
		printf("\n");
	}

	//동적 메모리 할당 해제 arr1
	for (int i = 0; i < 2; i++) {
		free(arr1[i]);
	}
	free(arr1);

	//동적 메모리 할당 해제 arr2
	for (int i = 0; i < 2; i++) {
		free(arr2[i]);
	}
	free(arr2);

	return 0;
}