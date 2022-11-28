#include <stdio.h>
#include <stdlib.h>
#define persentage 30

int main()
{
    char minesweeper[10][10] = {};
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<9; j++)
        {
            if(rand()%100 < 30)
            {
                minesweeper[i][j] = '#';
                printf("%c", minesweeper[i][j]);
            }
            else
            {
                minesweeper[i][j] = '.';
                printf("%c", minesweeper[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
