#include <stdio.h>
#include <math.h>

int main()
{
    float n, sum = 0, avg, stdDev;
    float nums[10] ={};
    for(int i = 0; i < 10; i++)
    {
        scanf("%f", &n);
        nums[i] = n;
        sum += n;
    }
    avg = sum / 10;
    sum = 0;
    for(int i = 0; i<10; i++)
    {
        sum += pow(nums[i]-avg,2);
    }
    stdDev = pow(sum/10,0.5);
    printf("평균 : %f\n표준편차 : %f", avg, stdDev);
}
