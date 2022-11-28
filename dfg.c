#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define SIZE 10

void display(int image[SIZE][SIZE]) 
{
    for (int r = 0; r < SIZE; r++) 
    {
        for (int c = 0; c < SIZE; c++) 
        {
            if (image[r][c] == 0)
                printf(".");
            else if (image[r][c] == 1)
                printf("#");
            else if (image[r][c] == 2)
                printf("G");
            else if (image[r][c] == 3)
                printf("M");
            else if (image[r][c] == 4)
                printf("M");
    }
    printf("\n");
    }
    printf("\n");
}


void randLoc(int image[SIZE][SIZE]){
    int x, y;
    for (int z=1; z<5; z++) {
        x = rand() % 10;
        y = rand() % 10;
        if (image[x][y] == 0) {
            image[x][y] = z;
        }
        else {
            z--;
            }
    }
}

void move(int image[SIZE][SIZE]){
    while (1) {
        int breakbtn = 0;
        int check = 0;
        printf("움직일 방향을 입력하시오(w,a,s,d) :\n");
        switch(_getch()){
            case 'w':
                for (int i=0; i<SIZE; i++){
                    for (int k=0; k<SIZE; k++){
                        if (image[i][k] == 1){
                            image[i-1][k] = 1;
                            image[i][k] = 0;
                            display(image);
                        }
                    }
                }
                break;
            case 'a':
                for (int i=0; i<SIZE; i++){
                    for (int k=0; k<SIZE; k++){
                        if (image[i][k] == 1){
                            image[i][k-1] = 1;
                            image[i][k] = 0;
                            display(image);
                        }
                    }
                }
                break;
            case 's':
                for (int i=0; i<SIZE; i++){
                    for (int k=0; k<SIZE; k++){
                        if (image[i][k] == 1){
                            image[i+1][k] = 1;
                            image[i][k] = 0;
                            display(image);
                            breakbtn = 1;
                            break;
                        }
                    }
                    if(breakbtn == 1)
                    {
                        break;
                    }
                }
                break;
            case 'd':
                for (int i=0; i<SIZE; i++){
                    for (int k=0; k<SIZE; k++){
                        if (image[i][k] == 1){
                            image[i][k+1] = 1;
                            image[i][k] = 0;
                            display(image);
                            breakbtn = 1;
                            break;
                        }
                    }
                    if(breakbtn == 1)
                    {
                        break;
                    }
                }
                break;
            default:
                break;
    }
        
        for (int i=0; i<SIZE; i++){
            for (int k=0; k<SIZE; k++){
                if (image[i][k] == 2)
                    check = 1;
            }
        }
        if (check == 0)
            break;   
                }
}

int main(void)
{   
    int image[SIZE][SIZE] = {0};
    srand(time(NULL));
    randLoc(image);
    display(image);
    move(image);
    printf("게임이 종료 되었습니다.\n");
    
    
    return 0;
}