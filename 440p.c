#include <stdio.h>

int main()
{
    int nums[] = {3,2,9,7,1,4,8,0,6,5};
    int min=nums[0], space, index;
    for (int i = 0; i<10; i++)
    {
        for (int k = i; k<10; k++)
        {
            if(nums[k]<min)
            {
                min = nums[k];
                index = k;
            }
        }
        space = nums[i];
        nums[i] = min;
        nums[index] = space;
    }
    for (int t = 0; t<10; t++)
    {
        printf("%d,", nums[t]);
    }
}