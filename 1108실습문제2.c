#include <stdio.h>

int main()
{
    char dic[5][2][30] = {
        {"book", "책"},
        {"boy", "소년"},
        {"computer", "컴퓨터"},
        {"language", "언어"},
        {"rain", "비"}
    };

    char word[30];
    printf("단어를 입력하세요: ");
    scanf("%s", &word);

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(dic[i][0], word)==0)
        {
            printf("%s: %s", dic[i][0], dic[i][1]);
            return 0;
        }
    }
    printf("사전에서 발견되지 않았습니다.");
}