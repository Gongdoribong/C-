#include <stdio.h>
#include <stdlib.h>

int main()
{
    char field[10][11] = {{'.','.','.','.','.','.','.','.','.','.'},
                            {'.','#','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','M','.','.','.','.'},
                            {'.','.','.','.','.','.','M','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','.'},
                            {'.','.','.','.','.','.','.','.','.','G'}};

    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
    
    int location[4][2] = {{1,1},{5,5},{6,6},{9,9}};

    char mainChara = '#', monster1 = 'M', monster2 = 'M', gold = 'G';
    int findGold = 0, mob1Loca, mob2Loca;

    while(findGold==0)
    {
        printf("w, a, s, d를 눌러 움직일 수 있습니다.\n");

        switch (_getch())
        {
            case 'a':
                if(location[0][1] != 0)
                {
                    field[location[0][0]][location[0][1]] = '.';
                    location[0][1] -= 1;
                    field[location[0][0]][location[0][1]] = mainChara;
                }
                break;

            case 'd':
                if(location[0][1] != 9)
                {
                    field[location[0][0]][location[0][1]] = '.';
                    location[0][1] += 1;
                    field[location[0][0]][location[0][1]] = mainChara;
                }
                break;
            
            case 'w':
                if(location[0][0] != 0)
                {
                    field[location[0][0]][location[0][1]] = '.';
                    location[0][0] -= 1;
                    field[location[0][0]][location[0][1]] = mainChara;
                }
                break;

            case 's':
                if(location[0][0] != 9)
                {
                    field[location[0][0]][location[0][1]] = '.';
                    location[0][0] += 1;
                    field[location[0][0]][location[0][1]] = mainChara;
                }
                break;
            
            default:
                printf('이동키가 아닙니다.\n');
                break;
        }

        srand((unsigned int)time(NULL));
        mob1Loca = rand()%4;
        mob2Loca = rand()%4;


        switch (mob1Loca)
        {
            case 0:
                if(location[1][1] != 0)
                {
                    field[location[1][0]][location[1][1]] = '.';
                    location[1][1] -= 1;
                    field[location[1][0]][location[1][1]] = monster1;
                }
                break;

            case 1:
                if(location[1][1] != 9)
                {
                    field[location[1][0]][location[1][1]] = '.';
                    location[1][1] += 1;
                    field[location[1][0]][location[1][1]] = monster1;
                }
                break;
            
            case 2:
                if(location[1][0] != 0)
                {
                    field[location[1][0]][location[1][1]] = '.';
                    location[1][0] -= 1;
                    field[location[1][0]][location[1][1]] = monster1;
                }
                break;

            case 3:
                if(location[1][0] != 9)
                {
                    field[location[1][0]][location[1][1]] = '.';
                    location[1][0] += 1;
                    field[location[1][0]][location[1][1]] = monster1;
                }
                break;
            
            default:
                break;
        }
        
        switch (mob2Loca)
        {
            case 0:
                if(location[2][1] != 0)
                {
                    field[location[2][0]][location[2][1]] = '.';
                    location[2][1] -= 1;
                    field[location[2][0]][location[2][1]] = monster2;
                }
                break;

            case 1:
                if(location[2][1] != 9)
                {
                    field[location[2][0]][location[2][1]] = '.';
                    location[2][1] += 1;
                    field[location[2][0]][location[2][1]] = monster2;
                }
                break;
            
            case 2:
                if(location[2][0] != 0)
                {
                    field[location[2][0]][location[2][1]] = '.';
                    location[2][0] -= 1;
                    field[location[2][0]][location[2][1]] = monster2;
                }
                break;

            case 3:
                if(location[2][0] != 9)
                {
                    field[location[2][0]][location[2][1]] = '.';
                    location[2][0] += 1;
                    field[location[2][0]][location[2][1]] = monster2;
                }
                break;
            
            default:
                break;
        }

        if(location[0][0] == location[3][0] && location[0][1] == location[3][1])
        {
            findGold = 1;
        }

        system("cls");
        for(int i = 0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                printf("%c", field[i][j]);
            }
            printf("\n");
        }
    }
}