#include <stdio.h>
#include <string.h>

int main()
{
    char answer[16] = {"gwajae gae siro"};
    char blank[16];
    int i = 0, mistake = 5, checking = 0;
    char ch;

    while(answer[i] != '\0')
    {
        if(answer[i]==' ')
        {
            blank[i] = ' ';
            printf(" ");
        }
        else if(answer[i])
        {
            blank[i] = '_';
            printf("_");
        }
        i++;
    }

    printf("%d",i);

    while(mistake>0)
    {
        printf("\n���ڸ� �Է��ϼ���: ");
        scanf("%c",&ch);

        for(int t = 0; t<i; t++)
        {
            printf("%d",t);     //��������� ��� �ߵ�
            if(strcmp(answer[t],ch)==0) //���ǹ��� ��� ������ ���α׷��� ���Ḧ �ع�����...
            {
                blank[t] = ch;
                checking += 1;
                printf("k");
            }
        }
        if(checking == 0)
        {
            mistake -= 1;
            printf("���� ���� Ƚ���� %d �Դϴ�.",mistake);
            if(mistake == 0)
            {
                printf("���� ����");
                break;
            }
        }
        for(int t = 0; t<i; t++)
        {
            printf("%s",blank);
        }
    }
    return 0;
    
}