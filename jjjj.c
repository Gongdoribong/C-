#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10




void play_table(char hideTable[size][size], char mineTable[size][size])         //play_table�̶�� �Լ��� ���ؼ� ����ã�� ������ �����Ѵ�.
{                                                                               //�ڷ����� ����� �迭�� main�Լ��� ���� �޾ƿ�.

    for (int i = 0; i < size; i++)                                              //������ ������ ������ ?�� �迭�� �ʱ�ȭ �� ����Ѵ�.
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
        printf("�˰��� �ϴ� ��� ���� ���� �Է��ϼ���. ( ex - 3 5, �� ���� �� ���� 1�� 1��) : ");
        scanf("%d %d", &a, &b);

        if (a > size || b > size)                                                       //if ���� ���� ������ ����� �ٽ� �����Ѵ�.
        {
            printf("�ش�Ǵ� ������ �ƴմϴ�. �ٽ� �õ��ϼ���\n");
        }
        else if (mineTable[a - 1][b - 1] == '#')                                               //if ���� ���� ���ڸ� ������ ������ �����Ų��.
        {
            printf("���ڸ� �߰��߽��ϴ�. ���α׷��� ����˴ϴ�.\n");
            break;
        }
        else if (mineTable[a - 1][b - 1] == '.')                                           //if���� ���� ���ڸ� �ȹ����� ��� �����Ų��
        {
            system("cls");                                                                 //system("cls")�� ���ؼ� �� ���� �������� �͹̳� ȭ�鿡�� �����.
            for (int i = 0; i < size; i++)                                                 //����ڰ� �Է��� �κ��� ���ڰ� �ƴ� ��쿡 ���� �ǿ� .�� ���� ǥ���Ѵ�.
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
                
            prtinf("������ %d��� %d�� �ֺ��� ������ ������ %d�Դϴ�.", a, b, count);    

        }

        
        /*                                                                                   //������ ���ڰ����� �ֺ��� ���ڰ� � �ִ��� �����ؾ� ������ ������ ������ ǥ������ �ʰ� ������ ���θ��� ǥ���Ͽ���.
        if (mineTable[a - 2][b - 1] == '#' || mineTable[a - 2][b - 2] == '#' || mineTable[a - 2][b] == '#' ||
            mineTable[a - 1][b - 2] == '#' || mineTable[a - 1][b] == '#' || mineTable[a][b - 2] == '#' || mineTable[a][b - 1] == '#' ||
            mineTable[a][b] == '#')
        {   
            printf("�ֺ��� ���ڰ� �ֽ��ϴ�\n");
            
        }*/
    }
}

void make_mine(char mineTable[size][size])    //���ڸ� ����� �Լ� make_mine�� �̿��Ͽ� ���ڸ� �����Ѵ�.
{                                             //30% �̸��� ���ڸ� ������ �迭�� ����. ���ڴ� '#'�� ǥ���ϸ� ���ڰ� �ƴ� �κ��� .���� ǥ���Ѵ�.         
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

int main(void)                      //�Լ����� Ȱ���Ͽ� main�Լ��� ������ �Ͽ���.
{
    srand(time(NULL));              //srand(time(NULL))�� ���ؼ� ������ ������ �ٸ� ���� ���� �����Ͽ���.
    char hideTable[size][size];     //���ڿ� 10*10�迭 hideTable�� mineTable�� ������.
    char mineTable[size][size];
    make_mine(mineTable);           //�Լ����� �ʿ��� ���ڵ鿡 �°Բ� �迭�� �Ѱ���.
    play_table(hideTable, mineTable);
    for (int i = 0; i < size; i++)      //���� for���� ���� ����ã�� ���ӿ� �������� �����.
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3c", mineTable[i][j]);
        }
        printf("\n");
    }

    return 0;
}
