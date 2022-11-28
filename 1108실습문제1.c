#include <stdio.h>

int main()
{
    char s[5][20] = {};
    for(int i = 0; i<5; i++)
    {
        printf("과일 이름을 입력하세요: ");
        scanf("%s", s[i]);
    }
    for(int i = 0; i<5; i++)
    {
        printf("%d번째 과일: %s\n",i+1,s[i]);
    }
    return 0;
}