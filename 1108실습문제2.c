#include <stdio.h>

int main()
{
    char dic[5][2][30] = {
        {"book", "å"},
        {"boy", "�ҳ�"},
        {"computer", "��ǻ��"},
        {"language", "���"},
        {"rain", "��"}
    };

    char word[30];
    printf("�ܾ �Է��ϼ���: ");
    scanf("%s", &word);

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(dic[i][0], word)==0)
        {
            printf("%s: %s", dic[i][0], dic[i][1]);
            return 0;
        }
    }
    printf("�������� �߰ߵ��� �ʾҽ��ϴ�.");
}