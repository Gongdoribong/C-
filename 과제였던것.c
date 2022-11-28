#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 3
#define column 5

int arraySum(int array[row][column])
{
    int rowSum[3] = {};
    int columnSum[5] = {};

    /////// 합계를 배열에 저장 ///////
    for(int i = 0; i<row; i++)
    {
        for(int k = 0; k<column; k++)
        {
            rowSum[i] += array[i][k];
            columnSum[k] += array[i][k];
        }
    }

    /////////// 출력 ////////////
    for(int i = 0; i<row; i++)
    {
        printf("%d행의 합계 : %d\n", i, rowSum[i]);
    }
    for(int i = 0; i<column; i++)
    {
        printf("%d열의 합계 : %d\n", i, columnSum[i]);
    }
}

int main()
{
    int array[row][column]={0};
    srand((unsigned int)time(NULL));

    for(int i = 0; i<row; i++)
    {
        for(int k = 0; k<column; k++)
        {
            array[i][k] = rand()%100;
            printf("%d ", array[i][k]); // 배열 확인용 코드
        }
        printf("\n");
    }
    arraySum(array);
}

// 달라진 점 : 기존 코드에서 이중 for문을 두 번 돌렸던 것을 한 번 돌리도록 수정