#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps); //동적 할당 영역의 문자열을 출력하는 함수

int main(void)
{
    char temp[80];       //임시 char 배열
    char *str[21] = {0}; //문자열 을 연결할 포인터 배열 ,널 포인터로 초기화
    int i = 0;           //반복 제어 변수;

    while (i < 20) // 최대 20개까지 입력
    {
        printf("문자열을 입력하세요 :");
        gets_s(temp); //문자열 입력
        if (strcmp(temp, "end") == 0)
            break;                                 //end 가 입력되면 반복종료
        str[i] = (char *)malloc(strlen(temp) + 1); //문자열 저장공간 할당
        strcpy(str[i], temp);                      //동적 할당 영역에 문자열 복사
        i++;
    }
    print_str(str); //입력된 문자열 출력

    for (i = 0; str[i] != NULL; i++) //str에 연결된 문자열이 없을때 까지
    {
        free(str[i]); //동적 할당 영역반환
    }

    return 0;
}
void print_str(char **ps) //이중 포인터 선언
{
    while (*ps != NULL) //포인터 배열의 값이 널 포인터 가 아닌 동안 반복
    {
        printf("%s\n", *ps); //ps가 가리키는 것은 포인터 배열의 요소
        ps++;                //ps 가 다음 배열 요소를 가리킨다.
    }
} //제목 재수정(2020년 05월 31일),혼자 공부하는 c언어 파일 모음집