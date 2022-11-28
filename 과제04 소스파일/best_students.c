#include <stdio.h>

struct student
{
    int number;
    char name[20];
    double grade;
};

struct student list[10] = {};

int main()
{
    for(int i = 0; i < 10; i++)
    {
        printf("학번 이름 성적을 입력하세요 (e.g. 202235327 홍길동 4.5)");
        scanf("%d %s %lf", &list[i].number, &list[i].name, &list[i].grade);
    }

    struct student temp;
    temp = list[0];

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(list[j].grade < list[j+1].grade)
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++)
        printf("%d, %s, %.2lf\n", list[i].number, list[i].name, list[i].grade);

    return 0;
}