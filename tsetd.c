#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student list[100];
    struct student super_stu;
    struct student bad_stu;
    int i,size,j;

    for (i = 0; i < 10; i++)
    {
        printf("학생의 학번과 이름, 성적을 차례대로 입력하시오: ");
        scanf("%d %s %lf", &list[i]. number, list[i].name, &list[i].grade);
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (list[i].grade > list[j].grade)
            {
                super_stu = list[i];
                list[i] = list[j];
                list[j] = super_stu;
            }
        }
    }

    for (i=0; i<10; i++)
        printf("학번:%d 이름:%s 학점:%lf\n", list[i].number, list[i].name, list[i].grade);
}
