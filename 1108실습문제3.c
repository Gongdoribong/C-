#include <stdio.h>

int encrypt(char word[])
{
    int i = 0;
    while(word[i] != '\0')
    {
        printf("%c5",word[i]);
        i++;
    }
    return 0;
}

int main()
{
    char word[50];
    printf("���ڿ��� �Է��ϼ���: ");
    gets(word);
    encrypt(word);
}