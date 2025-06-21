#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//학생 구조체 선언
typedef struct student {
    char name[20]; //이름
    int stnum, score; //학번, 점수
} StType;

int main() {
    int size; //students 동적 메모리 할당 크기
    StType* students; //학생 구조체
    int stnum; //학번
    bool found; //학번 존재여부 확인 (1: true, 0: false)

    //학생 수 입력받기
    printf("몇 명의 학생 정보를 입력하시나요? ");
    scanf_s("%d", &size);
    students = (StType*)malloc(sizeof(StType) * size);

    //학생 정보 입력받기 (이름, 학번, 점수)
    for (int i = 0; i < size; i++) {
        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i);
        scanf_s("%s %d %d", students[i].name, sizeof(students[i].name), &students[i].stnum, &students[i].score);
    }

    //학번으로 학생정보 검색
    while (1) {
        found = false;

        //학번 입력받기
        printf("학번을 입력하세요 (0이면 종료): ");
        scanf_s("%d", &stnum);

        //0입력 시 종료
        if (stnum == 0) break;

        //학생 정보 찾기
        for (int i = 0; i < size; i++) {
            if (stnum == students[i].stnum) {
                printf("%s %d %d\n", students[i].name, students[i].stnum, students[i].score);
                found = true;
                break;
            }
        }

        //학생 정보가 없다면 출력
        if (!found) printf("해당 학번의 학생이 없습니다.\n");
    }

    //동적 메모리 할당 해제
    free(students);
    return 0;
}
