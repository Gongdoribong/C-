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
        printf("\n글자를 입력하세요: ");
        scanf("%c",&ch);

        for(int t = 0; t<i; t++)
        {
            printf("%d",t);     //여기까지는 출력 잘됨
            if(strcmp(answer[t],ch)==0) //조건문이 어떻게 터지면 프로그램이 종료를 해버리냐...
            {
                blank[t] = ch;
                checking += 1;
                printf("k");
            }
        }
        if(checking == 0)
        {
            mistake -= 1;
            printf("남은 도전 횟수는 %d 입니다.",mistake);
            if(mistake == 0)
            {
                printf("게임 종료");
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