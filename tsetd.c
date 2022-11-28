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
    printf(" <- 변경 전 main 함수\n");

    test(array);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            printf("%c", array[i][j]);
        }
    }
    printf(" <- 변경 후 main 함수\n");

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
    printf("<- 변경 후 test 함수\n");
    
}