#include <stdio.h>

void get_int(int *px, int *py)
{
    scanf("%d %d", px, py);
}

int main(void)

{

	int x, y;

	get_int(&x, &y);

	printf("������ ���� %d \n", x + y);

	return 0;

}
