#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dice[6]={0};
    for(int i=0; i<10000; i++)
    {
        int number = rand()%6;
        dice[number]+=1;
    }
    for(int k=0; k<6; k++)
    {
        printf("%d,", dice[k]);
    }
    
}