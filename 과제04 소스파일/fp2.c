#include <stdio.h>

int menu()
{
    printf("=====================\n");
    printf("0. ????\n");
    printf("1. ????\n");
    printf("2. ????\n");
    printf("3. ??????\n");
    printf("4. ????\n");
    printf("=====================\n");
}

int add(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

int mul(int x, int y)
{
    return x*y;
}

int div(int x, int y)
{
    return x/y;
}


int main()
{
    int choice, result, x, y;
    int (*pf[4])(int, int) = { add, sub, mul, div };

    while(1)
    {
        menu();
        printf("?޴??? ?????Ͻÿ?:");
        scanf("%d", &choice);

        if(choice < 0 || choice >= 4)
        {
            break;
        }

        printf("2???? ?????? ?Է??Ͻÿ?:");
        scanf("%d %d", &x, &y);

        result = pf[choice](x,y);

        printf("???? ???? = %d\n", result);
    }
}