#include <stdio.h>

int main()
{
    char array[3][2] = {{'a', 'b'}, {'c','d'},{'e','f'}};
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            printf("%c", array[i][j]);
        }
    }
    printf(" <- ���� �� main �Լ�\n");

    test(array);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            printf("%c", array[i][j]);
        }
    }
    printf(" <- ���� �� main �Լ�\n");

}

int test(char array[3][2])
{
    array[0][0] = 'x';
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            printf("%c", array[i][j]);
        }
    }
    printf("<- ���� �� test �Լ�\n");
    
}