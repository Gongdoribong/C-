#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 3
#define column 5

int arraySum(int array[row][column])
{
    int rowSum[3] = {};
    int columnSum[5] = {};

    /////// �հ踦 �迭�� ���� ///////
    for(int i = 0; i<row; i++)
    {
        for(int k = 0; k<column; k++)
        {
            rowSum[i] += array[i][k];
            columnSum[k] += array[i][k];
        }
    }

    /////////// ��� ////////////
    for(int i = 0; i<row; i++)
    {
        printf("%d���� �հ� : %d\n", i, rowSum[i]);
    }
    for(int i = 0; i<column; i++)
    {
        printf("%d���� �հ� : %d\n", i, columnSum[i]);
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
            printf("%d ", array[i][k]); // �迭 Ȯ�ο� �ڵ�
        }
        printf("\n");
    }
    arraySum(array);
}

// �޶��� �� : ���� �ڵ忡�� ���� for���� �� �� ���ȴ� ���� �� �� �������� ����