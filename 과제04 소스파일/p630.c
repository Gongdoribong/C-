#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int m[ROWS][COLS] = {};

double get_row_avg(int m[ROWS][COLS], int r)
{
    int *p, *endp;
    double sum = 0.0;

    p = &m[r][0];
    endp = &m[r][COLS-1];

    while(p<=endp)
    {
        sum += *p++;
    }

    sum /= COLS;

    return sum;
}

double get_total_avg(int m[][COLS])
{
    int *p, *endp;
    double sum = 0.0;

    p = &m[0][0];
    endp = &m[ROWS-1][COLS-1];

    while(p<=endp)
    {
        sum += *p++;
    }

    sum /= ROWS*COLS;

    return sum;
}

int main()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            m[i][j] = rand()%100;
        }
    }

    double result = 0.0;

    for(int i = 0; i<ROWS; i++)
    {
        result = get_row_avg(m, i);

        printf("%dÇàÀÇ Æò±Õ : %f\n", i, result);

    }

    result = get_total_avg(m);

    printf("ÃÑ Æò±Õ : %f", result);
}