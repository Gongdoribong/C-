#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

char map[10][11] = {};

void print_map() 
{
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", map[i][j]);
        printf("\n");
    }
}

int main() 
{
    char mainChara = '#', monster1 = 'M', monster2 = 'M', gold = 'G';
    int end = 0, mob1Loca, mob2Loca;
    srand((unsigned)time(NULL));

    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            map[i][j] = '.';
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
            map[location[i][0]][location[i][1]] = mainChara;

        else if(i == 1)
            map[location[i][0]][location[i][1]] = monster1;

        else if(i == 2)
            map[location[i][0]][location[i][1]] = monster2;
            
        else if(i == 3)
            map[location[i][0]][location[i][1]] = gold;
    }

    print_map();

    while (end == 0) 
    {
        printf("w, a, s, d를 눌러서 움직일 수 있습니다. \n");
        
        switch (_getch())
        {
        case 'a':
            if (location[0][1] != 0)
            {
                map[location[0][0]][location[0][1]] = '.';
                location[0][1] -= 1;
                map[location[0][0]][location[0][1]] = mainChara;
            }
            break;

        case 'd':
            if (location[0][1] != 9)
            {
                map[location[0][0]][location[0][1]] = '.';
                location[0][1] += 1;
                map[location[0][0]][location[0][1]] = mainChara;
            }
            break;

        case 'w':
            if (location[0][0] != 0)
            {
                map[location[0][0]][location[0][1]] = '.';
                location[0][0] -= 1;
                map[location[0][0]][location[0][1]] = mainChara;
            }
            break;

        case 's':
            if (location[0][0] != 9)
            {
                map[location[0][0]][location[0][1]] = '.';
                location[0][0] += 1;
                map[location[0][0]][location[0][1]] = mainChara;
            }
            break;

        default:
            printf("이동키가 아닙니다.\n");
            break;
        }

        mob1Loca = rand() % 4;
        mob2Loca = rand() % 4;

        switch (mob1Loca)
        {
            case 0:
                if (location[1][1] != 0)
                {
                    map[location[1][0]][location[1][1]] = '.';
                    location[1][1] -= 1;
                    map[location[1][0]][location[1][1]] = monster1;
                }
                break;

            case 1:
                if (location[1][1] != 9)
                {
                    map[location[1][0]][location[1][1]] = '.';
                    location[1][1] += 1;
                    map[location[1][0]][location[1][1]] = monster1;
                }
                break;

            case 2:
                if (location[1][0] != 0)
                {
                    map[location[1][0]][location[1][1]] = '.';
                    location[1][0] -= 1;
                    map[location[1][0]][location[1][1]] = monster1;
                }
                break;

            case 3:
                if (location[1][0] != 9)
                {
                    map[location[1][0]][location[1][1]] = '.';
                    location[1][0] += 1;
                    map[location[1][0]][location[1][1]] = monster1;
                }
                break;

            default:
                break;
        }

        switch (mob2Loca)
        {
            case 0:
                if (location[2][1] != 0)
                {
                    map[location[2][0]][location[2][1]] = '.';
                    location[2][1] -= 1;
                    map[location[2][0]][location[2][1]] = monster2;
                }
                break;

            case 1:
                if (location[2][1] != 9)
                {
                    map[location[2][0]][location[2][1]] = '.';
                    location[2][1] += 1;
                    map[location[2][0]][location[2][1]] = monster2;
                }
                break;

            case 2:
                if (location[2][0] != 0)
                {
                    map[location[2][0]][location[2][1]] = '.';
                    location[2][0] -= 1;
                    map[location[2][0]][location[2][1]] = monster2;
                }
                break;

            case 3:
                if (location[2][0] != 9)
                {
                    map[location[2][0]][location[2][1]] = '.';
                    location[2][0] += 1;
                    map[location[2][0]][location[2][1]] = monster2;
                }
                break;

            default:
                break;
        }

        if(location[0][0] == location[3][0] && location[0][1] == location[3][1])
        {
            end = 1;
        }
        else if(location[0][0] == location[1][0] && location[0][1] == location[1][1])
        {
            end = 1;
        }
        else if(location[0][0] == location[2][0] && location[0][1] == location[2][1])
        {
            end = 1;
        }
        
        system("cls");
        print_map();
    }
    return 0;
}