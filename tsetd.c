#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

struct student {        // student ����ü ���� (�̸�, ����, grade�� ��� ����ü)
    char name[20];
    int score;
    char grade;
};
typedef struct student student;     // struct student�� student��� �ϰڴ�
void my_name(void)
{
    printf("======================\n");
    printf("�а�: ����а�\n");
    printf("�й�: 2229022\n");
    printf("�̸�: �̽¿�\n");
    printf("======================\n");
}
void input(student*, int);      // student �����Ϳ� ������ ���޹޴� input �Լ� ������Ÿ��
void output(student*, int);     // student �����Ϳ� ������ ���޹޴� output �Լ��� ������Ÿ��
int main(void)
{
    my_name();
    
    student stu[SIZE];
    int num, i;
    printf("�л����� �Է��ϼ��� : ");
    scanf("%d",&num);       // �л��� �Է¹ޱ�
    printf("\n<�л��̸��Է�>\n");
    for (i=0;i<num;i++)     // �л�����ŭ for �ݺ��ϸ鼭
    {
        printf("�л� %d : ", i+1);
        scanf("%s",&stu[i].name);   // �̸� �Է¹ޱ�
    }
    input(stu,num);     // input�Լ� ȣ�� (�迭��� �л��� ����)
    output(stu,num);    // output �Լ� ȣ�� (�迭��� �л��� ����)

    return 0;
}
void input(student* st, int n)
{
    int score;
    printf("\n<�� �л��� ���� �Է�>\n");
    for (int i=0;i<n;i++)       // �л�����ŭ for �ݺ��ϸ鼭
    {
        printf("%s ",st[i].name);
        scanf("%d",&st[i].score);       // �� �л����� ���� �Է¹ޱ�
        while (st[i].score<0 || st[i].score>100)    // �Է¹��� ������ 0�̸� �Ǵ� 100 �ʰ��� ��� ���Է¹ޱ�
        {
            printf("�ٽ��Է��ϼ���!\n");
            printf("%s ",st[i].name);
            scanf("%d",&st[i].score);
        }
        switch (st[i].score/10)     // �Է¹��� ������ ���� grade�� ����
        {
            case 10:
            case 9: st[i].grade='A';
                    break;
            case 8: st[i].grade='B';
                    break;
            case 7: st[i].grade='C';
                    break;
            case 6: st[i].grade='D';
                    break;
            default: st[i].grade='F';
        }
    }
}
void output(student* st, int n)
{
    printf("\n\t<����>\n");
    printf("�̸�\t����\t���\n");
    for (int i=0;i<n;i++)       // �л�����ŭ for �ݺ��ϸ鼭 ���(�л��̸�, ����, grade)���
    {
        printf("%s\t%d\t%c\n",st[i].name, st[i].score, st[i].grade);
    }
}