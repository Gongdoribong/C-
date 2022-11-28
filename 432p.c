#include <stdio.h>

int infoSeat(int reserv[10])
{
    printf("---------------------------------\n");
    printf("  1  2  3  4  5  6  7  8  9  10  \n");
    printf("---------------------------------\n");
    for(int i = 0; i<10; i++)
    {
        printf("  %d", reserv[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    char choice;
    printf("좌석을 예약하시겠습니까?(y 또는 n)");
    scanf("%c", &choice);
    while(choice=='y')
    {
        int seatNum = 0;
        int reserv[10] = {0};
        infoSeat(reserv);
        printf("몇 번째 좌석을 예약하시겠습니까?");
        scanf("%d", &seatNum);
        if(reserv[seatNum]==0)
        {
            reserv[seatNum-1]=1;
            printf("예약되었습니다\n.");
            infoSeat(reserv);
        }
        else
        {
            printf("이미 예약된 자리입니다.\n");
        }
        printf("좌석을 예약하시겠습니까?(y 또는 n)");
        scanf("%c", &choice);
    }
}