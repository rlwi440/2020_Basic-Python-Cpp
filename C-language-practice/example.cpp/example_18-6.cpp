#include <stdio.h>

int main(void)
{
    FILE *fp; //fp (" file pointer "")
    int ary[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};
    int i, res;

    fp = fopen("a.txt", "wb"); //바이너리 파일로 개방 , wb(writebinary)
    for (i = 0; i < 10; i++)
    {
        fputc(ary[i], fp); //배열 요소의  각 값에 해당하는 아스키 문자 출력
    }
    fclose(fp); //파일 닫음

    fp = fopen("a.txt", "rt"); //같은 파일을 텍스트 파일로 개방  ,rt(read txt)
    while (1)
    {
        res = fgetc(fp); //파일에서 한 문자 입력
        if (res == EOF)
            break;
        printf("%4d", res); //입력한 문자의 아스키 코드 값 출력
    }
    fclose(fp); //파일 닫음

    return 0;
} //제목 재수정(2020년 05월 31일),혼자 공부하는 c언어 파일 모음집