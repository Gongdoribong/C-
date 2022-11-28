#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int printField(char field[10][11]) 
{
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", field[i][j]);
        printf("\n");
    }
}

int move(char who, char where, int i, char field[10][11], int location[4][2])
{
    switch (where)
        {
            case 'left':
                if(location[i][1] != 0)
                {
                    field[location[i][0]][location[i][1]] = '.';
                    location[i][1] -= 1;
                    field[location[i][0]][location[i][1]] = who;
                }
                break;

            case 'right':
                if(location[i][1] != 9)
                {
                    field[location[i][0]][location[i][1]] = '.';
                    location[i][1] += 1;
                    field[location[i][0]][location[i][1]] = who;
                }
                break;
            
            case 'up':
                if(location[i][0] != 0)
                {
                    field[location[i][0]][location[i][1]] = '.';
                    location[i][0] -= 1;
                    field[location[i][0]][location[i][1]] = who;
                }
                break;

            case 'down':
                if(location[i][0] != 9)
                {
                    field[location[i][0]][location[i][1]] = '.';
                    location[i][0] += 1;
                    field[location[i][0]][location[i][1]] = who;
                }
                break;
            
            default:
                printf('이동키가 아닙니다.\n');
                break;
        }
}

int main()
{
    srand((unsigned int)time(NULL));
    char mainChara = '#', monster1 = 'M', monster2 = 'M', gold = 'G';
    char field[10][11] = {};

    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            field[i][j] = '.';
        }
    }

    int location[4][2] = {};

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<2; j++)
        {
            location[i][j] = rand()%10;
        }
        if(i == 0)
        {
            field[location[i][0]][location[i][1]] = mainChara;
        }
        else if(i == 1)
        {
            field[location[i][0]][location[i][1]] = monster1;
        }
        else if(i == 2)
        {
            field[location[i][0]][location[i][1]] = monster2;
        }
        else if(i == 3)
        {
            field[location[i][0]][location[i][1]] = gold;
        }
    }

    int end = 0;
    int mob1Loca, mob2Loca;

    printField(field);

    while(end == 0)
    {
        printf("w, a, s, d를 눌러 움직일 수 있습니다.");
        
        switch (_getch())
        {
            case 'w':
                move(mainChara, 'up', 0, field, location);
                break;
            case 'a':
                move(mainChara, 'left', 0, field, location);
                break;
            case 's':
                move(mainChara, 'down', 0, field, location);
                break;
            case 'd':
                move(mainChara, 'right', 0, field, location);
                break;
            
            default:
                printf("이동키가 아닙니다.\n");
                break;
        }

        mob1Loca = rand()%4;
        mob2Loca = rand()%4;

        switch (mob1Loca)
        {
            case 0:
                printf("do");
                move(monster1, 'up', 1, field, location);
                break;
            case 1:
                printf("do");
                move(monster1, 'left', 1, field, location);
                break;
            case 2:
                printf("do");
                move(monster1, 'down', 1, field, location);
                break;
            case 3:
                move(monster1, 'right', 1, field, location);
                break;

            default:
                break;
        }

        switch (mob2Loca)
        {
            case 0:
                move(monster2, 'up', 2, field, location);
                break;
            case 1:
                move(monster2, 'left', 2, field, location);
                break;
            case 2:
                move(monster2, 'down', 2, field, location);
                break;
            case 3:
                move(monster2, 'right', 2, field, location);
                break;

            default:
                break;
        }

        if((location[0][0] == location[3][0] && location[0][1] == location[3][1])||(location[0][0] == (location[1][0] || location[2][0]) && location[0][1] == (location[1][1] || location[2][1])))
        {
            //end = 1;
        }
        printField(field);
        system('cls');
    }
}


// 1. 원래 위치 '.'으로 변환 2. 이동한 부분 변환 3. 이동한거 location에 저장
