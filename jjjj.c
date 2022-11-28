#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10




void play_table(char hideTable[size][size], char mineTable[size][size])         //play_table이라는 함수를 통해서 지뢰찾기 게임을 구현한다.
{                                                                               //자료형을 명시후 배열을 main함수로 부터 받아옴.

    for (int i = 0; i < size; i++)                                              //지뢰의 정보가 숨겨진 ?로 배열을 초기화 후 출력한다.
    {
        for (int j = 0; j < size; j++)
        {
            hideTable[i][j] = '?';
            printf("%3c", hideTable[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        int a, b;
        int count =0;
        printf("알고자 하는 행과 열의 값을 입력하세요. ( ex - 3 5, 단 왼쪽 맨 위는 1행 1열) : ");
        scanf("%d %d", &a, &b);

        if (a > size || b > size)                                                       //if 문을 통해 범위를 벗어나면 다시 질문한다.
        {
            printf("해당되는 범위가 아닙니다. 다시 시도하세요\n");
        }
        else if (mineTable[a - 1][b - 1] == '#')                                               //if 문을 통해 지뢰를 밟으면 게임을 종료시킨다.
        {
            printf("지뢰를 발견했습니다. 프로그램이 종료됩니다.\n");
            break;
        }
        else if (mineTable[a - 1][b - 1] == '.')                                           //if문을 통해 지뢰를 안밟으면 계속 진행시킨다
        {
            system("cls");                                                                 //system("cls")을 통해서 그 전에 지뢰판을 터미널 화면에서 지운다.
            for (int i = 0; i < size; i++)                                                 //사용자가 입력한 부분이 지뢰가 아닐 경우에 지뢰 판에 .을 통해 표시한다.
            {
                for (int j = 0; j < size; j++)
                {
                    hideTable[i][j];
                    hideTable[a - 1][b - 1] = '.';
                    printf("%3c", hideTable[i][j]);
                }
                printf("\n");
            }
        }
        if (a == 1 && b == 1){
            if (mineTable[a][b+1] == '#')
                count +=1;
            else if (mineTable[a+1][b] == '#')
                count +=1;
            else if (mineTable[a+1][b+1] == '#')
                count +=1;
                
            prtinf("선택한 %d행과 %d열 주변에 지뢰의 개수는 %d입니다.", a, b, count);    

        }

        
        /*                                                                                   //기존에 지뢰게임은 주변에 지뢰가 몇개 있는지 구현해야 하지만 지뢰의 개수를 표현하지 않고 지뢰의 여부만을 표현하였다.
        if (mineTable[a - 2][b - 1] == '#' || mineTable[a - 2][b - 2] == '#' || mineTable[a - 2][b] == '#' ||
            mineTable[a - 1][b - 2] == '#' || mineTable[a - 1][b] == '#' || mineTable[a][b - 2] == '#' || mineTable[a][b - 1] == '#' ||
            mineTable[a][b] == '#')
        {   
            printf("주변에 지뢰가 있습니다\n");
            
        }*/
    }
}

void make_mine(char mineTable[size][size])    //지뢰를 만드는 함수 make_mine을 이용하여 지뢰를 생성한다.
{                                             //30% 미만의 지뢰를 난수로 배열의 저장. 지뢰는 '#'로 표시하며 지뢰가 아닌 부분은 .으로 표시한다.         
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (rand() % 100 < 30)
            {
                mineTable[i][j] = '#';
            }
            else
                mineTable[i][j] = '.';
        }
}

int main(void)                      //함수들을 활용하여 main함수를 간단히 하였다.
{
    srand(time(NULL));              //srand(time(NULL))을 통해서 실행할 때마다 다른 랜덤 값을 지정하였음.
    char hideTable[size][size];     //문자열 10*10배열 hideTable과 mineTable을 선언함.
    char mineTable[size][size];
    make_mine(mineTable);           //함수에서 필요한 인자들에 맞게끔 배열을 넘겨줌.
    play_table(hideTable, mineTable);
    for (int i = 0; i < size; i++)      //이중 for문을 통해 지뢰찾기 게임에 정답지를 출력함.
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3c", mineTable[i][j]);
        }
        printf("\n");
    }

    return 0;
}
