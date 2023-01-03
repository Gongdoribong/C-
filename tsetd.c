#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

struct student {        // student 구조체 선언 (이름, 점수, grade를 담는 구조체)
    char name[20];
    int score;
    char grade;
};
typedef struct student student;     // struct student를 student라고 하겠다
void my_name(void)
{
    printf("======================\n");
    printf("학과: 통계학과\n");
    printf("학번: 2229022\n");
    printf("이름: 이승연\n");
    printf("======================\n");
}
void input(student*, int);      // student 포인터와 정수를 전달받는 input 함수 프로토타입
void output(student*, int);     // student 포인터와 정수를 전달받는 output 함수의 프로토타입
int main(void)
{
    my_name();
    
    student stu[SIZE];
    int num, i;
    printf("학생수를 입력하세요 : ");
    scanf("%d",&num);       // 학생수 입력받기
    printf("\n<학생이름입력>\n");
    for (i=0;i<num;i++)     // 학생수만큼 for 반복하면서
    {
        printf("학생 %d : ", i+1);
        scanf("%s",&stu[i].name);   // 이름 입력받기
    }
    input(stu,num);     // input함수 호출 (배열명과 학생수 전달)
    output(stu,num);    // output 함수 호출 (배열명과 학생수 전달)

    return 0;
}
void input(student* st, int n)
{
    int score;
    printf("\n<각 학생의 점수 입력>\n");
    for (int i=0;i<n;i++)       // 학생수만큼 for 반복하면서
    {
        printf("%s ",st[i].name);
        scanf("%d",&st[i].score);       // 각 학생별로 점수 입력받기
        while (st[i].score<0 || st[i].score>100)    // 입력받은 점수가 0미만 또는 100 초과인 경우 재입력받기
        {
            printf("다시입력하세요!\n");
            printf("%s ",st[i].name);
            scanf("%d",&st[i].score);
        }
        switch (st[i].score/10)     // 입력받은 점수에 따라 grade에 대입
        {
            case 10:
            case 9: st[i].grade='A';
                    break;
            case 8: st[i].grade='B';
                    break;
            case 7: st[i].grade='C';
                    break;
            case 6: st[i].grade='D';
                    break;
            default: st[i].grade='F';
        }
    }
}
void output(student* st, int n)
{
    printf("\n\t<학점>\n");
    printf("이름\t성적\t등급\n");
    for (int i=0;i<n;i++)       // 학생수만큼 for 반복하면서 결과(학생이름, 점수, grade)출력
    {
        printf("%s\t%d\t%c\n",st[i].name, st[i].score, st[i].grade);
    }
}