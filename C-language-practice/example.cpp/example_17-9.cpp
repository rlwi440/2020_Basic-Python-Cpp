#include <stdio.h>

struct list //자기참조 구조체(self-referencing struct)
{
    int num;           //데이터를 저장하는 멤버
    struct list *next; //구조체 자신을 가리키는 포인터 멤버
};

int main(void)
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; //구조체 변수 초기화
    struct list *head = &a, *current;                  //헤드 포인터 초기화

    a.next = &b; //a의 포인터 맴버가 b를 가르킴
    b.next = &c; //b의 포인터 멤버가 c를 가르킴

    printf("head->curnum:%d\n", head->num);             //head가 가르키는 a의 num 멤버 사용
    printf("head->next-> num : %d\n", head->next->num); //head가 b의 num 멤버사용

    printf("list all :");
    current = head;         //최초 current 포인터가 a를 가르킴
    while (current != NULL) //마지막 구조체 변수까지 출력하면 반복종료
    {
        printf("%d ", current->num); //current가 가르키는 구조체 변수의 num 출력
        current = current->next;
    }
    printf("\n");

    return 0;
} //제목 재수정(2020년 05월 31일),혼자 공부하는 c언어 파일 모음집