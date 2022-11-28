#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min;
    printf("---------------------------------\n");
    printf("  1  2  3  4  5  6  7  8  9  10  \n");
    printf("---------------------------------\n");
    int price[10] = {0};
    for (int i = 0; i<10; i++)
    {
        price[i] = rand()%101;
        printf("  %d", price[i]);
    }
    printf("\n");
    min = price[0];
    for (int n = 0; n<10; n++)
    {
        if(price[n]<min)
        {
            min = price[n];
        }
    }
    printf("최솟값은 %d입니다.\n", min);


}