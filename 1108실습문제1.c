#include <stdio.h>

int main()
{
    char s[5][20] = {};
    for(int i = 0; i<5; i++)
    {
        printf("���� �̸��� �Է��ϼ���: ");
        scanf("%s", s[i]);
    }
    for(int i = 0; i<5; i++)
    {
        printf("%d��° ����: %s\n",i+1,s[i]);
    }
    return 0;
}