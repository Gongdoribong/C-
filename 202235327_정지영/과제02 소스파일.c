#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 5

int arraySum(int array[ROWS][COLS]);


int main(void) {

    srand((unsigned int)time(NULL)); //rand() 함수만 쓰면 난수 값이 고정됨-> srand(time)을 통해 지속적으로 변하는 난수로 설정
    
    int array[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = rand() % 50 + 1;
        }
    }
    int result;
    result = arraySum(array);

    return 0;
}

int arraySum(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += array[i][j];
        }
        printf("%d행의 합계: %d \n", i, rowSum);
    }
    printf("\n");
    for (int  j= 0; j < COLS; j++) {
        int colSum = 0;
        for (int i = 0; i < ROWS; i++) {
            colSum += array[i][j];
        }
        printf("%d열의 합계: %d \n", j, colSum);
    }
    return 0;      
}